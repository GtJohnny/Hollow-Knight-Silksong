//
// Created by Ionuț Nica on 17.04.2024.
//

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H

#include <string>
#include <iostream>
#include <Enemy.h>
#include "Crest.h"
#include "Point.h"
#include "Bloodstain.h"
#include "Enemy.h"
#include "Item.h"

class Player{
    std::string name{};
    int hp{};
    int hpMax{};
    int silk{};
    int silkMax{};
    int speed{};
    int damage{};
    int money{};
    int shield{};
    Crest crest;
    Point point;
    Bloodstain* reper;
    Map* map;
public:
    Player()=default;
    /// @brief Constructor for Player class
    Player(int hp,                            ///@param [int] hp Health will pe represented in masks
           int silk,                          ///@param [int] silk Silk is a resource, basically mana
           const Crest &crest,                ///@param [Crest] crest The crest you spawn with
           const std::string &name,           ///@param [std::string] name The player's name (intended Hornet)
           int money                          ///@param [int] money The player will lose everything upon death
    );
    ///@brief basic sword swing
    void attack();
    void hit(Enemy&enemy);
    ///@brief can hp-ul este egal cu 0, in locul mortii vor ramane toti banii de la purtator
    void death();
    void getHit(int);
    friend class Item;
    friend class Enemy;
    friend class Bloodstain;

    int getHp() const;

    int getSilk() const;

    int getSpeed() const;

    int getDamage() const;

    int getMoney() const;

    int getShield() const;

    int getHpMax() const;

    const Point &getPoint() const;

    Bloodstain *getReper() const;

    Map *getMap() const;

    void setHp(int hp);

    void setSilk(int silk);

    void setShield(int shield);

    void setDamage(int damage);

    void setMoney(int money);
};




#endif //OOP_PLAYER_H
