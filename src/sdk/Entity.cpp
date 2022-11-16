#include "sdk/Entity.h"
#include "csgo.hpp"
#include "utility/MemoryManager.h"

int Entity::health()
{
    return mem::readMem<int>((uintptr_t)this + hazedumper::netvars::m_iHealth);
}

int Entity::getTeam()
{
    return mem::readMem<int>((uintptr_t)this + hazedumper::netvars::m_iTeamNum);
}

bool Entity::isAlive()
{
    return health() > 0;
}

bool Entity::isDormant()
{
    return mem::readMem<bool>((uintptr_t)this + hazedumper::signatures::m_bDormant);
}

void Entity::setSpotted(bool state)
{
    mem::writeMem<bool>((uintptr_t)this + hazedumper::netvars::m_bSpotted, state);
}

bool Entity::getSpotted()
{
    return mem::readMem<bool>((uintptr_t)this + hazedumper::netvars::m_bSpotted);
}