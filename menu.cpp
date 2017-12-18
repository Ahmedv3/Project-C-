#include "menu.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


menu::menu()
{
	sf::Font font;
    font.loadFromFile("arial.ttf");
    Text tekst_menu;
    tekst_menu.setFont(font);
    tekst_menu.setCharacterSize(30);
    tekst_menu.setColor(sf::Color::White);
    tekst_menu.setPosition(440,30);
    tekst_menu.setString("Ping-Pong:SuperUltraTurboExtreme!!!");
}

bool menu::show(bool start)
{
	return start;
}


