#include "headers/entities.h"
#include <SFML/Graphics.hpp>
// #include <SFML/OpenGL.hpp>

void run();
void kill();

sf::RenderWindow window;                  // window
sf::Event        event;                   // events
Spaceship        player(&event, &window); // player
Alien            alien(player, &window);  // Alien

void run()
{
  window.create(
    sf::VideoMode(2560, 1080),
    "Space Invaders",
    sf::Style::Fullscreen
      );

  window.setVerticalSyncEnabled(true);
  sf::Event events;

  while(window.isOpen())
  {

    while(window.pollEvent(event)) 
    {
        if(event.type == sf::Event::Closed)
        {
          window.close();
        }
        player.input(&event);
    }
    window.clear();       // clear previous frame
    player.ss_display();  // draw spaceship 
    alien.a_display();    // draw aliens
    window.display();     // display all
  }
}

int 
main()
{
  run();
  return 0;
}
