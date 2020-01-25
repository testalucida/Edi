#ifndef MAINTILE_H
#define MAINTILE_H

#include <FL/Fl_Tile.H>
#include <Edi/constants.h>
#include <Edi/enums.h>


class Explorer;
class EdiTabs;
class Editor;
class MessagePanel;

/**
 * Main Tile of Edi.
 * Contanis 1 Explorer object, 1 MessagePanel object
 * and 2 EdiTabs objects
 */
class MainTile : public Fl_Tile {
    public:
        MainTile( int x, int y, int w, int h );
        ~MainTile() {}
        EdiTabs* getLastFocusedEdiTabs();
    private:
        Explorer* _pExplorer;
        EdiTabs* _pEdiTabsLeft;
        EdiTabs* _pEdiTabsRight;
        MessagePanel* _pMsgPanel;

};

#endif