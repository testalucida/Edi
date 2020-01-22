#include <Edi/Editor.h>
#include <Edi/EdiBuffer.h>
#include <Edi/includes.h>
#include <Edi/styles.h>
#include <Edi/markups.h>
#include <FL/fl_ask.H>
#include <FL/Fl_Choice.H>
#include <my/datetime.h>

Editor::Editor(int x, int y, int w, int h)
    : Fl_Text_Editor(x, y, w, h)
{
    box(FL_FLAT_BOX);
    color(FL_WHITE);
    textfont(EDI_TEXTFONT);
    textsize(EDI_TEXTSIZE);
    linenumber_width(40);
    linenumber_bgcolor(FL_GRAY);
    linenumber_fgcolor(FL_DARK3);
    linenumber_font(EDI_TEXTFONT);
    linenumber_size(EDI_TEXTSIZE);
}

void Editor::setBuffer( EdiBuffer* pBuf ) {
    _pTextbuffer = pBuf;
    buffer( pBuf );
    style_init();
    highlight_data(_pStylebuffer, styles,
                   sizeof(styles) / sizeof(styles[0]),
                   'A', style_unfinished_cb_stat, this);
    _pTextbuffer->add_modify_callback( style_update_cb_stat, this );
}

int Editor::compare_keywords(const void *a, const void *b) {
    return (strcmp(*((const char **)a), *((const char **)b)));
}

void Editor::style_init(void) {
  char *style = new char[_pTextbuffer->length() + 1];
  char *text = _pTextbuffer->text();

  memset(style, 'A', _pTextbuffer->length());
  style[_pTextbuffer->length()] = '\0';

  if (!_pStylebuffer) _pStylebuffer = 
                new Fl_Text_Buffer(_pTextbuffer->length());

  style_parse(text, style, _pTextbuffer->length());

  _pStylebuffer->text(style);
  delete[] style;
  free(text);
}

void Editor::style_unfinished_cb_stat(int, void *)
{
    //cerr << "sytle_unfinished_cb_stat" << endl;
}

void Editor::style_update_cb_stat(int pos, int nInserted, int nRestyled,
                                  int nDeleted, const char *pDeletedText, void *pCbArgs)
{
    Editor *pThis = (Editor *)pCbArgs;
    pThis->style_update(pos, nInserted, nRestyled, nDeleted, pDeletedText);
}

void Editor::style_update(int pos,
                          int nInserted, int nRestyled,
                          int nDeleted, const char *pDeletedText)
{
    int start, end;
    char last, *style, *text;
    // If this is just a selection change, just unselect the style buffer...
    if (nInserted == 0 && nDeleted == 0)
    {
        _pStylebuffer->unselect();
        return;
    }
    // Track changes in the text buffer...
    if (nInserted > 0) {
        // Insert characters into the style buffer...
        style = new char[nInserted + 1];
        memset(style, 'A', nInserted);
        style[nInserted] = 0x00;
        _pStylebuffer->replace(pos, pos + nDeleted, style);
        delete[] style;
    } else {
        // Just delete characters in the style buffer...
        _pStylebuffer->remove(pos, pos + nDeleted);
    }

    // Select the area that was just updated to avoid unnecessary
    // callbacks...
    _pStylebuffer->select(pos, pos + nInserted - nDeleted);

    // Re-parse the changed region; we do this by parsing from the
    // beginning of the line of the changed region to the end of
    // the line of the changed region... Then we check the last
    // style character and keep updating if we have a multi-line
    // comment character...
    start = _pTextbuffer->line_start(pos);
    end = _pTextbuffer->line_end(pos + nInserted - nDeleted);
    text = _pTextbuffer->text_range(start, end);
    style = _pStylebuffer->text_range(start, end);
    last = style[end - start - 1];
    style_parse(text, style, end - start);
    _pStylebuffer->replace(start, end, style);
    redisplay_range(start, end);
    if (last != style[end - start - 1]) {
        // The last character on the line changed styles, so reparse the
        // remainder of the buffer...
        free(text);
        free(style);
        end = _pTextbuffer->length();
        text = _pTextbuffer->text_range(start, end);
        style = _pStylebuffer->text_range(start, end);
        style_parse(text, style, end - start);
        _pStylebuffer->replace(start, end, style);
        redisplay_range(start, end);
    }
    free(text);
    free(style);

} //Editor::style_update

void Editor::style_parse( const char *text, char *style, int length ) {
    char current;
    int col;
    int last;
    char buf[255], *bufptr;
    const char *temp;

    // Style letters:
    //
    // A - Plain
    // B - Line comments
    // C - Block comments
    // D - Strings
    // E - Directives
    // F - Types
    // G - Keywords

  for (current = *style, col = 0, last = 0; length > 0; length --, text ++) {
    if (current == 'B' || current == 'F' || current == 'G') current = 'A';
    if (current == 'A') {
      // Check for directives, comments, strings, and keywords...
      if (col == 0 && *text == '#') {
        // Set style to directive
        current = 'E';
      } else if (strncmp(text, "//", 2) == 0) {
        current = 'B';
	for (; length > 0 && *text != '\n'; length --, text ++) *style++ = 'B';

        if (length == 0) break;
      } else if (strncmp(text, "/*", 2) == 0) {
        current = 'C';
      } else if (strncmp(text, "\\\"", 2) == 0) {
        // Quoted quote...
	*style++ = current;
	*style++ = current;
	text ++;
	length --;
	col += 2;
	continue;
      } else if (*text == '\"') {
        current = 'D';
      } else if (!last && (islower((*text)&255) || *text == '_')) {
        // Might be a keyword...
	for (temp = text, bufptr = buf;
	     (islower((*temp)&255) || *temp == '_') && bufptr < (buf + sizeof(buf) - 1);
	     *bufptr++ = *temp++) {
	  // nothing
        }

        if (!islower((*temp)&255) && *temp != '_') {
	  *bufptr = '\0';

          bufptr = buf;

	  if (bsearch(&bufptr, code_types,
	              sizeof(code_types) / sizeof(code_types[0]),
		      sizeof(code_types[0]), compare_keywords)) {
	    while (text < temp) {
	      *style++ = 'F';
	      text ++;
	      length --;
	      col ++;
	    }

	    text --;
	    length ++;
	    last = 1;
	    continue;
	  } else if (bsearch(&bufptr, code_keywords,
	                     sizeof(code_keywords) / sizeof(code_keywords[0]),
		             sizeof(code_keywords[0]), compare_keywords)) {
	    while (text < temp) {
	      *style++ = 'G';
	      text ++;
	      length --;
	      col ++;
	    }

	    text --;
	    length ++;
	    last = 1;
	    continue;
	  }
	}
      }
    } else if (current == 'C' && strncmp(text, "*/", 2) == 0) {
      // Close a C comment...
      *style++ = current;
      *style++ = current;
      text ++;
      length --;
      current = 'A';
      col += 2;
      continue;
    } else if (current == 'D') {
      // Continuing in string...
      if (strncmp(text, "\\\"", 2) == 0) {
        // Quoted end quote...
	*style++ = current;
	*style++ = current;
	text ++;
	length --;
	col += 2;
	continue;
      } else if (*text == '\"') {
        // End quote...
	*style++ = current;
	col ++;
	current = 'A';
	continue;
      }
    }

    // Copy style info...
    if (current == 'A' && (*text == '{' || *text == '}')) *style++ = 'G';
    else *style++ = current;
    col ++;

    last = isalnum((*text)&255) || *text == '_' || *text == '.';

    if (*text == '\n') {
      // Reset column and possibly reset the style
      col = 0;
      if (current == 'B' || current == 'E') current = 'A';
    }
  }
}

int Editor::handle( int evt ) {
    switch( evt ) {
      case FL_FOCUS:
      break;
      case FL_UNFOCUS:
      my::MyTimestamp ts( true );
      break;
    }
    return Fl_Text_Editor::handle( evt );
}


/*
void load_file(const char *newfile, int ipos) {
  loading = 1;
  int insert = (ipos != -1);
  changed = insert;
  if (!insert) strcpy(filename, "");
  int r;
  if (!insert) r = textbuf->loadfile(newfile);
  else r = textbuf->insertfile(newfile, ipos);
  changed = changed || textbuf->input_file_was_transcoded;
  if (r)
    fl_alert("Error reading from file \'%s\':\n%s.", newfile, strerror(errno));
  else
    if (!insert) strcpy(filename, newfile);
  loading = 0;
  textbuf->call_modify_callbacks();
}
*/

/*
void save_file(const char *newfile) {
  if (textbuf->savefile(newfile))
    fl_alert("Error writing to file \'%s\':\n%s.", newfile, strerror(errno));
  else
    strcpy(filename, newfile);
  changed = 0;
  textbuf->call_modify_callbacks();
}
*/

/*
void new_cb(Fl_Widget*, void*) {
  if (!check_save()) return;

  filename[0] = '\0';
  textbuf->select(0, textbuf->length());
  textbuf->remove_selection();
  changed = 0;
  textbuf->call_modify_callbacks();
}
*/

/*
void save_cb() {
  if ( _filename[0] == '\0' ) {
    // No filename - get one!
    saveas_cb();
    return;
  }
  else save_file( _filename );
}

void saveas_cb() {
  Fl_Native_File_Chooser fnfc;
  fnfc.title("Save File As?");
  fnfc.type(Fl_Native_File_Chooser::BROWSE_SAVE_FILE);
  if ( fnfc.show() ) return;
  save_file(fnfc.filename());
}
*/

/*
void quit_cb(Fl_Widget*, void* v) {
  Editor* pEdi = (Editor*)v;
  if( v->_changed && !check_save())
    return;

  exit(0);
}
*/