#ifndef FIELDGENERATE_H
#define FIELDGENERATE_H

#include <vector>
#include "GameField.h"
class FieldGenerate {
public:
    FieldGenerate();

    GameField EasyLevel();
    //GameField HardLevel();
private:
    std::vector <std::string> easy_level;
};

#endif