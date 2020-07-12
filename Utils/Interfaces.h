//
// Created by emiel on 8/07/20.
//

#ifndef SPECTRALHOOK_INTERFACES_H
#define SPECTRALHOOK_INTERFACES_H

#include <dlfcn.h>
#include <stdlib.h>
#include <cstdint>


typedef void* (*InstantiateInterfaceFn)();
typedef void* (*CreateInterfaceFn) (char*, int*);

class InterfaceReg {
public:
    InstantiateInterfaceFn m_CreateFn;
    char * m_pName;
    InterfaceReg* m_pNext;
};

inline InterfaceReg* getInterfaces(const char* module) {
    void* library_handle = dlopen(module, RTLD_NOLOAD | RTLD_NOW);

    void* interfaceregs_symb = dlsym(library_handle, "s_pInterfaceRegs");

    if(interfaceregs_symb) {
        dlclose(library_handle);
        return *reinterpret_cast<InterfaceReg**>(interfaceregs_symb);
    }else{
        void* createinterface_symb = dlsym(library_handle, "CreateInterface");
        dlclose(library_handle);

        uintptr_t jmp_adr = uintptr_t(createinterface_symb) + 4;
        int32_t jump_offset = *reinterpret_cast<int32_t*> (jmp_adr + 1);

        uintptr_t createinterfaceinternal_addr = (jmp_adr + 5) + jump_offset;

        return **reinterpret_cast<InterfaceReg***>(createinterfaceinternal_addr + 11);
    }
}

inline CreateInterfaceFn getFactory(const char* module) {
    void* library_handle = dlopen(module, RTLD_NOLOAD | RTLD_NOW);
    void* createinterface_symb = dlsym(library_handle, "CreateInterface");
    dlclose(library_handle);

    return reinterpret_cast<CreateInterfaceFn>(createinterface_symb);
}

#endif //SPECTRALHOOK_INTERFACES_H
