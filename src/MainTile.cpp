#include <Edi/MainTile.h>
#include <Edi/Explorer.h>
#include <Edi/EdiTabs.h>
#include <Edi/MessagePanel.h>
#include <Edi/constants.h>

MainTile::MainTile( int x, int y, int w, int h )
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

    //2 EdiTab objects right of explorer
    int x1 = _pExplorer->x() + _pExplorer->w();
    int w1 = (w-_pExplorer->w()) / 2;
    _pEdiTabsLeft = new EdiTabs( x1, y, w1, H );
    int x2 = _pEdiTabsLeft->x() + _pEdiTabsLeft->w();
    int w2 = w - _pExplorer->w() - w1;
    _pEdiTabsRight = new EdiTabs( x2, y, w2, H );

    //MessagePanel to the bottom

    end();
    
}