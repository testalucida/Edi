#ifndef TREE_H
#define TREE_H

#include <FL/Fl_Tree.H>

class Tree : public Fl_Tree {
    public:
        Tree( int x, int y, int w, int h, const char* pLbl = NULL );
        ~Tree() {}

    private:
};
       
#endif