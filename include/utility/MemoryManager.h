#pragma once
#include <Windows.h>

namespace mem
{
    inline HANDLE _proc;

    /// @brief Find process with specified name
    /// @return Process ID
    uintptr_t getProcess(const char* procName);
        
    /// @brief Find module with specified name
    /// @return Base address of the module
    uintptr_t getModule(uintptr_t procId, const char* moduleName);

    /// @brief Read memory of the process which was found by the function "getProcess"
    template<typename ElemType>
    ElemType readMem(uintptr_t address)
    {
        ElemType ret;
        ReadProcessMemory(_proc, (void*)address, &ret, sizeof(ElemType), NULL);
        return ret;
    }

    /// @brief Write memory of the process which was found by the function "getProcess"
    template<typename ElemType>
    void writeMem(uintptr_t address, ElemType value)
    {
        WriteProcessMemory(_proc, (void*)address, &value, sizeof(ElemType), NULL);
    }    
};