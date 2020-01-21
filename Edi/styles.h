#ifndef STYLES_H
#define STYLES_H

#include <FL/Fl_Text_Display.H>

Fl_Text_Display::Style_Table_Entry styles[] = 
{	// Style table
    { FL_BLACK,      FL_COURIER,           14 }, // A - Plain
    { FL_DARK_GREEN, FL_HELVETICA_ITALIC,  14 }, // B - Line comments
    { FL_DARK_GREEN, FL_HELVETICA_ITALIC,  14 }, // C - Block comments
    { FL_BLUE,       FL_COURIER,           14 }, // D - Strings
    { FL_DARK_RED,   FL_COURIER,           14 }, // E - Directives
    { FL_DARK_RED,   FL_COURIER_BOLD,      14 }, // F - Types
    { FL_BLUE,       FL_COURIER_BOLD,      14 }, // G - Keywords
};


#endif