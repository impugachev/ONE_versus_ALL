#ifndef ONE_VERSUS_ALL_GAME_H
#define ONE_VERSUS_ALL_GAME_H

class Zombie;

#include <SFML/Graphics.hpp>
#include "Hero.h"

class Game                                  // Класс "Игра"
{
private:
  sf::Texture          background;          // Текстура фона
  sf::Sprite           back;                // Спрайт фона
  Hero                 player;              // Герой игрока
  std::vector<Zombie*> monsters;            // Все враги героя
  sf::Clock            timerSpawnZombies,   // Таймер появления зомби
                       timerSpawnSoldiers,  // Таймер появления солдата
                       timerAttackMonsters, // Таймер атаки врагов
                       reload,              // Таймер перезарядки оружия героя
                       timerHeroShoot,      // Кулдаун стрельбы героя
                       reloadSoldier;       // Таймер перезарядки солдата
public:
  sf::RenderWindow     window;              // Окно игры
  Game();
  void updateHero();                        // Обновить состояние героя
  void updateEnemies();                     // Обновить состояние врагов
  void updateBullets();                     // Обновить состояние пуль
  void outToDisplay();                      // Вывести на экран
  void hello();
  void loadGame(const char* fileName);      // Загрузить игру
  void saveGame(const char* fileName);      // Сохранить игру
  ~Game();
};

#endif