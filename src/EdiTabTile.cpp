#include <Edi/EdiTabTile.h>
#include <Edi/EdiGrp.h>

EdiTabTile::EdiTabTile( int x, int y, int w, int h )
: Fl_Tile( x, y, w, h )
{
    int h1 = h/2;
    int h2 = h - h1;
    _pEdiGrpTop = new EdiGrp( x, y, w, h1 );
    _pEdiGrpBottom = new EdiGrp( x, y + h1, w, h2 );
    end();
}

EdiGrp* EdiTabTile::getEdiGrp( whichGrp grp ) const { 
    return (grp == TOP) ?_pEdiGrpTop : _pEdiGrpBottom; 
}