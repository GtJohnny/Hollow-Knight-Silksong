//
// Created by Ionuț Nica on 17.04.2024.
//

#ifndef OOP_ENEMY_H
#define OOP_ENEMY_H

#include <string>
#include "Point.h"
#include "Player.h"
class Enemy{
    std::string name;
    int hp;
    int hpMax;
    int speed;
    int money;
    Point location;
    friend class Player;
    bool dead = false;

public:
    Enemy()=default;
    ~Enemy(){this->dead=true;};

    
    Enemy(const std::string& nume,        ///@param nume [std::string] Enemy name
                int hp,                    ///@param hp [int] Enemy health
                int money,                ///@param money [int] Money dropped on death
                const Point& location);    ///@param location [Point] Locatia de spawn 
    Enemy(const Enemy& enemy);
    virtual void Attack()=0;
        
    void Death(Player&player);
        ///@param val [int] Damage taken
        ///@param player [Player] Player who dealt that damage
    void getHit(int val,Player&player);
    void getHeal(int);

};





#endif //OOP_ENEMY_H
