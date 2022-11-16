#include "utility/MemoryManager.h"
#include <TlHelp32.h>

uintptr_t mem::getProcess(const char* processName)
{
	HANDLE processes = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	uintptr_t process;
	PROCESSENTRY32 entry;
	entry.dwSize = sizeof(entry);
 
	do
	{
		if (!strcmp(entry.szExeFile, processName))
		{
			process = entry.th32ProcessID;
			CloseHandle(processes);
			mem::_proc = OpenProcess(PROCESS_ALL_ACCESS, false, process);
            return process;
		}
 
	} while (Process32Next(processes, &entry));
    CloseHandle(processes);
	return 0;
}

uintptr_t mem::getModule(uintptr_t procId, const char* moduleName)
{
    HANDLE modules = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, procId);
	MODULEENTRY32 entry;
	entry.dwSize = sizeof(entry);
 
	do
	{
		if (!strcmp(entry.szModule, moduleName))
		{
			CloseHandle(modules);
			return (uintptr_t)entry.hModule;
		}
	} while (Module32Next(modules, &entry));
    CloseHandle(modules);
	return 0;
}
