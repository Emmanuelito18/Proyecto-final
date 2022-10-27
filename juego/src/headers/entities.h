#include <SFML/Graphics.hpp>

#ifndef ENTITY
#define ENTITY

class Spaceship
{
  public:
    struct {
      sf::RectangleShape b_model;
      bool visible = false;
    } bullet;

    Spaceship( 
        sf::Event* event,
        sf::RenderWindow* window); 

  public:  
    void input(sf::Event* pevent);
    void left();
    void right();
    void shot();
    void ss_display();

  protected:
    sf::Sprite ss_model;
    sf::Event* pevent;
    sf::RenderWindow* pwindow;

  protected:
    float position[2]{};
    bool shoot = false;
};

class Alien
{
  protected:
    float position[2];
    float speed{0.05f};
    bool visible = true;
    bool direction = true;

    struct { // alien structure
      sf::Sprite sprite;
      bool visible = true;
    } a_model[40];

    struct {
      sf::RectangleShape *b_model;
      bool* visible;
    } another_b;

    sf::RenderWindow* pwindow;
    struct {
      sf::RectangleShape b_model;
      bool visible = true;
    } bullet;

  public:
    Alien(
        Spaceship &spaceship, 
        sf::RenderWindow* window);
    void movement(sf::Sprite* sprite);
    void fire();
    void a_display();
};

class Barricade
{
  public:
    struct {
      sf::RectangleShape rect;
      bool visible = true;
    } barricade[20];
    
  public:
    Barricade( sf::RenderWindow* window);
    void display_barricades();

  protected:
    sf::RenderWindow* pwindow;

  protected:
    void create_barricade(); 
};

#endif
