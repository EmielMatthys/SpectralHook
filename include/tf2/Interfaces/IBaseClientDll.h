//
// Created by emiel on 8/07/20.
//

#ifndef SPECTRALHOOK_IBASECLIENTDLL_H
#define SPECTRALHOOK_IBASECLIENTDLL_H

#include "../../../Utils/Virtuals.h"
#include "../Classes/ClientClass.h"

enum ClientFrameStage_t : int {
    FRAME_UNDEFINED = -1,
    FRAME_START,
    FRAME_NET_UPDATE_START,
    FRAME_NET_UPDATE_POSTDATAUPDATE_START,
    FRAME_NET_UPDATE_POSTDATAUPDATE_END,
    FRAME_NET_UPDATE_END,
    FRAME_RENDER_START,
    FRAME_RENDER_END
};

class IBaseClientDll {
public:
    ClientClass* GetAllClasses() {
        return GetVirtualFunction<ClientClass*(*)(IBaseClientDll*)>(this, 8)(this);
    }

    void CreateMove(int sequence, float frametime, bool active) {
        return GetVirtualFunction<void(*)(IBaseClientDll*, int, float, bool)>
                (this,21)(this, sequence, frametime, active);
    }

    void FrameStageNotify(ClientFrameStage_t stage){
        return GetVirtualFunction<void(*)(IBaseClientDll*, ClientFrameStage_t)>
                (this, 35)(this, stage);
    }
};

extern IBaseClientDll* g_clientdll;

#endif //SPECTRALHOOK_IBASECLIENTDLL_H
