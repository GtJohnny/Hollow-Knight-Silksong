//
// Created by Ionuț Nica on 17.04.2024.
//

#ifndef OOP_CHARM_H
#define OOP_CHARM_H

#include <string>
#include <ostream>

class Charm{
    std::string name;
    std::string description;

public:
    Charm()=default;
    ~Charm()=default;
    Charm(const std::string& name,const std::string& description);
    Charm(const Charm& charm);
    Charm& operator=(const Charm&charm);
    friend std::ostream &operator<<(std::ostream &os, const Charm &charm){

    }

    bool operator==(const Charm& charm){
        return this->description==charm.description && this->name==charm.name;
    }

};




#endif //OOP_CHARM_H
