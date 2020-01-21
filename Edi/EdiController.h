#ifndef EDICONTROLLER_H
#define EDICONTROLLER_H

#include <string>

class Editor;
class EdiBuffer;
class Fl_Widget;

class EdiController {
    public:
        EdiController( Editor* );
        ~EdiController();
        EdiBuffer* getCodeBuffer() const { return _pBuf; }
        void loadFile( const char* pFilename, int ipos = -1 );
        bool isLoading() { return _loading; }
        static void changed_cb( int, int nInserted, int nDeleted,int, const char*, void* p );
        void saveFile( const char* pFilename );
        /**
         * checks if there any unsaved changes.
         * If so, asks if to save and calls save_cb if necessary.
         * Return true if
         *    - no unsaved changes
         *    - successfully saved
         *    - user chooses "Don't save" option
         */
        bool checkSave();
        static void save_cb( Fl_Widget*, void* );
        static void saveas_cb(  Fl_Widget*, void* );
    private:
        std::string _filename;
        Editor* _pEdi = 0;
        EdiBuffer* _pBuf = 0;
        bool _loading = false;
        bool _changed = false;
};

#endif