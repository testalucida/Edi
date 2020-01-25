#ifndef PROJECTEVENTCONTROLLER_H
#define PROJECTEVENTCONTROLLER_H

class Fl_Widget;

/**
 * ProjectEventController provides all callbacks to use 
 * from Project menu in MenuBar.
 */
class ProjectEventController {
public:
    ~ProjectEventController() {}

    static void onNewProject( Fl_Widget*, void* );
    static void onOpenProject( Fl_Widget*, void* );
    static void onCloseProject( Fl_Widget*, void* );
    static void onNewFile( Fl_Widget*, void* );
    static void onOpenFile( Fl_Widget*, void* );
    static void onSaveFile( Fl_Widget*, void* );
    static void onSaveFileAs( Fl_Widget*, void* );
    static void onNewClass( Fl_Widget*, void* );
    static void onExit( Fl_Widget*, void* );

private:
    ProjectEventController() {}
};

#endif