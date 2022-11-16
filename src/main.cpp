#include <iostream>
#include "utility/MemoryManager.h"
#include "Globals.h"

#include "features/RadarHack.h"

/*
* TODO: 
* 1. Create class for clientBase
* 2. Create a container for all classes that inherit Feature
* 3. Move the main loop somewhere
*/

int main()
{
    uintptr_t procId = mem::getProcess("csgo.exe");
    if (!procId)
    {
        std::cout << "procId\n";
        return EXIT_FAILURE;
    }

    g::clientBase = mem::getModule(procId, "client.dll");
    if (!g::clientBase)
    {
        std::cout << "clientBase\n";
        return EXIT_FAILURE;
    }
    
    RadarHack radarHack;

    std::cout << "Started...\n";
    while (!GetAsyncKeyState(VK_END))
    {
        radarHack.run();
        Sleep(1);
    }
    std::cout << "Exiting...\n";
}
