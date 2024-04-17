//
// Created by Ionuț Nica on 17.04.2024.
//

#include "../include/Enemy.h"


Enemy::Enemy(const std::string& name, int hp, int money, const Point& location) {
    this->hp=this->hpMax=hp;
    this->name=name;
    this->location=location;
    this->speed=speed;
    this->money=money;
}
void Enemy::Death(Player&player) {
    player.money+=this->money;
    delete this;
}
