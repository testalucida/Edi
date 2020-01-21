#ifndef EDITABTILE_H
#define EDITABTILE_H

#include <FL/Fl_Tile.H>

class EdiGrp;

enum whichGrp {
    TOP = 0,
    BOTTOM = 1
} ;

/**
 * Each EdiTabTile contains 2 EdiGrp objects
 * for splitting text vertical feature.
 */
class EdiTabTile : public Fl_Tile {
public:
    EdiTabTile( int x, int y, int w, int h );
    ~EdiTabTile() {}
    EdiGrp* getEdiGrp( whichGrp grp ) const;
private:
    EdiGrp* _pEdiGrpTop;
    EdiGrp* _pEdiGrpBottom;
};

#endif