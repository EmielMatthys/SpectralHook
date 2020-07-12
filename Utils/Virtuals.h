//
// Created by emiel on 8/07/20.
//

#ifndef SPECTRALHOOK_VIRTUALS_H
#define SPECTRALHOOK_VIRTUALS_H

#include <cstddef>

inline void**& GetVirtualTable(void* baseclass) {
    return *reinterpret_cast<void***>(baseclass);
}

template <typename Fn = void*> inline Fn GetVirtualFunction(void* baseclass, size_t index) {
    return reinterpret_cast<Fn>(GetVirtualTable(baseclass)[index]);
}


#endif //SPECTRALHOOK_VIRTUALS_H
