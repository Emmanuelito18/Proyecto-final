#include <SFML/Graphics.hpp>
#include "headers/entities.h"

Barricade::Barricade( sf::RenderWindow *window) 
{
  pwindow = window;
}

void Barricade::display_barricades()
{
  // TODO:: sprite la wea
    
}

void Barricade::create_barricade()
{
  for (int i = 0; i < 20; i++)
  {
    barricade[i].rect.setSize(sf::Vector2f(20.f, 20.f));
    barricade[i].rect.setOrigin(0.f, 0.f);
  }
}
