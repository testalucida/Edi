#include <Edi/GuiHelper.h>
#include <Edi/MenuBar.h>
#include <Edi/MainTile.h>
#include <Edi/MainWindow.h>

#include <FL/Fl_Widget.H>

GuiHelper* GuiHelper::_pInstance = NULL;

void GuiHelper::destroy() {
	delete _pInstance;
}

EdiTabs* GuiHelper::getLastFocusedEdiTabs( Fl_Widget* pWidget ) {
    MainWindow* pWin = (MainWindow*)pWidget->top_window();
    MainTile* pMainTile = pWin->getMainTile();
    return pMainTile->getLastFocusedEdiTabs();
}
