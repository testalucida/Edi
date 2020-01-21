#ifndef EDIGRP_H
#define EDIGRP_H

#include <FL/Fl_Group.H>

class Editor;
class EdiRowHeader;

class EdiGrp : public Fl_Group {
    public:
        EdiGrp( int x, int y, int w, int h );
        ~EdiGrp() {}
        Editor* getEditor() const { return _pEdi; };
    private:
        Editor* _pEdi = NULL;
        EdiRowHeader* _pRowHeader = NULL;
};

#endif