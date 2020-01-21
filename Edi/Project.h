#ifndef PROJECT_H
#define PROJECT_H

#include <Edi/ExplorerGroup.h>

class Tree;

class Project : public ExplorerGroup {
public:
    Project( int x, int y, int w, int h, const char* pLbl = NULL );
    ~Project() {}
private:
    Tree* _pTree;
};

#endif