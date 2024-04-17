//
// Created by Ionuț Nica on 17.04.2024.
//

#ifndef OOP_ITEM_H
#define OOP_ITEM_H


#include <string>
#include "Player.h"

class Item{
    std::string name;
    std::string description;
    int value;
protected:
    int uses;
public:
    Item()=default;
    ~Item()=default;
    friend class Player;
    ///@param uses [int] how many times you may use it
    ///@param name [std::string]name
    ///@param description [std::string] what story it may tell
    ///@param value [int] its price if you were to sell it
    Item(int uses,const std::string&name, const std::string&description,int value);
    Item(const Item&item);
    virtual void use(Player&player)=0;
    ///@param player [Player] who uses it
    ///@param qnt how much was sold at once
    [[nodiscard]] int Sell(Player& player,int qnt);
    friend std::ostream& operator<<(std::ostream& out, const Item&item);
    Item& operator=(const Item& item);
};



#endif //OOP_ITEM_H
