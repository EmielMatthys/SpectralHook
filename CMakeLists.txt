cmake_minimum_required(VERSION 3.15)
project(SpectralHook)

set(CMAKE_CXX_STANDARD 14)


add_library(SpectralHook SHARED
        spectralhook.cpp
        entrypoint.cpp Utils/Interfaces.h include/tf2/Interfaces/ICvar.h include/tf2/Interfaces/IClientEntityList.h
        include/tf2/Interfaces/IBaseClientDll.h include/vmthook/vmthook.h Utils/Virtuals.h include/tf2/Structures/Color.h
        Utils/Logger/ILogger.h Utils/Logger/CGameConsoleLogger.cpp Utils/Logger/CGameConsoleLogger.h

        include/tf2/Classes/CBaseHandle.h include/tf2/Definitions/Const.h include/tf2/Classes/CBaseEntity.h include/tf2/Interfaces/IEngineClient.h include/tf2/Structures/PlayerInfo.h include/tf2/Classes/ClientClass.h include/tf2/Interfaces/IPanel.h include/tf2/Interfaces/ISurface.h include/tf2/Structures/CUserCmd.h include/tf2/Classes/Vector.h include/tf2/Interfaces/IClientMode.h Hooks/Hooks.h Hooks/ClientModeCreateMove.cpp Utils/NetVars.h include/tf2/Classes/RecvTable.h Utils/FindPattern.h)

#set_target_properties(SpectralHook PROPERTIES PUBLIC_HEADER include/spectralhook.h)
set_target_properties(SpectralHook PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-m32")
