#ifndef EDIROWHEADER_H
#define EDIROWHEADER_H

#include <FL/Fl_Text_Display.H>

class EdiRowHeader : public Fl_Text_Display {
    public:
        EdiRowHeader( int x, int y, int w, int h ) ;
    protected:
        void draw();
        
};

#endif