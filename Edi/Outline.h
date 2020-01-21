#ifndef OUTLINE_H
#define OUTLINE_H

#include <Edi/ExplorerGroup.h>
#include <Edi/Tree.h>

class Outline : public ExplorerGroup  {
    public:
        Outline( int x, int y, int w, int h, const char* pLbl = NULL );
        ~Outline() {}
    private:
        Fl_Group* _pTopGrp; //contains some display options
        Tree* _pTree; //contains outline infos like method or
                    //function names, filenames contained
                    //in the project opened etc.
};

#endif