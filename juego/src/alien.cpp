#include <SFML/Graphics.hpp>
#include "headers/entities.h"


Alien::Alien(  
    Spaceship &spaceship, 
    sf::RenderWindow* window)
{
  pwindow = window;
  another_b.b_model = &spaceship.bullet.b_model; 
  another_b.visible = &spaceship.bullet.visible; 
}

void Alien::movement(sf::Sprite* sprite)
{
  float lim = pwindow -> getSize().x / 2.8f;

  if (direction)
  {
    if (position[0] < lim)
    {
      sprite -> setPosition(position[0] += speed, position[1]);
    }
    else
    {
      speed += 0.05f;
      sprite -> setPosition(position[0], position[1] += 50.f);
      direction = false; 
    }
  }
  else 
  {
    if (position[0] > 0)
    {
      sprite -> setPosition(position[0] += -(speed), position[1]);
    }
    else
    {
      speed += 0.05f;
      sprite -> setPosition(position[0], position[1] += 50.f);
      direction = true; 
    }
  }
}

void Alien::fire()
{
  // TODO: fire 
  bullet.b_model.setSize(sf::Vector2f(3.f, 30.f)); bullet.b_model.setFillColor(sf::Color::Red); bullet.b_model.setOrigin(sf::Vector2f( // set origin at spaceship position        
        -(pwindow -> getSize().x / 2.f) - position[0], 
        -(pwindow -> getSize().y / 1.15f)));

  bullet.b_model.setPosition(0.f, position[1]);

  if(bullet.visible)
  {
    position[1] < -1000.f ? bullet.visible = false : position[1] += 25.f;
    pwindow -> draw(bullet.b_model);
  }
  else 
  {
    position[1] = 0;
  }

}

void Alien::a_display()
{
  sf::Texture a_texture; // spaceship texture

  if (!a_texture.loadFromFile("assets/alien.png"))
  {
    return;
  }

  // set bounds of bullet
  sf::FloatRect b_bounds = another_b.b_model -> getGlobalBounds();

  float row{};
  float column{-200.f};

  int column_count{};
  int row_count{};
   
  sf::FloatRect bounds[40];
  
  for (int i{}; i < 40; i++)
  {
    if (column_count > 9)
    {
      row = 0.f;
      column += -600.f;
      column_count = 0;
      row_count += 1;
    }

    // setup the sprite location
    a_model[i].sprite.setOrigin(sf::Vector2f(
      row -= (pwindow -> getSize().x / 3.5f) + 200, 
      column));
    column_count++;
    
    // scale and texture alien
    a_model[i].sprite.setScale(sf::Vector2f(0.15f, 0.15f)); // a_scale
    a_model[i].sprite.setTexture(a_texture);              // a_texture

    // get bounds only if visible
    if (a_model[i].visible)
    {
      bounds[i] = a_model[i].sprite.getGlobalBounds();
    }

    // change visibility if touch bullet
    if (bounds[i].intersects(b_bounds))
    {
      a_model[i].visible = false;
      *another_b.visible = false;
    }
    else 
    {
      // draw aliens
      if (a_model[i].visible)
      {
        pwindow -> draw(a_model[i].sprite);
        movement(&a_model[i].sprite);
      }
    }
  } 
}
