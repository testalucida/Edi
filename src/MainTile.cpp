#include <Edi/MainTile.h>
#include <Edi/Explorer.h>
#include <Edi/EdiTabs.h>
#include <Edi/MessagePanel.h>
#include <Edi/constants.h>

/**
 * due to a bug in the interaction between
 * Fl_Tabs and Fl_Tile we have to set the app window
 * to 'damaged' in order to avoid smearings alongside the tab.
 */
void workaround_cb( Fl_Widget* p, void * ) {
    p->parent()->damage( FL_DAMAGE_ALL );
}

MainTile::MainTile( int x, int y, int w, int h )
: Fl_Tile( x, y, w, h )
{
    box(FL_FLAT_BOX);
    color( MAINTILECOLOR );

    int H = h - MESSAGEPANELHEIGHT;
    //Explorer to the left:
    _pExplorer = new Explorer( 0, y, EXPLORERWIDTH, H );

    //2 EdiTab objects right of explorer
    int x1 = _pExplorer->x() + _pExplorer->w();
    int w1 = (w-_pExplorer->w()) / 2;
    _pEdiTabsLeft = new EdiTabs( x1, y, w1, H );
    _pEdiTabsLeft->addEdiTabTile( "new on left tab" );
    _pEdiTabsLeft->addEdiTabTile( "another new one" );

    int x2 = _pEdiTabsLeft->x() + _pEdiTabsLeft->w();
    int w2 = w - _pExplorer->w() - w1;
    _pEdiTabsRight = new EdiTabs( x2, y, w2, H );
    _pEdiTabsRight->addEdiTabTile( "new on right tab" );

    callback( workaround_cb );


    //MessagePanel to the bottom

    end();
    
}

EdiTabs* MainTile::getLastFocusedEdiTabs() {
    //TODO
    
    //temp:
    return _pEdiTabsLeft;
}
