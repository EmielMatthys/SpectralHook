//
// Created by emiel on 8/07/20.
//

#ifndef SPECTRALHOOK_ICVAR_H
#define SPECTRALHOOK_ICVAR_H

#include "../Structures/Color.h"
#include "../../../Utils/Virtuals.h"

class ICvar {
public:
    template <typename... Values> void ConsoleColorPrintf(const Color& col, const char* format, Values... params) {
        return GetVirtualFunction<void(*)(ICvar*, const Color&, const char*, ...)>
                (this, 23)(this, col, format, params...);
    }

    template <typename... Values> void ConsoleDPrintf(const char* format, Values... params){
        return GetVirtualFunction<void(*)(ICvar*, const char*, ...)>(this, 24)(this, format, params...);
    }
};

extern ICvar* g_cvar;

#endif //SPECTRALHOOK_ICVAR_H
