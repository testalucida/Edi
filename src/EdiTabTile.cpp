#include <Edi/EdiTabTile.h>
#include <Edi/EdiGrp.h>
#include <Edi/EdiBuffer.h>
#include <Edi/Editor.h>

EdiTabTile::EdiTabTile( int x, int y, int w, int h, const char* pLbl )
: Fl_Tile( x, y, w, h, pLbl )
{
    box( FL_FLAT_BOX );
    int h1 = h/2;
    int h2 = h - h1;
    _pEdiGrpTop = new EdiGrp( x, y, w, h1 );
    _pEdiGrpBottom = new EdiGrp( x, y + h1, w, h2 );
    end();
}

EdiGrp* EdiTabTile::getEdiGrp( whichGrp grp ) const { 
    return (grp == TOP) ?_pEdiGrpTop : _pEdiGrpBottom; 
}

EdiGrp* EdiTabTile::getLastFocusedEdiGrp() const {

}

void EdiTabTile::setBuffer( EdiBuffer* pBuf ) {
    _pEdiGrpTop->getEditor()->buffer( pBuf );
}