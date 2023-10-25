#ifndef CONTROLLER_CPP
#define CONTROLLER_CPP
#include "controller.h"
#include "constants.h"

Controller::Controller(Hero &hero, GameField& field, std::pair <int,int> coord): hero(hero), field(field) {
    if (!check_coord(coord)){
        ERROR_VALUE;
    }
    current_cell = field.get_cell(coord);
    this->coord = coord;
}
std::pair <ui, ui> Controller::get_coord() {
    return coord;
}
bool Controller::set_coord(std::pair<int,int> new_coord) {
    if(check_coord(new_coord)){
        coord = new_coord;
        return true;
    }
    return false;
}
bool Controller::check_coord(std::pair<int,int> coord) {
    return coord.first >= 0 && coord.first < HEIGHT && coord.second >= 0 && coord.second < WIDTH;
}

GameField& Controller::get_field() {
    return field;
}

bool Controller::move(Side side) {
    std::pair<ui, ui> new_coord = coord;
    switch (side){
        case Up:
            std::cout << "MOVE UP" << "\n";
            new_coord.first++;
            break;
        case Down:
            std::cout << "MOVE DOWN" << "\n";
            new_coord.first--;
            break;
        case Left:
            std::cout << "MOVE LEFT" << "\n";
            new_coord.second--;
            break;
        case Right:
            std::cout << "MOVE RIGHT" << "\n";
            new_coord.second++;
            break;
        case Stay:
            std::cout << "STAY IN PLACE" << "\n";
            break;
        default:
            throw std::runtime_error("Incorrect direction value");
            break;
    }
    if (!field.isValidPosition(new_coord)){
        std::cout << "you are out of bounds!\n";
        return false;
    }
    else{
        set_coord(new_coord);
        current_cell = field.get_cell(new_coord);
        if (current_cell.getEvent() != nullptr) {
            current_cell.getEvent()->ApplyEvent(hero, *this);
        }
        return true;
    }


}
#endif