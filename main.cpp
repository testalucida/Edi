
/* 
 * File:   main.cpp
 * Author: martin
 *
 * Created on 9. Januar 2020, 11:59
 */

//#include "mainwindow.h"
#include <Edi/MainWindow.h>
#include <Edi/MenuBar.h>
#include <Edi/EdiGrp.h>
#include <Edi/includes.h>
#include <Edi/MainTile.h>
#include <Edi/EdiController.h>
#include <Edi/OutlineManager.h>
#include <Edi/Tree.h>
#include <Edi/constants.h>

#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Text_Editor.H>
#include <FL/fl_ask.H>

#include <cstdlib>

using namespace std;


void win_cb( Fl_Widget* pWin, void* ) {
  int result = fl_choice("Do you want to save before quitting?", 
                           "Don't Save",  // 0
                           "Save",        // 1
                           "Cancel"       // 2
                           );
    if (result == 0) {  // Close without saving
        pWin->hide();
    } else if (result == 1) {  // Save and close
        cerr << "do your save thing now" << endl;
        pWin->hide();
    } else if (result == 2) {  // Cancel / don't close
        // don't do anything
    }
    cerr << "main window callback" << endl;
    pWin->hide(); //when all windows are hidden, the app ends
}

/***********************************************************/
int main( int argc, char** argv ) {

  MainWindow* pWin = new MainWindow( 100, 100, 900, 700 );

  //MenuBar* pMenuBar = new MenuBar( 0, 0, 900 );

//   MainTile* pMainTile = new MainTile( 0, pMenuBar->h(), pWin->w(), 
//                                     pWin->h() - pMenuBar->h() );

//   pWin->end();
//   pWin->resizable( pMainTile );

/*
  EdiController ctrl1( pMainTile->getEditor( 1 ) );
  EdiController ctrl2( pMainTile ->getEditor( 2 ) );
  ctrl1.loadFile( "/home/martin/kannweg.cpp" );
  */
  
  pWin->show();
  return Fl::run();
}
/***********************************************************/

/**
int main(int argc, char** argv) {
    Fl_Double_Window* pWin = make_mainwindow();    
    pWin->callback( win_cb );
    EdiController ctrl( g_pEdiGrp->getEditor() );
    ctrl.loadFile( "/home/martin/kannweg.cpp" );
    OutlineManager mgr( NULL );
    mgr.setCodeBuffer( ctrl.getCodeBuffer() );
    pWin->show( argc,argv );
   
    return Fl::run();
}
*/