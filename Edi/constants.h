#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <FL/Enumerations.H>
#include <FL/Fl_Widget.H>

#define TODO (//TODO)

static const int MENUBARHEIGHT = 25;
static const int EDIROWHEADERWIDTH = 20;
static const int MESSAGEPANELHEIGHT = 40;
static const int EXPLORERWIDTH = 150;
static Fl_Callback* NOCALLBACK = (Fl_Callback *)0;
static const int NOSHORTCUT = 0;
static void* NOUSERDATA = (void*)0;
static const int NOFLAGS = 0;
static const int DEFAULTLABELTYPE = (uchar)0;
static const int DEFAULTLABELFONT = 0;
static const int DEFAULTLABELSIZE = 14;
static const Fl_Color DEFAULTLABELCOLOR = 51;


#define MAINTILECOLOR (fl_rgb_color( 229, 229, 229 ))
#define TABSELECTIONCOLOR (fl_rgb_color( 249, 249, 205 ))


#endif