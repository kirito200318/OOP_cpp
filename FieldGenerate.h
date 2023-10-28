#pragma once

#include <vector>
#include "GameField.h"
#include "NegativeEvent.h"
#include "PositiveEvent.h"
#include "MoveToStart.h"
class FieldGenerate {
public:
    FieldGenerate();

    GameField EasyLevel();
    //GameField HardLevel();
private:
    std::vector <std::string> easy_level;
};
