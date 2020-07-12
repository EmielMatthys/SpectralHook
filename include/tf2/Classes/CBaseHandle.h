//
// Created by emiel on 8/07/20.
//

#ifndef SPECTRALHOOK_CBASEHANDLE_H
#define SPECTRALHOOK_CBASEHANDLE_H

#include "../Definitions/Const.h"

class CBaseHandle {
public:
    unsigned  long m_Index;

    inline bool isValid() const {
        return m_Index != INVALID_EHANDLE_INDEX;
    }

    inline int GetEntryIndex() const {
        return m_Index & ENT_ENTRY_MASK;
    }
};

#endif //SPECTRALHOOK_CBASEHANDLE_H
