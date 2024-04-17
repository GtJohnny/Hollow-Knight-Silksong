//
// Created by Ionuț Nica on 17.04.2024.
//

#include "../include/Item.h"
#include <iostream>

int Item::Sell(Player &player,int qnt=1) {
    if(qnt>this->value)qnt=this->value;
    this->uses -=qnt;
    player.money+=qnt*this->value;
}


Item::Item(int uses,const std::string&name, const std::string&description,int value=1):uses(uses),name(name),description(description),value(value){};

Item::Item(const Item &item) {
    this->value=item.value;
    this->uses=item.uses;
    this->name=item.name;
    this->description=item.description;
}

std::ostream& operator<<(std::ostream& out, const Item&item){
    out<<"Name: "<<item.name<<"\nDescription: "<<item.description<<"\n Uses: "<<item.uses<<"\n";
}

Item& Item::operator=(const Item& item){
    this->description=item.description;
    this->uses=item.uses;
    this->name=item.name;
    this->value=item.value;
    return *this;
}