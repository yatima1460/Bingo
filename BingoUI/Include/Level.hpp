#pragma once

class Level
{

public:

    virtual void BeginLevel() = 0;

    virtual void Update() = 0;

    virtual void Draw() = 0;

    virtual void EndLevel() = 0;

    virtual ~Level() = default;

};