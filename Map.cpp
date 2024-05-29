//
// Created by Ionuț Nica on 17.04.2024.
//

#include "../include/Map.h"
#include "fstream"

static const std::string src = "../Maps/map";
Map::Map(int i) {
    char *s;
    itoa(i,s,5);
    this->path=Map::src+s;
    std::ifstream f(this->path);
   //
}

const std::vector<Enemy> &Map::getArr() {
    return arr;
}
