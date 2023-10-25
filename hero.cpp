#ifndef HERO_CPP
#define HERO_CPP
#include "hero.h"


Hero::Hero(std::string name, int hp, int mana, int attack): name(name), coin_points(0){


    if (checkHP(hp)){
        this->hp = hp;
    }
    else{
        ERROR_VALUE;
    }
    if (checkMana(mana)){
        this->mana = mana;
    }
    else{
        ERROR_VALUE;
    }
    if (checkAtk(mana)){
        this->attack = attack;
    }
    else{
        ERROR_VALUE;
    }
}
bool Hero::checkEXP(int exp) {
    return exp >= 0 && exp <= 10000;
}
bool Hero::checkCP(int coin_points) {
    return coin_points >= 0 && exp <= 100;
}
bool Hero::checkHP(int hp) {
    return hp > 0 && hp <= 1000;
}
bool Hero::checkMana(int mana) {
    return mana >= 0 && mana <= 100;
}
bool Hero::checkAtk(int attack) {
    return attack >= 0 && attack <= 100;
}


void Hero::getInformation(){
    std::cout << name << " - name" << '\n'
              << hp << " - hp" <<'\n'
              << mana << " - mana" << '\n'
              << attack << " - attack" << '\n'
              << exp << " - experience" << '\n'
              << coin_points << " - coin_points" << '\n';
}

//getters
ui Hero::getEXP(){
    return exp;
}
ui Hero::getCP(){
    return coin_points;
}
ui Hero::getHP() {
    return hp;
}
ui Hero::getMana() {
    return mana;
}
ui Hero::getAtk() {
    return attack;
}
std::string Hero::getName() {
    return name;
}

//setters
void Hero::setHP(int hp){
    if (checkHP(hp)){
        this->hp = hp;
    }else{
        ERROR_VALUE;
    }
}
void Hero::setMana(int mana){
    if (!checkMana(mana)){
        ERROR_VALUE;
    }else{
        this->mana = mana;
    }
}
void Hero::setAtk(int attack){
    if(!checkAtk(attack)){
        ERROR_VALUE;
    }else{
        this->attack = attack;
    }
}
void Hero::setName(std::string name){
    this->name = name;
}
void Hero::setEXP(int exp){
    if (!checkEXP(exp)){
        ERROR_VALUE;
    }else{
        this->exp = exp;
    }
}
void Hero::setCP(int coin_points){
    if (!checkCP(coin_points)){
        ERROR_VALUE;
    }else{
        this->coin_points = coin_points;
    }
}

#endif