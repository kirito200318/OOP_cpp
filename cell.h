#pragma once
#include <iostream>
#include "GameEvent.h"
class Cell {
private:
    bool passable;
    GameEvent* cell_event;

public:

    Cell(bool isPassable = true, GameEvent* cell_event = nullptr);
    Cell(const Cell& other);
    Cell(Cell&& other)  noexcept;
    Cell& operator=(const Cell& other);
    Cell& operator=(Cell&& other)  noexcept;
    ~Cell();
    GameEvent* getEvent();
    void setEvent(GameEvent* game_event);

    bool isPassable();

    void setPassable(bool isPassable);
};
