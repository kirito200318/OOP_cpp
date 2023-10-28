#pragma once
#include "GameField.h"

GameField::GameField(int numRows, int numCols) : rows(-1), cols(-1), coord_start(std::pair<int, int>{-1, -1}), coord_exit(std::pair<int, int>{-1, -1}) {
    if (!check_size(numRows, numCols)) {
        ERROR_VALUE;
    }
    rows = numRows;
    cols = numCols;
    cells = new Cell * [rows];
    for (int i = 0; i < rows; ++i) {
        cells[i] = new Cell[cols];
    }
}

GameField::~GameField() {
    for (int i = 0; i < rows; ++i) {
        delete[] cells[i];
    }
    delete[] cells;
}

GameField::GameField(const GameField& other) : rows(other.rows), cols(other.cols), coord_start(std::pair<int, int>{other.coord_start.first, other.coord_start.second}), coord_exit(std::pair<int, int>{other.coord_exit.first, other.coord_exit.second}) {
    cells = new Cell * [rows];
    for (int i = 0; i < rows; ++i) {
        cells[i] = new Cell[cols];
        for (int j = 0; j < cols; ++j) {
            cells[i][j] = other.cells[i][j];
        }
    }
}
bool GameField::check_size(int numRows, int numCols) {
    return numRows >= 3 && numCols >= 3;
}
GameField& GameField::operator=(const GameField& other) {
    if (this == &other) {
        return *this;
    }

    // Clean up existing resources
    for (int i = 0; i < rows; ++i) {
        delete[] cells[i];
    }
    delete[] cells;

    // Copy data from other
    rows = other.rows;
    cols = other.cols;
    coord_start = other.coord_start;
    coord_exit = other.coord_exit;

    cells = new Cell * [rows];
    for (int i = 0; i < rows; ++i) {
        cells[i] = new Cell[cols];
        for (int j = 0; j < cols; ++j) {
            cells[i][j] = other.cells[i][j];
        }
    }

    return *this;
}

GameField::GameField(GameField&& other) noexcept : rows(other.rows), cols(other.cols), coord_start(std::pair<int, int>{other.coord_start.first, other.coord_start.second}), coord_exit(std::pair<int, int>{other.coord_exit.first, other.coord_exit.second}), cells(other.cells) {
    other.rows = -1;
    other.cols = -1;
    other.cells = nullptr;
    other.coord_start = std::pair<int, int>{ -1,-1 };
    other.coord_exit = std::pair<int, int>{ -1,-1 };
}

GameField& GameField::operator=(GameField&& other) noexcept {
    if (this == &other) {
        return *this;
    }

    // Clean up existing resources
    for (int i = 0; i < rows; ++i) {
        delete[] cells[i];
    }
    delete[] cells;

    // Copy data from other
    rows = other.rows;
    cols = other.cols;
    coord_start = other.coord_start;
    coord_exit = other.coord_exit;
    cells = other.cells;

    //обнуляем other
    other.rows = -1;
    other.cols = -1;
    other.cells = nullptr;
    other.coord_start = std::pair<int, int>{ -1,-1 };
    other.coord_exit = std::pair<int, int>{ -1,-1 };
    return *this;
}
int GameField::getRows() {
    return rows;
}
int GameField::getCols() {
    return cols;
}
Cell& GameField::get_cell(std::pair<int, int> coord) {
    return cells[coord.first][coord.second];
}

std::pair<int, int> GameField::getStartPosition() {
    return coord_start;
}

std::pair<int, int> GameField::getExitPosition() {
    return coord_exit;
}

void GameField::setStartPosition(std::pair<int, int> coord_player) {
    if (isValidPosition(coord_player) && cells[coord_player.first][coord_player.second].isPassable()) {
        this->coord_start = coord_player;
    }
}

void GameField::setExitPosition(std::pair<int, int> coord_exit) {
    if (isValidPosition(coord_exit)) {
        this->coord_exit = coord_exit;
    }
}

bool GameField::isPlayerAtExit() {
    return coord_start == coord_exit;
}

bool GameField::isValidPosition(std::pair<int, int> coord) {
    return coord.first >= 0 && coord.first < rows && coord.second >= 0 && coord.second < cols && get_cell(coord).isPassable();
}
