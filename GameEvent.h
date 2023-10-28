#pragma once

#include "controller.h"

class GameEvent {
public:
    virtual GameEvent* Clone() = 0;
    virtual void ApplyEvent(Hero& Hero, Controller& controller) = 0;
};
