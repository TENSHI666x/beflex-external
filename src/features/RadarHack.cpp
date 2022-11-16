#include "features/RadarHack.h"
#include "sdk/Entity.h"
#include "utility/MemoryManager.h"
#include "csgo.hpp"
#include "Globals.h"

void RadarHack::run()
{
    Entity* localPlayer = mem::readMem<Entity*>(g::clientBase + hazedumper::signatures::dwLocalPlayer);
    if (!localPlayer) return;

    for (int i = 0; i < 32; i++)
    {
        Entity* ent = mem::readMem<Entity*>(g::clientBase + hazedumper::signatures::dwEntityList + i * 0x10);
        if (!ent) continue;
        if (!ent->isAlive() || ent->isDormant()) continue;
        ent->setSpotted(true);
    }
}