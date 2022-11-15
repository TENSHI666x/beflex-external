#pragma once
#include <Windows.h>

class MemoryManager
{
public:
    uintptr_t getProcess(const char* procName);
    uintptr_t getModule(uintptr_t procId, const char* moduleName);

    template<typename ElemType>
    ElemType readMem(uintptr_t address)
    {
        ElemType ret;
        ReadProcessMemory(_proc, (void*)address, &ret, sizeof(ElemType), NULL);
        return ret;
    }

    template<typename ElemType>
    void writeMem(uintptr_t address, ElemType value)
    {
        WriteProcessMemory(_proc, (void*)address, &value, sizeof(ElemType), NULL);
    }    

private:
    HANDLE _proc;
};