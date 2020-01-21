#ifndef EDITILE_H
#define EDITILE_H

#include <FL/Fl_Tile.H>
#include <Edi/constants.h>

class Explorer;
class EdiGrp;
class Editor;

class EdiTile : public Fl_Tile {
    public:
        EdiTile( int x, int y, int w, int h );
        ~EdiTile() {}
        Editor* getEditor( int which ) const;
    private:
        Explorer* _pExplorer;
        EdiGrp* _pEdiGrp1;
        EdiGrp* _pEdiGrp2;
};

#endif