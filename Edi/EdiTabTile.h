#ifndef EDITABTILE_H
#define EDITABTILE_H

#include <FL/Fl_Tile.H>
#include <Edi/enums.h>

class EdiGrp;
class EdiBuffer;
class Editor;

/**
 * EdiTabTile is the content of each Tab in EdiTabs.
 * Each EdiTabTile contains 2 EdiGrp objects
 * for splitting text vertical feature.
 */
class EdiTabTile : public Fl_Tile {
public:
    EdiTabTile( int x, int y, int w, int h, const char* pLbl = NULL );
    ~EdiTabTile() {}
    /**
     * Get top or bottom EdiGrp
     */
    EdiGrp* getEdiGrp( whichGrp grp ) const;
    EdiGrp* getLastFocusedEdiGrp() const;
    void setBuffer( EdiBuffer* );
    Editor* getEditor( whichGrp grp = TOP );
private:
    EdiGrp* _pEdiGrpTop;
    EdiGrp* _pEdiGrpBottom;
};

#endif