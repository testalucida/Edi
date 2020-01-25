#include <Edi/EdiController.h>
#include <Edi/EdiBuffer.h>
#include <Edi/Editor.h>
#include <Edi/EdiTabTile.h>
#include <Edi/EdiTabs.h>
#include <FL/fl_ask.H>
#include <FL/Fl_Native_File_Chooser.H>


EdiController::EdiController( EdiTabTile* tabtile, const char* pFilename ) 
: _pTabTile( tabtile )
{
    if( pFilename ) {
         _filename = pFilename;
    }
}

/**
 * checks if there are any unsaved changes.
 * If so, asks if to save and calls save_cb if necessary.
 * Return true if
 *    - no unsaved changes
 *    - successfully saved
 *    - user chooses "Don't save" option
 */
bool EdiController::checkSave() {
    if( !_changed ) return true;

    int rc = fl_choice("The current file has not been saved.\n"
                        "Would you like to save it now?",
                        "Cancel", "Save", "Don't Save");

    if (rc == 1) {
        //save_cb(); // Save the file...
        return !_changed; //we mustn't return true because 
        //_changed is set in save_cb and there might have 
        // occured an error on saving.
    }

    return rc == 2 ? true : false;
}

void EdiController::loadFile() {
    //create buffer:
    _pBuf = new EdiBuffer();
    _pBuf->add_modify_callback( changed_cb, this );
    //make buffer load file:
    _loading = true;
    int rc = _pBuf->loadfile( _filename.c_str() );
    _changed = ( _changed || _pBuf->input_file_was_transcoded );
    if( rc ) {
        fl_alert( "Error reading from file \'%s\':\n%s.", 
                  _filename.c_str(), strerror(errno) );
        return;
    } 
    
    _pEdi = _pTabTile->getEditor();
    _pEdi->setBuffer( _pBuf );
    _loading = false;
    _pBuf->call_modify_callbacks();
}

void EdiController::changed_cb(int, int nInserted, int nDeleted,int, const char*, void* p) {
  EdiController* pEdiC = (EdiController*)p;
  if( (nInserted || nDeleted) && !pEdiC->_loading ) pEdiC->_changed = 1;
  if( pEdiC->_loading ) pEdiC->_pEdi->show_insert_position();
}

void EdiController::saveFile( const char* pFilename ) {
    if( _pBuf->savefile( pFilename ) ) {
        fl_alert( "Error writing to file \'%s\':\n%s.", 
                  pFilename, strerror(errno) );
    } else {
        _filename = pFilename;
    }
  _changed = false;
  _pBuf->call_modify_callbacks();
}

void EdiController::save_cb( Fl_Widget*, void* p ) {
    EdiController* pC = (EdiController*)p;
    if ( pC->_filename.empty() ) {
        // No filename - get one!
        pC->saveas_cb( NULL, p );
        return;
    }
    else pC->saveFile( pC->_filename.c_str() );
}

void EdiController::saveas_cb(  Fl_Widget*, void* p ) {
    EdiController* pC = (EdiController*)p;
    Fl_Native_File_Chooser fnfc;
    fnfc.title("Save File As?");
    fnfc.type(Fl_Native_File_Chooser::BROWSE_SAVE_FILE);
    if ( fnfc.show() ) return;
    pC->saveFile( fnfc.filename() );
}

EdiController::~EdiController() {

}