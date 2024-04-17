//
// Created by Ionuț Nica on 17.04.2024.
//

#include "Potions.h"
#include "vector"
///constructori
HealPotion::HealPotion(int uses,const std::string &description, const std::string &name="Heal potion", int value=15, int healValue=20,
                       int cooldown=5)
                       :Item(uses,name,description,value),healValue(healValue),cooldown(cooldown) {}

BluePotion::BluePotion(int uses,const std::string &description, const std::string &name="Heal potion", int value=10, int shield=20,
                       int cooldown=5): Item(uses,name,description,value),shield(shield),cooldown(cooldown) {}
StrengthPotion::StrengthPotion(int uses,const std::string &description, const std::string &name="Heal potion", int value=20, int strength=20)
                        :Item(uses,name,description,value),strength(strength) {}
ExplosionPotion::ExplosionPotion(int uses,const std::string &description, const std::string &name="Heal potion", int value=30,int delay=8,int selfDamage=2, int buff=0)
                        :Item(uses,name,description,value),delay(delay),selfDamage(selfDamage),buff(buff) {}
AoeBuffPot::AoeBuffPot(int uses,const std::string &description, const std::string &name="Heal potion", int value=40, int strength=5,
                       int heal=2,int buff=0): HealPotion(uses,name,description,value),ExplosionPotion(uses,name,description,value),strength(strength),heal(heal),buff(buff) {}




 /// use()

 void HealPotion::use(Player&player){
    player.setHp(std::max(player.getHp()+this->healValue,player.getHpMax()));
    this->uses--;
}

void BluePotion::use(Player &player) {
    player.setShield(player.getShield()+this->shield);
    this->uses--;

}


void StrengthPotion::use(Player &player) {
    player.setDamage(player.getDamage()+this->strength);
    this->uses--;

}


void ExplosionPotion::use(Player &player) {
    player.getHit(this->selfDamage);
    Map map = *player.getMap();


    for(int i=0;i<map.getArr().size();i++){
   //     player.hit(map.getArr().at(i));
        map.getArr().at(i).getHit(this->selfDamage,player);

    }


}
void AoeBuffPot::use(Player &player) {
 //   player.setHp(std::max(player.getHp()+this->healValue,player.getHpMax()));
    player.setDamage(player.getDamage()+this->strength);


    Map map = *player.getMap();


    for(int i=0;i<map.getArr().size();i++){
        //     player.hit(map.getArr().at(i));
      //  map.getArr().at(i).getDamage(this->selfDamage+this->buff,player);
   //     map.getArr().at(i).hp+=this->buff+this->heal;

    }


}



