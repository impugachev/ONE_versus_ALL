#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

int main()
{
  sf::RenderWindow window(sf::VideoMode(1024, 768), "ONE versus ALL");
  window.setFramerateLimit(60);
  sf::Texture heroTexture;
  heroTexture.loadFromFile("/home/igor/CLionProjects/ONE_versus_ALL/img/hero.png");
  heroTexture.setSmooth(true);
  sf::Sprite hero;
  hero.setTexture(heroTexture);
  hero.setOrigin(40, 65);
  hero.move(512, 384);
  sf::Vector2i heropos =  sf::Vector2i(512, 384);

  sf::Texture background;
  background.loadFromFile("/home/igor/CLionProjects/ONE_versus_ALL/img/background.jpg");
  background.setRepeated(true);
  sf::Sprite back(background, sf::IntRect(0, 0, 1024, 768));
  sf::Vector2i mousePos;
  //hero.setRotation(90);
  //back.setTextureRect(sf::IntRect(0, 0, 800, 600));
  //hero.rotate(-90);
  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
      hero.move(0, -5);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
      hero.move(0, 5);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
      hero.move(-5, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
      hero.move(5, 0);
    mousePos = sf::Mouse::getPosition(window);
    sf::Vector2i vect = mousePos-heropos;
    float rot = acos(vect.y/sqrt(vect.x*vect.x+vect.y*vect.y))*180/3.14159265 - 180;
    rot = vect.x < 0 ? rot : -rot;
    std::cerr << hero.getPosition().x << " " << hero.getPosition().y << "\n";
    //std::cerr << rot << "\n";
    hero.setRotation(rot);
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {

      std::cerr << "mouse " << mousePos.x << " " << mousePos.y << "\n";
      //hero.rotate(-90);
      //hero.move(57, 35);
    }
    window.clear();
    window.draw(back);
    window.draw(hero);
    window.display();
  }
  return 0;
}