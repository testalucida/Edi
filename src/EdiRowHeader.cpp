#include <Edi/EdiRowHeader.h>
#include <Edi/settings.h>

EdiRowHeader::EdiRowHeader( int x, int y, int w, int h )
: Fl_Text_Display( x, y, w, h )
{
    box( FL_FLAT_BOX );
    color( fl_lighter( FL_GRAY ) );
    textfont( EDI_TEXTFONT );
    textsize( EDI_TEXTSIZE );
}

void EdiRowHeader::draw() {
    Fl_Text_Display::draw();
}