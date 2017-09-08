#include <SFML/Graphics.hpp>

int main()
{
  sf::RenderWindow window(sf::VideoMode(1024, 768), "ONE versus ALL");
  window.setFramerateLimit(60);
  sf::Texture heroTexture;
  heroTexture.loadFromFile("/home/igor/MyProject/ONE_versus_ALL/img/hero.png");
  heroTexture.setSmooth(true);
  sf::Sprite hero;
  hero.setTexture(heroTexture);
  hero.move(472, 319);
  sf::Texture background;
  background.loadFromFile("/home/igor/MyProject/ONE_versus_ALL/img/background.jpg");
  background.setRepeated(true);
  sf::Sprite back(background, sf::IntRect(0, 0, 1024, 768));
  //back.setTextureRect(sf::IntRect(0, 0, 800, 600));
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
    window.draw(back);
    window.draw(hero);
    window.display();
  }
  return 0;
}