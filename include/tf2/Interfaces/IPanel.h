//
// Created by emiel on 9/07/20.
//

#ifndef SPECTRALHOOK_IPANEL_H
#define SPECTRALHOOK_IPANEL_H

#include "../../../Utils/Virtuals.h"

class IPanel {
    const char* GetName(unsigned int vguiPanel) {
        typedef const char* (* OriginalFn)(void*, unsigned int);
        return GetVirtualFunction<OriginalFn>(this, 36)(this, vguiPanel);
    }
};

extern IPanel* g_panel;

#endif //SPECTRALHOOK_IPANEL_H
