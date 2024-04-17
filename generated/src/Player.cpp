//
// Created by Ionuț Nica on 17.04.2024.
//

#include "../include/Player.h"

Player::Player(int hp, int silk,  const Crest &crest,const std::string &name = "Hornet", int money=0)
    :hp(hp),hpMax(5),silk(silk),silkMax(99),speed(10),damage(5),crest(crest),money(money){
    this->map=new Map(1);
}

void Player::attack() {
    ///
}
void Player::hit(Enemy&enemy) {
    ///
}
void Player::death() {
    if(this->reper) delete this->reper;
    this->reper = new Bloodstain(this->point,*this->map,this->money);
    this->money=0;
}

int Player::getHp() const {
    return hp;
}

int Player::getSilk() const {
    return silk;
}

int Player::getSpeed() const {
    return speed;
}

int Player::getDamage() const {
    return damage;
}

int Player::getMoney() const {
    return money;
}

const Point &Player::getPoint() const {
    return point;
}

Bloodstain *Player::getReper() const {
    return reper;
}

Map *Player::getMap() const {
    return map;
}

void Player::setHp(int hp) {
    Player::hp = hp;
}

void Player::setSilk(int silk) {
    Player::silk = silk;
}

void Player::setDamage(int damage) {
    Player::damage = damage;
}

void Player::setMoney(int money) {
    Player::money = money;
}

int Player::getHpMax() const {
    return hpMax;
}

int Player::getShield() const {
    return shield;
}

void Player::setShield(int shield) {
    Player::shield = shield;
}
