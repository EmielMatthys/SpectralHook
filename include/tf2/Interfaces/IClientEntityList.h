//
// Created by emiel on 8/07/20.
//

#ifndef SPECTRALHOOK_ICLIENTENTITYLIST_H
#define SPECTRALHOOK_ICLIENTENTITYLIST_H

#include "../Classes/CBaseHandle.h"
#include "../Classes/CBaseEntity.h"

class IClientEntityList {
public:
    virtual void* GetClientNetworkable(int) = 0;
    virtual void* GetClientNetworkableFromHandle(CBaseHandle hEnt) = 0;
    virtual void* GetClientUnknownFromHandle(CBaseHandle hEnt) = 0;

    virtual CBaseEntity* GetClientEntity(int entnum) = 0;
    virtual CBaseEntity* GetClientEntityFromHandle(CBaseHandle hEnt) = 0;

    // Returns number of entities currently in use
    virtual int					NumberOfEntities( bool bIncludeNonNetworkable ) = 0;

    // Returns highest index actually used
    virtual int					GetHighestEntityIndex( void ) = 0;

    // Sizes entity list to specified size
    virtual void				SetMaxEntities( int maxents ) = 0;
    virtual int					GetMaxEntities( ) = 0;
};

extern IClientEntityList* g_entityList;

#endif //SPECTRALHOOK_ICLIENTENTITYLIST_H
