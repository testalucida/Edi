#ifndef EDITAB_H
#define EDITAB_H

#include <FL/Fl_Tabs.H>

/**
 * Two EdiTab objects are contained in EdiTile.
 * Each of them contain 0...n EdiTabTile objects
 */
class EdiTabs : public Fl_Tabs {
public:
    EdiTabs( int x, int y, int w, int h, const char* pLbl=NULL );
    ~EdiTabs() {}
private:
   
};

#endif