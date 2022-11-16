#pragma once

class Feature
{
public:
    virtual ~Feature() = default;

    virtual void run() = 0;
};