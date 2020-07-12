//
// Created by emiel on 9/07/20.
//
#include "Hooks.h"
#include "../include/tf2/Interfaces/IClientEntityList.h"
#include "../include/tf2/Interfaces/IEngineClient.h"

typedef bool (*OriginalCreateMove)(IClientMode*, float, CUserCmd*);

bool Hooks::ClientModeCreateMove(IClientMode *thisptr, float flInputSampleTime, CUserCmd *cmd) {

     auto* me = reinterpret_cast<CBasePlayer *>(g_entityList->GetClientEntity(g_engineclient->GetLocalPlayer()));

     if(cmd->buttons & IN_JUMP && !(me->GetFlags() & FL_ONGROUND)) {
         cmd->buttons &= ~ IN_JUMP;
     }

     return clientmodecreatemode_hook->GetOrigianlFunction<OriginalCreateMove>(25)(thisptr, flInputSampleTime, cmd);

}
