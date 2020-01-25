#include <Edi/ProjectEventController.h>
#include <Edi/constants.h>
#include <Edi/EdiTabs.h>
#include <Edi/EdiTabTile.h>
#include <Edi/GuiHelper.h>
#include <Edi/EdiBuffer.h>
#include <Edi/EdiController.h>

#include <FL/Fl_Native_File_Chooser.H>
#include <FL/Fl_Menu_Bar.H>

#include <typeinfo>

void ProjectEventController::onNewProject( Fl_Widget*, void* ) {

}

void ProjectEventController::onOpenProject( Fl_Widget*, void* ) {

}

void ProjectEventController::onCloseProject( Fl_Widget*, void* ) {

}

void ProjectEventController::onNewFile( Fl_Widget*, void* ) {

}

void ProjectEventController::onOpenFile( Fl_Widget* p, void* )  {
    //ask for file to open:
    Fl_Native_File_Chooser fnfc;
    fnfc.title( "Open file" );
    fnfc.type( Fl_Native_File_Chooser::BROWSE_FILE );
    if ( fnfc.show() ) return;

    //get last focused EdiTabs and add a new EdiTabTile
    EdiTabs* pTabs = GuiHelper::inst().getLastFocusedEdiTabs( p );
    EdiTabTile* pTabTile = pTabs->addEdiTabTile( fnfc.filename() );
    
    //create an EdiController and let it do the work
    EdiController* pEc = new EdiController( pTabTile, fnfc.filename() );
}

void ProjectEventController::onSaveFile( Fl_Widget*, void* ) {

} 

void ProjectEventController::onSaveFileAs( Fl_Widget*, void* ) {

} 

void ProjectEventController::onNewClass( Fl_Widget*, void* )  {

}

void ProjectEventController::onExit( Fl_Widget*, void* ) {

} 