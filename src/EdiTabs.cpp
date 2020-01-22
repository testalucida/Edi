#include <Edi/EdiTabs.h>
#include <Edi/Editor.h>
#include <Edi/EdiGrp.h>
#include <Edi/EdiTabTile.h>

EdiTabs::EdiTabs( int x, int y, int w, int h, const char* pLbl ) 
: Fl_Tabs( x, y, w, h, pLbl ) 
{
    this->active();
}

EdiTabTile* EdiTabs::getVisibleTab() {
    //first get EdiTabTile of the opened (visible) tab:
    EdiTabTile* pTabTile = ((EdiTabTile*) value());
    return pTabTile;
}

