//
// Created by Ionuț Nica on 17.04.2024.
//

#include "../include/Crest.h"



Crest::Crest(const std::string& description):description(description){
    this->arr=new std::vector<Charm>(5);
}

void Crest::equip(const Charm &charm) {
    if(this->count<5){
        this->arr->emplace_back(charm);
    }
}

void Crest::unequip(Charm &charm) {
    if(this->count=0)return;
    for(int i=0;i<arr->size()-1;i++){
        if((Charm)arr->at(i)==charm) {
            for (int j = i + 1; j < arr->size(); j++) {
                arr[i] = arr[j];
            }
            arr->pop_back();
        }
    }
}
