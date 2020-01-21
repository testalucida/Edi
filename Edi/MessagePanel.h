#ifndef MESSAGEPANEL_H
#define MESSAGEPANEL_H

#include <FL/Fl_Tile.H>

class MessagePanel : public Fl_Tile {
public:
    MessagePanel( int x, int y, int w, int h );
    ~MessagePanel() {}
};

#endif