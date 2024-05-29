//
// Created by Ionuț Nica on 17.04.2024.
//

#ifndef OOP_POTIONS_H
#define OOP_POTIONS_H

#include "Item.h"
#include <string>


class HealPotion:virtual public Item{
    int cooldown;
private:
    int healValue;
public:
    ///@brief Will heal
    ///@param uses how many times you may use it
    ///@param name name
    ///@param description what story it may tell
    ///@param value its price if you were to sell it
    ///@param cooldown duration between casts
    HealPotion(int uses, const std::string& name,const std::string& description, int value, int healValue, int cooldown);
    virtual void use(Player&player) override;
};



class BluePotion:virtual public Item{
    int shield;
    int cooldown;
public:
    ///@brief Will give a few masks of shield
    ///@param uses how many times you may use it
    ///@param name name
    ///@param description what story it may tell
    ///@param value its price if you were to sell it
    ///@param shield how many blue masks you gain
    ///@param cooldown duration between casts
    BluePotion(int uses, const std::string& name,const std::string& description, int value, int shield, int cooldown);
    virtual void use(Player&player) override;


};

class StrengthPotion:virtual public Item{
    int strength;
public:
    ///@brief Will increase strength
    ///@param uses how many times you may use it
    ///@param name name
    ///@param description what story it may tell
    ///@param value its price if you were to sell it
    ///@param strength how mighty you become
    StrengthPotion(int uses, const std::string& name,const std::string& description, int value, int strength);
    virtual void use(Player&player) override;

};

class ExplosionPotion:virtual public Item{
    int delay;
    int selfDamage;
    int buff;
public:
    ///@brief Will deal damage to everybody you can see
    ///@param uses [int] how many times you may use it
    ///@param name [std::string]name
    ///@param description [std::string]what story it may tell
    ///@param value[int] its price if you were to sell it
    ///@param delay[int] it's a ticking bomb..so wait
    ///@param selfDamage[int] it will hurt you as well
    ///@param buff [int] how much the damage can be increased
    ExplosionPotion(int uses, const std::string& name,const std::string& description,int value, int delay, int selfDamage,int buff);
    virtual void use(Player&player) override;
};


class AoeBuffPot:virtual public HealPotion, virtual public ExplosionPotion{

    int strength;
    int heal;
    int buff;
public:
    ///@brief Will heal and increase strength to everyone
    ///@param uses [int] how many times you may use it
    ///@param name [std::string]name
    ///@param description [std::string]what story it may tell
    ///@param value[int] its price if you were to sell it
    ///@param delay[int] it's a ticking bomb..so wait
    ///@param heal[int] healing power
    ///@param buff [int] how much the heal can be increased
    AoeBuffPot(int uses, const std::string& name,const std::string& description,int value, int delay, int heal,int buff);


};



#endif //OOP_POTIONS_H
