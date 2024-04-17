//
// Created by Ionuț Nica on 17.04.2024.
//

#ifndef OOP_BLOODSTAIN_H
#define OOP_BLOODSTAIN_H

#include "Point.h"
#include "Map.h"
#include "Player.h"

class Bloodstain{
    int money;
    Point locatie;
    Map map;
public:
    Bloodstain()=default;
    ~Bloodstain()=default;
    /// Bloodstain - upon death, the player needs to get back to where he perished
    Bloodstain(const Point& point, ///@param point (X,Y) coordonates for where it is situated on the map
               const Map& map,     ///@param map where it actually is
               int money);         ///@param money how much was lost


   [[nodiscard]] int Collect(Player& player); ///@param player the player to which we grant back the money
    int getMoney() const;

    const Point &getLocatie() const;

    const Map &getMap() const;
};




#endif //OOP_BLOODSTAIN_H
