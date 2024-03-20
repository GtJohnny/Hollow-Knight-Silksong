#include <iostream>
#include <string>
#include <vector>
#include <stack>



enum tip{cloak,architect,assassin,old}charm_type;

class Item{
    std::string Name;
    std::string Description;
    int usages;
public:
    friend void UseItem();

    friend std::ostream &operator<<(std::ostream &os, const Item &item) {
        os << "Name: " << item.Name << " Description: " << item.Description << " usages: " << item.usages;
        return os;
    }
};

class Charm{
public:
    Charm()=default;
    Charm(const std::string &denumire, const std::string &descriere,const tip &type=old, int impact=1) : Denumire(denumire), Descriere(descriere), type(type),   impact(impact) {}
    Charm(const Charm&obj){
        this->impact=obj.impact;
        this->Denumire=obj.Denumire;
        this->type=obj.type;
        this->Descriere=obj.Descriere;
    }

    Charm& operator=(const Charm& obj) {
        if(this!=&obj) {
            this->Denumire = obj.Denumire;
            this->Descriere = obj.Descriere;
            this->type = obj.type;
            this->impact = obj.impact;
        }
        return *this;
    }

    const Charm operator+(const Charm& obj)
    {
        Charm c;
        c.Descriere=obj.Descriere;
        c.type=obj.type;
        c.Denumire=obj.Denumire;
        c.impact=this->impact+obj.impact;
        return c;
    }

    const Charm operator+(const int&nr){
        Charm c;
        c.Descriere=this->getDescriere();
        c.type=this->type;
        c.Denumire=this->Denumire+"+";
        c.impact=this->impact+nr;
        return c;
    };

    const std::string &getDenumire() const {
        return Denumire;
    }

    void setDenumire(const std::string &denumire) {
        Denumire = denumire;
    }

    const std::string &getDescriere() const {
        return Descriere;
    }

    void setDescriere(const std::string &descriere) {
        Descriere = descriere;
    }

    tip getType() const {
        return type;
    }

    void setType(tip type) {
        Charm::type = type;
    }

    int getImpact() const {
        return impact;
    }

    void setImpact(int impact) {
        Charm::impact = impact;
    }

    friend std::ostream &operator<<(std::ostream &out, const Charm &charm) {
        out << "Charm: " << charm.Denumire << "\nDescriere: " << charm.Descriere << "\nDe tip: " << charm.type << "\nCu: " << charm.impact<<'\n';
        return out;
    }

private:
    std::string Denumire;
    std::string Descriere;
    tip type=old;
    int impact=0;



};

class Crest{
    std::string description;
    tip crest_type;
    std::stack<Charm> inv;
public:
    Crest(const tip&crest):crest_type(crest){}

    const std::string &getDescription() const {
        return description;
    }

    void setDescription(const std::string &description) {
        Crest::description = description;
    }

    tip getCrestType() const {
        return crest_type;
    }

    void setCrestType(tip crestType) {
        crest_type = crestType;
    }

    const std::stack<Charm> &getInv() const {
        return inv;
    }

    void setInv(const std::stack<Charm> &inv) {
        Crest::inv = inv;
    }

    friend std::ostream &operator<<(std::ostream &out, const Crest &crest) {
        out << "Descriere: " << crest.description << "\nTip: " << crest.crest_type << "Lista charms:\n";
        for(int i=0;i<crest.inv.size();i++) {
            out << crest.inv.top()<<'\n';
        }
        if(crest.inv.empty()){
            out<<"Gol\n";
        }
        return out;
    };


};

class Enemy{
    int hp,armor,agility,evade;
public:
    friend void AttackPlayer();
    friend void Death();

    friend std::ostream &operator<<(std::ostream &os, const Enemy &enemy) {
        os << "hp: " << enemy.hp << " armor: " << enemy.armor << " agility: " << enemy.agility << " evade: "
           << enemy.evade;
        return os;
    }
};

class Point{
    int x,y;
public:
    Point()=default;
    Point(const int&x,const int&y):x(x),y(y){}

};

class Location{
    Point p;
    int room;
public:
    Location()=default;
    Location(const Point&p,int &i):p(p),room(i){}

};


class Bloodstain{
    int money;
    Location loc;
    bool collected;
public:
    Bloodstain(const int& money,const Location&loc):money(money),collected(false),loc(loc){};
    friend void Collect();

    ~Bloodstain(){
        if(!collected){
            if(this->money>200){
                std::cout<<"\nA great deal of shells have been lost\n";
            }
            if(this->money>100){
                std::cout<<"\nAn honest sum of shells has been lost\n";
            }if(this->money>50){
                std::cout<<"\nA speck of dust and money may have been forgotten\n";
            }
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const Bloodstain &bloodstain) {
        os << "money: " << bloodstain.money << " loc: " << bloodstain.loc << " collected: " << bloodstain.collected;
        return os;
    }

};


class Player{
    std::string nume;
    int health;
    int max_health;
    int speed;
    int money;
    int damage;
    float silk; //mana
    float max_silk;
    int armor;
    tip equippedCrest;
    Bloodstain *ptr;
    friend Bloodstain;
    Location loc;

public:
    //ToDo
    void Jump();
    void Walk();

    int getHealth() const {
        return this->health;
    }

    int getMaxHealth() const {
        return this->max_health;
    }

    int getSpeed() const {
        return this->speed;
    }

    int getMoney() const {
        return this->money;
    }

    float getSilk() const {
        return this->silk;
    }

    float getMaxSilk() const {
        return this->max_silk;
    }

    void setHealth(int health) {
        this->health = health;
    }

    void setMaxHealth(int maxHealth) {
        this->max_health = maxHealth;
    }

    void setSpeed(int speed) {
        this->speed = speed;
    }

    void setMoney(int money) {
        this->money = money;
    }

    void setSilk(float silk) {
        this->silk = silk;
    }

    void setMaxSilk(float maxSilk) {
        this->max_silk = maxSilk;
    }

    const std::string &getNume() const {
        return this->nume;
    }

    void setNume(const std::string &nume) {
        this->nume = nume;
    }

    tip getEquippedCharm() const {
        return this->equippedCrest;
    }

    void setEquippedCharm(tip equippedCrest) {
        this->equippedCrest = equippedCrest;
    }
 //   Player player("Hornet",5,5,0,15,old,12);

    Player(const std::string &nume,const int &hp,const int & max_hp, const float &silk, const float &max_silk,const tip&eq ,const int &damage) {
        this->nume = nume;
        this->health = hp;
        this->silk = silk;
        this->max_silk = max_silk;
        this->max_health = max_hp;
        this->equippedCrest = eq;
        this->damage = damage;
        this->money = 0;
        this->speed = 10;
        this->armor = 0;
    }


    void Spawn ();
    void Death(){
        if(this->ptr !=NULL)
            delete this->ptr;
        this->ptr=new Bloodstain(this->money,this->loc);
    }
    void Retrieval(){

    }
    friend void EquipCrest();
    friend void PlayerAttack();

    int getDamage() const {
        return damage;
    }

    void setDamage(int damage) {
        Player::damage = damage;
    }

    void EquipCrest(const Crest&crest){
        this->equippedCrest=crest.getCrestType();
    }

    friend std::ostream &operator<<(std::ostream &out, const Player &player) {
        out << "Viata: " << player.health << "/" << player.max_health<< "\nsilk: " << player.silk << "/"<< player.max_silk << "\nBani: " << player.money << "\nDamage: " << player.damage <<"\n\n";
        return out;
    }

};




int main() {
    /// select items, customizable, select crest


    Player player("Hornet",5,5,0,15,old,12);
    std::cout<<player;
    Crest crest1(assassin);
    player.EquipCrest(crest1);
    Charm c1("Den1","Des",cloak,7);
    std::cout<<c1;
    Charm c2("Apex","an",assassin,10);
    std::cout<<c2;
    Charm c4("D3","Des",old,8);
    Charm c3=c2+c1;
    std::cout<<c3;
    /*
    player.attack()

    */
    if(player.getHealth()==0) {
        player.Death();
        player.Retrieval();
    }





}
