#pragma once
#include "FieldGenerate.h"


FieldGenerate::FieldGenerate() {
    //+ - ������ ���������
    //- ������ �����������
    //? - �����
    //s - �����
    //! - ������������� �������
    //x - ���������� ������� �� ������
    //. - ����������� �� �����

    easy_level = {
       "-----",
       "s++--",
       "--+!-",
       "-+x+-",
       "-.-+?"
    };
}

GameField FieldGenerate::EasyLevel() {
    //��������� ������� ������
    GameField field(5, 5);
    for (int y = 0; y < 5; ++y) {
        for (int x = 0; x < 5; ++x) {
            std::pair <int, int> cur_coord = { y,x };
            switch (easy_level[y][x]) {
            case '-':
                field.get_cell(cur_coord).setPassable(false);
                break;
            case 's':
                field.setStartPosition(cur_coord);
                break;
            case 'f':
                field.setExitPosition(cur_coord);
                break;
            case '!':
                field.get_cell(cur_coord).setEvent(new PositiveEvent);
                break;
            case 'x':
                field.get_cell(cur_coord).setEvent(new NegativeEvent);
                break;
            case '.':
                field.get_cell(cur_coord).setEvent(new MoveToStart);
                break;
            }

        }
    }
    return field;
}

