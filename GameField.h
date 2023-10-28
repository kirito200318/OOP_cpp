#pragma once
#include "cell.h"
#define ERROR_VALUE throw std::out_of_range(std::string("Invalid variable value"))
class GameField {
private:
    Cell** cells;
    int rows;
    int cols;
    //{row,col}
    std::pair<int, int> coord_start;
    std::pair<int, int> coord_exit;

public:
    GameField(int numRows = 3, int numCols = 3);
    GameField() = default;
    ~GameField();
    //����������� ������������
    GameField(const GameField& other);
    //�������� ������������ �����������
    GameField& operator=(const GameField& other);

    //����������� �����������
    GameField(GameField&& other) noexcept;
    //�������� ������������ �����������
    GameField& operator=(GameField&& other) noexcept;

    void setStartPosition(std::pair<int, int> coord_player);
    void setExitPosition(std::pair<int, int> coord_exit);

    Cell& get_cell(std::pair<int, int> coord);
    int getRows();
    int getCols();
    std::pair<int, int> getStartPosition();
    std::pair<int, int> getExitPosition();

    bool isPlayerAtExit();
    bool check_size(int numRows, int numCols);
    bool isValidPosition(std::pair<int, int> coord);
};