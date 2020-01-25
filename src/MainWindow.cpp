#include <Edi/MainWindow.h>

MainWindow::MainWindow( int x, int y, int w, int h ) 
: Fl_Double_Window( x, y, w, h, "Fast C++ IDE" )
{
    _pMenuBar = new MenuBar( 0, 0, w );
    _pMainTile = 
        new MainTile( 0, _pMenuBar->h(), w, h - _pMenuBar->h() );
    end();
    resizable( _pMainTile );
}

MenuBar* MainWindow::getMenuBar() { 
    return _pMenuBar; 
}

MainTile* MainWindow::getMainTile() { 
    return _pMainTile; 
}