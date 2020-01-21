#ifndef EXPLORER_H
#define EXPLORER_H

#include <FL/Fl_Tile.H>

class Outline;
class Project;

////////////////////////////////////////

class Explorer : public Fl_Tile {
public:
    Explorer( int x, int y, int w, int h, const char* pLbl = NULL );
    ~Explorer() {}
private:
    Outline* _pOutline;
    Project* _pProject;
};

#endif