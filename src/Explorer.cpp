#include <Edi/Explorer.h>

Explorer::Explorer( int x, int y, int w, int h, const char* pLbl ) 
: Fl_Tile( x, y, w, h, pLbl )
{
    box(FL_FLAT_BOX);
    color(FL_LIGHT2);
    selection_color(FL_BACKGROUND_COLOR);


    end();
}