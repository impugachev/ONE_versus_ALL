#include <SFML/Graphics.hpp>

int main()
{
  sf::RenderWindow window(sf::VideoMode(800, 600), "ONE versus ALL");
  window.setFramerateLimit(60);
  sf::CircleShape hero(40);
  hero.move(400, 300);
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
    window.clear();
    window.draw(hero);
    window.display();
  }
  return 0;
}