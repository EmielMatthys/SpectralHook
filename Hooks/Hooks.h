//
// Created by emiel on 9/07/20.
//

#ifndef SPECTRALHOOK_HOOKS_H
#define SPECTRALHOOK_HOOKS_H

#include "../include/tf2/Structures/CUserCmd.h"
#include "../include/tf2/Interfaces/IClientMode.h"
#include "../include/vmthook/vmthook.h"

namespace Hooks {
    bool ClientModeCreateMove(IClientMode* thisptr, float flInputSampleTime, CUserCmd* cmd);
}

extern std::unique_ptr<VMTHook> clientmodecreatemode_hook;

#endif //SPECTRALHOOK_HOOKS_H
