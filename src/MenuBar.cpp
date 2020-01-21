#include <Edi/MenuBar.h>

MenuBar::MenuBar( int x, int y, int w, int h ) 
: Fl_Menu_Bar( x, y, w, h )
{
    box(FL_FLAT_BOX);
    color((Fl_Color)37);
    
}