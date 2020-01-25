#include <Edi/MenuBar.h>
#include <Edi/ProjectEventController.h>
#include <FL/Fl_Menu_Item.H>
#include <Edi/constants.h>

#define DEFAULTFONT (0, 14, 51)

Fl_Menu_Item menuitems[] = {
  { "&Project",           NOSHORTCUT, NOCALLBACK, NOUSERDATA, FL_SUBMENU, 
        DEFAULTLABELTYPE, DEFAULTLABELFONT, DEFAULTLABELSIZE, DEFAULTLABELCOLOR },

    { "New Project...",   NOSHORTCUT, ProjectEventController::onNewProject, NOUSERDATA, NOFLAGS, 
        DEFAULTLABELTYPE, DEFAULTLABELFONT, DEFAULTLABELSIZE, DEFAULTLABELCOLOR },

    { "Open Project...",  NOSHORTCUT, ProjectEventController::onOpenProject, NOUSERDATA, NOFLAGS, 
        DEFAULTLABELTYPE, DEFAULTLABELFONT, DEFAULTLABELSIZE, DEFAULTLABELCOLOR },

    { "Close Project",    NOSHORTCUT, ProjectEventController::onCloseProject, NOUSERDATA, FL_MENU_DIVIDER,
        DEFAULTLABELTYPE, DEFAULTLABELFONT, DEFAULTLABELSIZE, DEFAULTLABELCOLOR },

    { "&New File...",        NOSHORTCUT, ProjectEventController::onNewFile, NOUSERDATA, NOFLAGS,
        DEFAULTLABELTYPE, DEFAULTLABELFONT, DEFAULTLABELSIZE, DEFAULTLABELCOLOR },

    { "&Open File...",    FL_COMMAND + 'o', ProjectEventController::onOpenFile, NOUSERDATA, NOFLAGS, 
        DEFAULTLABELTYPE, DEFAULTLABELFONT, DEFAULTLABELSIZE, DEFAULTLABELCOLOR },

    { "&Save File",       FL_COMMAND + 's', ProjectEventController::onSaveFile, NOUSERDATA, NOFLAGS, 
        DEFAULTLABELTYPE, DEFAULTLABELFONT, DEFAULTLABELSIZE, DEFAULTLABELCOLOR },

    { "Save File &As...", FL_COMMAND + FL_SHIFT + 's', ProjectEventController::onSaveFileAs, NOUSERDATA, FL_MENU_DIVIDER,
        DEFAULTLABELTYPE, DEFAULTLABELFONT, DEFAULTLABELSIZE, DEFAULTLABELCOLOR },

    { "E&xit",            FL_COMMAND + 'q', ProjectEventController::onExit, NOUSERDATA, NOFLAGS,
        DEFAULTLABELTYPE, DEFAULTLABELFONT, DEFAULTLABELSIZE, DEFAULTLABELCOLOR },

    { 0 },
/*
  { "&Edit", 0, 0, 0, FL_SUBMENU },
    { "Cu&t",             FL_COMMAND + 'x', (Fl_Callback *)cut_cb },
    { "&Copy",            FL_COMMAND + 'c', (Fl_Callback *)copy_cb },
    { "&Paste",           FL_COMMAND + 'v', (Fl_Callback *)paste_cb },
    { "&Delete",          0, (Fl_Callback *)delete_cb },
    { "Preferences",      0, 0, 0, FL_SUBMENU },
      { "Line Numbers",   FL_COMMAND + 'l', (Fl_Callback *)linenumbers_cb, 0, FL_MENU_TOGGLE },
      { "Word Wrap",      0,                (Fl_Callback *)wordwrap_cb, 0, FL_MENU_TOGGLE },
      { 0 },
    { 0 },

  { "&Search", 0, 0, 0, FL_SUBMENU },
    { "&Find...",         FL_COMMAND + 'f', (Fl_Callback *)find_cb },
    { "F&ind Again",      FL_COMMAND + 'g', find2_cb },
    { "&Replace...",      FL_COMMAND + 'r', replace_cb },
    { "Re&place Again",   FL_COMMAND + 't', replace2_cb },
    { 0 },
*/
  { 0 }
};

MenuBar::MenuBar( int x, int y, int w, int h ) 
: Fl_Menu_Bar( x, y, w, h )
{
    box(FL_FLAT_BOX);
    color((Fl_Color)37);
    copy( menuitems );
    
}