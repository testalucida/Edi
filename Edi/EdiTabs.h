#ifndef EDITAB_H
#define EDITAB_H

#include <FL/Fl_Tabs.H>

class EdiGrp;

class EdiTabs : public Fl_Tabs {
public:
    EdiTabs( int x, int y, int w, int h, const char* pLbl=NULL );
    ~EdiTabs() {}
private:
   
};

#endif