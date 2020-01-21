#ifndef EXPLORERGROUP_H
#define EXPLORERGROUP_H

#include <FL/Fl_Group.H>

class Fl_Group;

/**
 * Group to be displayed in an Explorer.
 * We have two of them: Outline and Project.
 * What they have in common is a title bar ('header') and 
 * an area containing specific widgets ('content').
 */
class ExplorerGroup : public Fl_Group {
public:
    ExplorerGroup( int x, int y, int w, int h, const char* pLbl );
    ~ExplorerGroup() {}
    void setHeader( Fl_Widget* );
    Fl_Widget* getHeader() const;
    void setContent( Fl_Widget* );
    Fl_Widget* getContent() const;
private:
    Fl_Group* _pHeader;
    Fl_Group* _pContent;
};

#endif