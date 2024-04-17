//
// Created by Ionuț Nica on 17.04.2024.
//


#include "../include/Bloodstain.h"

///@param map where the player died
///@param money how much it was lost
///@param point where precisely it happened
Bloodstain::Bloodstain(const Point& point,const Map& map,int money=0):locatie(point),map(map),money(money){
    //**
};
            ///@param player Player that collects lost money
[[nodiscard]] int Bloodstain::Collect(Player &player) {

    if (this->money > 200) {
        std::cout << "\nA great deal of shells have been lost\n";
    }
    if (this->money > 100) {
        std::cout << "\nAn honest sum of shells has been lost\n";
    }
    if (this->money > 50) {
        std::cout << "\nA speck of dust and money may have been forgotten\n";
    }
    return player.money += this->money;
}

int Bloodstain::getMoney() const {
    return money;
}

const Point &Bloodstain::getLocatie() const {
    return locatie;
}

const Map &Bloodstain::getMap() const {
    return map;
}
