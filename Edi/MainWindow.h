#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <FL/Fl_Double_Window.H>

#include <Edi/MenuBar.h>
#include <Edi/MainTile.h>

class MainWindow : public Fl_Double_Window {
    public:
        MainWindow( int x, int y, int w, int h ); 
        MenuBar* getMenuBar();
        MainTile* getMainTile();
    private:
        MenuBar* _pMenuBar = NULL;
        MainTile* _pMainTile = NULL;
};

#endif