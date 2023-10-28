#pragma once
#include "cell.h"
Cell::Cell(bool isPassable, GameEvent* cell_event) : passable(isPassable), cell_event(cell_event) {}
bool Cell::isPassable() {
    return passable;
}
void Cell::setPassable(bool isPassable) {
    passable = isPassable;
}

Cell::Cell(const Cell& other) : passable(other.passable), cell_event(nullptr) {
    if (other.cell_event != nullptr) {
        cell_event = other.cell_event->Clone();
    }
}

// ����������� �����������
Cell::Cell(Cell&& other)  noexcept : passable(other.passable), cell_event(nullptr) {
    other.cell_event = nullptr;
}

// �������� ������������ �����������
Cell& Cell::operator=(const Cell& other) {
    if (this == &other) {
        return *this;
    }

    passable = other.passable;

    if (other.cell_event != nullptr) {
        if (cell_event != nullptr) {
            delete cell_event;
        }
        cell_event = other.cell_event->Clone();
    }
    else {
        if (cell_event != nullptr) {
            delete cell_event;
            cell_event = nullptr;
        }
    }

    return *this;
}

// �������� ������������ �����������
Cell& Cell::operator=(Cell&& other)  noexcept {
    if (this == &other) {
        return *this;
    }

    passable = other.passable;

    // ����������� ��������� �� �������
    if (cell_event != nullptr) {
        delete cell_event;
    }

    cell_event = other.cell_event;
    other.cell_event = nullptr;

    return *this;
}

// ����������
Cell::~Cell() {
    if (cell_event != nullptr) {
        delete cell_event;
    }
}


GameEvent* Cell::getEvent() {
    if (cell_event != nullptr)
        return cell_event;
    return nullptr;
}

void Cell::setEvent(GameEvent* game_event) {
    this->cell_event = game_event;
}
