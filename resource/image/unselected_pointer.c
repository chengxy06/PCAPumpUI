/*********************************************************************
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                           www.segger.com                           *
**********************************************************************
*                                                                    *
* C-file generated by                                                *
*                                                                    *
*        Bitmap Converter (ST) for emWin V5.44.                      *
*        Compiled Nov 10 2017, 08:52:20                              *
*                                                                    *
*        (c) 1998 - 2017 Segger Microcontroller GmbH & Co. KG        *
*                                                                    *
**********************************************************************
*                                                                    *
* Source file: unselected_pointer                                    *
* Dimensions:  8 * 1                                                 *
* NumColors:   16                                                    *
*                                                                    *
**********************************************************************
*/

#include <stdlib.h>

#include "GUI.h"

#ifndef GUI_CONST_STORAGE
  #define GUI_CONST_STORAGE const
#endif

extern GUI_CONST_STORAGE GUI_BITMAP bmunselected_pointer;

/*********************************************************************
*
*       Palette
*
*  Description
*    The following are the entries of the palette table.
*    The entries are stored as a 32-bit values of which 24 bits are
*    actually used according to the following bit mask: 0xBBGGRR
*
*    The lower   8 bits represent the Red   component.
*    The middle  8 bits represent the Green component.
*    The highest 8 bits represent the Blue  component.
*/
static GUI_CONST_STORAGE GUI_COLOR _Colorsunselected_pointer[] = {
#if (GUI_USE_ARGB == 0)
  0x000000, 0x111111, 0x222222, 0x333333,
  0x444444, 0x555555, 0x666666, 0x777777,
  0x888888, 0x999999, 0xAAAAAA, 0xBBBBBB,
  0xCCCCCC, 0xDDDDDD, 0xEEEEEE, 0xFFFFFF
#else
  0xFF000000, 0xFF111111, 0xFF222222, 0xFF333333,
  0xFF444444, 0xFF555555, 0xFF666666, 0xFF777777,
  0xFF888888, 0xFF999999, 0xFFAAAAAA, 0xFFBBBBBB,
  0xFFCCCCCC, 0xFFDDDDDD, 0xFFEEEEEE, 0xFFFFFFFF
#endif

};

static GUI_CONST_STORAGE GUI_LOGPALETTE _Palunselected_pointer = {
  16,  // Number of entries
  0,   // No transparency
  &_Colorsunselected_pointer[0]
};

static GUI_CONST_STORAGE unsigned char _acunselected_pointer[] = {
  0xFF, 0xFF, 0xFF, 0xFF
};

GUI_CONST_STORAGE GUI_BITMAP bmunselected_pointer = {
  8, // xSize
  1, // ySize
  4, // BytesPerLine
  4, // BitsPerPixel
  _acunselected_pointer,  // Pointer to picture data (indices)
  &_Palunselected_pointer   // Pointer to palette
};

/*************************** End of file ****************************/
