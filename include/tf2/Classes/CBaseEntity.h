//
// Created by emiel on 8/07/20.
//

#ifndef SPECTRALHOOK_CBASEENTITY_H
#define SPECTRALHOOK_CBASEENTITY_H

#include "../../../Utils/NetVars.h"

class CBaseEntity {
public:

};

class CBasePlayer : public CBaseEntity {
public:
    int GetFlags(){
        return *reinterpret_cast<int*>(uintptr_t(this) + NetVars::GetOffset("CBasePlayer", "m_fFlags"));
    }
};

#endif //SPECTRALHOOK_CBASEENTITY_H
