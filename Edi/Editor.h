#ifndef EDITOR_H
#define EDITOR_H

#include <FL/Fl_Text_Editor.H>
#include <FL/filename.H>

class EdiBuffer;

static char _filename[FL_PATH_MAX] = "";

class Editor : public Fl_Text_Editor {
    public:
        Editor( int x, int y, int w, int h );
        ~Editor() {}
		void setBuffer( EdiBuffer* );
        static void changed_cb( int, int nInserted, int nDeleted,
                                int, const char*, void* v );
        void style_init();
        static void style_unfinished_cb_stat( int, void* );
        static void style_update_cb_stat( int pos, 
                                  int nInserted, int nRestyled,
                                  int nDeleted, const char* pDeletedText,
                                  void* pCbArgs );
        void style_update( int pos, 
                                  int nInserted, int nRestyled,
                                  int nDeleted, const char* pDeletedText );
        void style_parse( const char *pText, char* pStyle, int length );
        static int compare_keywords( const void *a, const void *b );
        int check_save();
        
        int handle( int );
        
    private:
        EdiBuffer* _pTextbuffer = NULL;
        Fl_Text_Buffer* _pStylebuffer = NULL;

};

#endif