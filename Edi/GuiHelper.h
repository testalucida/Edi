#ifndef GUIHELPER_H
#define GUIHELPER_H

#include <algorithm>

class EdiTabs;
class Fl_Widget;

class GuiHelper {
public:
    static GuiHelper& inst() {
        if( !_pInstance ) {
            _pInstance = new GuiHelper();
            atexit( destroy );
        }
        return *_pInstance;
    }
    EdiTabs* getLastFocusedEdiTabs( Fl_Widget* );
private:
    GuiHelper() {}
    static void destroy();
private:
    static GuiHelper* _pInstance;
};

#endif