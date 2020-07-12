//
// Created by emiel on 8/07/20.
//

#ifndef SPECTRALHOOK_VMTHOOK_H
#define SPECTRALHOOK_VMTHOOK_H

#include <cstdint>
#include <cstddef>
#include <cstring>
#include <memory>
#include <vector>
#include <algorithm>

class VMTHook {
private:
    uintptr_t** baseclass = nullptr;
    std::unique_ptr<uintptr_t[]> current_vft = nullptr;
    uintptr_t* original_vft = nullptr;
    size_t total_functions = 0;

public:
    VMTHook() = default;
    explicit VMTHook(void* baseclass) {
        this->baseclass = static_cast<uintptr_t ** >(baseclass);

        while (static_cast<uintptr_t*>(*this->baseclass)[this->total_functions])
            ++this->total_functions;

        const std::size_t table_size = this->total_functions * sizeof(uintptr_t);
        this->original_vft = *this->baseclass;
        this->current_vft = std::make_unique<uintptr_t[]>(this->total_functions);

        std::memcpy(this->current_vft.get(), this->original_vft, table_size);

        *this->baseclass = this->current_vft.get();

    }

    ~VMTHook() {
        *this->baseclass = this->original_vft;
    }

    inline void* GetOriginalFunction(size_t function_index){
        return reinterpret_cast<void *>(this->original_vft[function_index]);
    }

    template <typename Function> inline const Function GetOrigianlFunction(size_t function_index) {
        return reinterpret_cast<Function>(this->original_vft[function_index]);
    }

    inline bool HookFunction(void* new_func, const size_t index) {
        if(index > this->total_functions)
            return false;

        this->current_vft[index] = reinterpret_cast<uintptr_t >(new_func);
        return true;
    }

    inline bool UnhookFunction(const size_t index) {
        if (index > this->total_functions)
            return false;

        this->current_vft[index] = this->original_vft[index];
        return true;
    }

    inline size_t  GetTotalFunctions() {
        return this->total_functions;
    }



};

#endif //SPECTRALHOOK_VMTHOOK_H
