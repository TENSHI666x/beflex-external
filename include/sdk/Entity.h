#pragma once

class Entity
{
public:
    int health();
    int getTeam();

    bool isAlive();
    bool isDormant();

    void setSpotted(bool state);
    bool getSpotted();
};