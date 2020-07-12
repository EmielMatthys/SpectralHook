//
// Created by emiel on 9/07/20.
//

#ifndef SPECTRALHOOK_ISURFACE_H
#define SPECTRALHOOK_ISURFACE_H

#include "../../../Utils/Virtuals.h"

class ISurface {
public:
    void DrawSetColor(int r, int g, int b, int a)
    {
        typedef void(* OriginalFn)(void*, int, int, int, int);
        GetVirtualFunction<OriginalFn>(this, 11)(this, r, g, b, a);
    }
    void DrawFilledRect(int x0, int y0, int x1, int y1)
    {
        typedef void(* OriginalFn)(void*, int, int, int, int);
        GetVirtualFunction<OriginalFn>(this, 12)(this, x0, y0, x1, y1);
    }
    void DrawOutlinedRect(int x0, int y0, int x1, int y1)
    {
        typedef void(* OriginalFn)(void*, int, int, int, int);
        GetVirtualFunction<OriginalFn>(this, 14)(this, x0, y0, x1, y1);
    }
    void DrawSetTextFont(unsigned long font)
    {
        typedef void(* OriginalFn)(void*, unsigned long);
        GetVirtualFunction<OriginalFn>(this, 17)(this, font);
    }
    void DrawSetTextColor(int r, int g, int b, int a)
    {
        typedef void(* OriginalFn)(void*, int, int, int, int);
        GetVirtualFunction<OriginalFn>(this, 19)(this, r, g, b, a);
    }
    void DrawSetTextPos(int x, int y)
    {
        typedef void(* OriginalFn)(void*, int, int);
        GetVirtualFunction<OriginalFn>(this, 20)(this, x, y);
    }
    void DrawPrintText(const wchar_t *text, int textLen)
    {
        typedef void(* OriginalFn)(void*, const wchar_t *, int, int);
        return GetVirtualFunction<OriginalFn>(this, 22)(this, text, textLen, 0);
    }
    unsigned long CreateFont()
    {
        typedef unsigned int(* OriginalFn)(void*);
        return GetVirtualFunction<OriginalFn>(this, 66)(this);
    }
    void SetFontGlyphSet(unsigned long &font, const char *windowsFontName, int tall, int weight, int blur, int scanlines, int flags)
    {
        typedef void(* OriginalFn)(void*, unsigned long, const char*, int, int, int, int, int, int, int);
        GetVirtualFunction<OriginalFn>(this, 67)(this, font, windowsFontName, tall, weight, blur, scanlines, flags, 0, 0);
    }
    void GetTextSize(unsigned long font, const wchar_t *text, int &wide, int &tall)
    {
        typedef void(* OriginalFn)(void*, unsigned long, const wchar_t *, int&, int&);
        GetVirtualFunction<OriginalFn>(this, 75)(this, font, text, wide, tall);
    }
};

extern ISurface* g_surface;

#endif //SPECTRALHOOK_ISURFACE_H
