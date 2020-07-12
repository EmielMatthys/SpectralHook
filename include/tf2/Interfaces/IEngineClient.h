//
// Created by emiel on 8/07/20.
//

#ifndef SPECTRALHOOK_IENGINECLIENT_H
#define SPECTRALHOOK_IENGINECLIENT_H

#include "../../../Utils/Virtuals.h"

class IEngineClient {
public:
    int GetLocalPlayer() {
        return GetVirtualFunction<int(*)(IEngineClient*)>(this, 12)(this);
    }

    void GetScreenSize( int& width, int& height )
    {
        typedef void ( *OriginalFn )( void*, int& , int& );
        return GetVirtualFunction<OriginalFn>( this, 5 )( this, width, height );
    }

    bool Con_IsVisible( )
    {
        typedef bool ( * OriginalFn )( void* );
        return GetVirtualFunction<OriginalFn>( this, 11 )( this );
    }

    float Time( )
    {
        typedef float ( * OriginalFn )( void* );
        return GetVirtualFunction<OriginalFn>( this, 14 )( this );
    }

    int GetMaxClients( )
    {
        typedef int ( * OriginalFn )( void* );
        return GetVirtualFunction<OriginalFn>( this, 21 )( this );
    }
    bool IsInGame( )
    {
        typedef bool ( * OriginalFn )( void* );
        return GetVirtualFunction<OriginalFn>( this, 26 )( this );
    }
    bool IsConnected( )
    {
        typedef bool ( * OriginalFn )( void* );
        return GetVirtualFunction<OriginalFn>( this, 27 )( this );
    }
    bool IsDrawingLoadingImage( )
    {
        typedef bool ( * OriginalFn )( void* );
        return GetVirtualFunction<OriginalFn>( this, 28 )( this );
    }

    bool IsTakingScreenshot( )
    {
        typedef bool ( * OriginalFn )( void* );
        return GetVirtualFunction<OriginalFn>( this, 85 )( this );
    }
    void* GetNetChannelInfo( )
    {
        typedef void* ( * OriginalFn )( void* );
        return GetVirtualFunction<OriginalFn>( this, 72 )( this );
    }
    void ClientCmd_Unrestricted( const char* chCommandString )
    {
        typedef void ( * OriginalFn )( void*, const char * );
        return GetVirtualFunction<OriginalFn>( this, 106 )( this, chCommandString );
    }
};

extern IEngineClient* g_engineclient;

#endif //SPECTRALHOOK_IENGINECLIENT_H
