#ifndef EDITAB_H
#define EDITAB_H

#include <FL/Fl_Tabs.H>

class EdiTabTile;

/**
 * Two EdiTab objects are contained in EdiTile.
 * Each of them contain 0...n EdiTabTile objects
 */
class EdiTabs : public Fl_Tabs {
public:
    EdiTabs( int x, int y, int w, int h, const char* pLbl=NULL );
    ~EdiTabs() {}
    /**
     * Gets the top or bottom Editor.
     * The return value can never be NULL.
     */ 
    EdiTabTile* getVisibleTab();

private:
   
};

#endif