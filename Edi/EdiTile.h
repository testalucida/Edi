#ifndef EDITILE_H
#define EDITILE_H

#include <FL/Fl_Tile.H>
#include <Edi/constants.h>

class Explorer;
class EdiTabs;
class Editor;
class MessagePanel;

/**
 * Main Tile of Edi.
 * Contanis 1 Explorer object, 1 MessagePanel object
 * and 2 EdiTabs objects
 */
class EdiTile : public Fl_Tile {
    public:
        EdiTile( int x, int y, int w, int h );
        ~EdiTile() {}
        Editor* getEditor( int which ) const;
    private:
        Explorer* _pExplorer;
        EdiTabs* _pEdiTabsLeft;
        EdiTabs* _pEdiTabsRight;
        MessagePanel* _pMsgPanel;

};

#endif