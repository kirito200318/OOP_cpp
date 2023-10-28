#pragma once
#include <iostream>
#include <string>
#define ERROR_VALUE throw std::out_of_range(std::string("Invalid variable value"))

#define ui unsigned int

class Hero {

public:
    Hero(std::string name, int hp, int mana, int attack);


    void getInformation();

    //getter
    ui getEXP();
    ui getCP();
    ui getHP();
    ui getMana();
    ui getAtk();
    std::string getName();

    //setter
    void setEXP(int exp);
    void setCP(int coin_points);
    void setHP(int hp);
    void setMana(int mana);
    void setAtk(int atk);
    void setName(std::string name);



    //check
    bool checkEXP(int exp);
    bool checkCP(int coin_points);
    bool checkHP(int hp);
    bool checkMana(int mana);
    bool checkAtk(int attack);
private:
    ui exp;
    ui coin_points;
    ui hp;
    ui mana;
    ui attack;
    std::string name;
};