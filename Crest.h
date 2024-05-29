//
// Created by Ionuț Nica on 17.04.2024.
//

#ifndef OOP_CREST_H
#define OOP_CREST_H

#include <vector>
#include <string>
#include "Charm.h"

class Crest{
    std::string description;
    int count=0;
    std::vector<Charm> *arr;
  //  int power=0;
public:
    Crest()=default;
    virtual ~Crest()=default;
    Crest(const std::string& description);
    void equip(const Charm& charm);
    void unequip(Charm& charm);

    void empty();

    int getCount()const{
        return this->count;
    }

};



#endif //OOP_CREST_H
