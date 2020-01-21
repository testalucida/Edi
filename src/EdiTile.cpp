#include <Edi/EdiTile.h>
#include <Edi/Explorer.h>
#include <Edi/EdiGrp.h>
#include <Edi/constants.h>

EdiTile::EdiTile( int x, int y, int w, int h )
: Fl_Tile( x, y, w, h )
{
    box(FL_FLAT_BOX);
    color((Fl_Color)73);
    selection_color(FL_BACKGROUND_COLOR);
    labeltype(FL_NORMAL_LABEL);
    labelfont(0);
    labelsize(14);
    labelcolor(FL_FOREGROUND_COLOR);
    align(Fl_Align(FL_ALIGN_TOP));
    when(FL_WHEN_RELEASE);

    int H = h - MESSAGEPANELHEIGHT;
    //Explorer to the left:
    _pExplorer = new Explorer( 0, y, EXPLORERWIDTH, H );

    //2 Editorgroups to the right
    int x1 = _pExplorer->x() + _pExplorer->w();
    int w1 = (w-_pExplorer->w()) / 2;
    _pEdiGrp1 = new EdiGrp( x1, y, w1, H );
    int x2 = _pEdiGrp1->x() + _pEdiGrp1->w();
    int w2 = w - _pExplorer->w() - w1;
    _pEdiGrp2 = new EdiGrp( x2, y, w2, H );

    //MessagePanel to the bottom

    end();
    
}

Editor* EdiTile::getEditor( int which ) const {
    return (which == 1 ) ? _pEdiGrp1->getEditor() :
                           _pEdiGrp2->getEditor();
}