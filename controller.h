#pragma once
#include "hero.h"
#include "GameField.h"

class Controller {
public:
    enum Side { Up, Down, Right, Left, Stay };
    Controller(Hero& hero, GameField& field, std::pair<int, int> coord);
    bool move(Side side);
    std::pair <ui, ui> get_coord();
    GameField& get_field();
    //setters
    bool set_coord(std::pair<int, int> new_coord);
private:
    Hero& hero;

    GameField& field;
    std::pair <ui, ui> coord;
    Cell current_cell;


};
