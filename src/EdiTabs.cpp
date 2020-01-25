#include <Edi/EdiTabs.h>
#include <Edi/Editor.h>
#include <Edi/EdiGrp.h>
#include <Edi/EdiTabTile.h>
#include <Edi/constants.h>
#include <FL/Fl_Box.H>

void onTabSelection( Fl_Widget* p, void* ) {
    EdiTabs* pTabs = (EdiTabs*)p;
    pTabs->selection_color( TABSELECTIONCOLOR );
    fprintf( stderr, "onTabSelection" );
}

EdiTabs::EdiTabs( int x, int y, int w, int h, const char* pLbl ) 
: Fl_Tabs( x, y, w, h, pLbl ) 
{
    box( FL_FLAT_BOX );
    end();
    callback( onTabSelection );
}

EdiTabTile* EdiTabs::getVisibleTab() {
    //first get EdiTabTile of the opened (visible) tab:
    EdiTabTile* pTabTile = ((EdiTabTile*) value());
    return pTabTile;
}

void EdiTabs::addEdiTabTile( EdiTabTile* pTab ) {
    add( pTab );
    if( this->children() == 1 ) {
        resizable( pTab );
    }
}

EdiTabTile* EdiTabs::addEdiTabTile( const char* pLbl ) {
    int X, Y, W, H;
    client_area( X, Y, W, H );
    EdiTabTile* pTab = new EdiTabTile( X, Y, W, H, pLbl );
    addEdiTabTile( pTab );
    return pTab;
}

