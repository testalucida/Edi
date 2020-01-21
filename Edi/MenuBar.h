#ifndef MENUBAR_H
#define MENUBAR_H

#include <FL/Fl_Menu_Bar.H>
#include <Edi/constants.h>

class MenuBar : public Fl_Menu_Bar {
public:
    MenuBar( int x, int y, int w, int h = MENUBARHEIGHT );
    ~MenuBar() {}
};

#endif