#include <Edi/EdiGrp.h>
#include <Edi/Editor.h>
#include <Edi/EdiRowHeader.h>
#include <Edi/constants.h>

EdiGrp::EdiGrp( int x, int y, int w, int h ) 
: Fl_Group( x, y, w, h )
{
    box( FL_FLAT_BOX );
    _pRowHeader = new EdiRowHeader( x, y, EDIROWHEADERWIDTH, h );
    _pEdi = new Editor( x + EDIROWHEADERWIDTH, y, w - EDIROWHEADERWIDTH, h );
    resizable( _pEdi );
    end();
}