//
// Created by emiel on 11/07/20.
//

#ifndef SPECTRALHOOK_FINDPATTERN_H
#define SPECTRALHOOK_FINDPATTERN_H

#include <cstdint>
#include <cstdlib>

inline bool Compare (const uint8_t* data, const uint8_t* pattern, const char* mask) {
    for (; *mask; ++mask, ++data, ++pattern) {
        if (*mask == 'x' && *data != *pattern) {
            return false;
        }
    }

    return *mask == 0;
}

static uintptr_t FindPattern(void* start, const char* pattern_string, const char* mask) {
    size_t address = reinterpret_cast<size_t>(start), length = 100000000;
    const auto* pattern = reinterpret_cast<const uint8_t* >(pattern_string);

    for (size_t i = 0; i < length; i++) {
        if (Compare(reinterpret_cast<const uint8_t *>(address + i), pattern, mask)) {
            return address + i;
        }
    }

    return 0;
}

#endif //SPECTRALHOOK_FINDPATTERN_H
