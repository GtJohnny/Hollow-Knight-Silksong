#include <iostream>
#include <string>
#include <vector>
#include <stack>
//#include "Player.h"
//#include "Enemy.h"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


void loadTexture(sf::RenderWindow& window, const std::string& fileName,int x,int y, int w, int l){
    sf::Texture tx;
    tx.loadFromFile(fileName);
    sf::IntRect (x,y,w,l);
    sf::Sprite sp(tx);
    auto size = window.getSize();
    sp.setScale(size.x/tx.getSize().x,size.y/tx.getSize().y);
    window.draw(sp);
}



int main() {

    sf::RenderWindow window(sf::VideoMode(1024, 768), "My window");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type){
                case sf::Event::Closed:
                    window.close();
                break;
                case sf::Event::MouseButtonPressed:

                break;

                default:
            }

            sf::IntRect (0,0,1024,768);
            loadTexture(window,"poze/meniu.png",0,0,1024,768);
            loadTexture(window, "QuitGame.png", 800, 300, 200, 70);
            loadTexture(window,"StartGame.png",800,400,200,70);



            window.close();
        }
    }

}

