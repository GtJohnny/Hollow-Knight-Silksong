//
// Created by Ionuț Nica on 17.04.2024.
//

#ifndef OOP_MAP_H
#define OOP_MAP_H

#include <fstream>
#include <string>
#include "Enemy.h"
#include <vector>
class Map{
    static const std::string src;
    std::string path;
    int index;
    std::string name;
    std::vector<Enemy> arr;

public:
    Map()=default;
    ~Map()=default;
    Map(int i);

    const std::vector<Enemy> &getArr();
};






#endif //OOP_MAP_H
