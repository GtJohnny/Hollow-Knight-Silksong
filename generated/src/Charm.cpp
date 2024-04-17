//
// Created by Ionuț Nica on 17.04.2024.
//

#include "../include/Charm.h"


Charm::Charm(const std::string &nume, const std::string &description):name(name),description(description){};

Charm::Charm(const Charm& charm){
    this->description=charm.description;
    this->name=charm.name;
}
Charm& Charm::operator=(const Charm&charm){
    this->description=charm.description;
    this->name=charm.name;
    return *this;
}