//
// Created by emiel on 1/04/20.
//

#include <stdlib.h>
#include <dlfcn.h>
#include <iostream>
#include "Utils/Interfaces.h"
#include "include/tf2/Interfaces/IClientEntityList.h"
#include "include/tf2/Interfaces/IBaseClientDll.h"
#include "include/tf2/Interfaces/ICvar.h"
#include "include/tf2/Interfaces/IEngineClient.h"
#include "include/tf2/Interfaces/IPanel.h"
#include "include/tf2/Interfaces/ISurface.h"
#include "include/tf2/Interfaces/IClientMode.h"
#include "include/vmthook/vmthook.h"
#include "Hooks/Hooks.h"
#include "Utils/FindPattern.h"

IClientEntityList* g_entityList;
IBaseClientDll* g_clientdll;
ICvar* g_cvar;
IEngineClient* g_engineclient;
IPanel* g_panel;
ISurface* g_surface;
IClientMode* g_clientmode;

std::unique_ptr<VMTHook> clientmodecreatemode_hook;

bool initialize_interfaces(std::string& err_msg) {
    err_msg = "was null!";
    bool ret = true;

    CreateInterfaceFn client_factory = getFactory("tf/bin/client.so");

    g_entityList = static_cast<IClientEntityList *>(client_factory("VClientEntityList003", nullptr));
    g_clientdll = static_cast<IBaseClientDll *>(client_factory("VClient017", nullptr));
    if (g_entityList == nullptr) {
        err_msg = "entityList " + err_msg;
        ret = false;
    }
    if(!g_clientdll){
        err_msg = "clientdll " + err_msg;
        ret = false;
    }

    g_cvar = static_cast<ICvar *>((getFactory("bin/libvstdlib.so"))("VEngineCvar004", nullptr));
    if(!g_cvar){
        err_msg = "cvar " + err_msg;
        ret = false;
    }

    g_engineclient = static_cast<IEngineClient *>((getFactory("bin/engine.so"))("VEngineClient014", nullptr));
    if(!g_engineclient){
        err_msg = "engineclient " + err_msg;
        ret = false;
    }

    g_panel = static_cast<IPanel *>((getFactory("bin/vgui2.so"))("VGUI_Panel009", nullptr));
    if(!g_cvar){
        err_msg = "panel " + err_msg;
        ret = false;
    }

    void** clienttable = *(void***)g_clientdll;

    uintptr_t pattern_res = FindPattern(clienttable[10],"\x8B\x0D\x00\x00\x00\x00\x00\x8B\x02\xD9\x05","xx????xxxx");
    if(pattern_res)
        g_clientmode = **(IClientMode***)(pattern_res + 2);

    if(!g_clientmode){
        err_msg = "clientmode " + err_msg;
        ret = false;
    }

    return ret;
}

extern "C" void __attribute__((constructor)) entrypoint() {

//    for(InterfaceReg* currentInterface = getInterfaces("bin/vgui2.so"); currentInterface; currentInterface = currentInterface->m_pNext){
//        printf("%s => 0x%X\n", currentInterface->m_pName, currentInterface->m_CreateFn());
//    }

    std::string err_msg;
    if (!initialize_interfaces(err_msg)) {
        printf("%s\n", err_msg.c_str());
        return;
    }

    g_cvar->ConsoleColorPrintf(Color(0,200,50), "[SpectralHook] Interfaces loaded successfully! \n");
    g_cvar->ConsoleColorPrintf(Color(0,170,150), "[SpectralHook] g_clientmode = 0x%X\n", g_clientmode);

    clientmodecreatemode_hook = std::make_unique<VMTHook>(g_clientmode);
    //clientmodecreatemode_hook->HookFunction(reinterpret_cast<void *>(Hooks::ClientModeCreateMove), 21);
}



extern "C" void __attribute__((destructor)) exitpoint() {
    VMTHook* torem = clientmodecreatemode_hook.release();
    delete torem;
    g_cvar->ConsoleColorPrintf(Color(200,0,0), "[SpectralHook] Unloaded successfully! \n");
}


