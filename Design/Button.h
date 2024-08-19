/**
 * @file Button.h
 * @author Stanculete Andreea <andreea.stanculete02@e-uvt.ro>
 *
 * @brief Include definitia clasei de buton
 */

#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>

class Button : public sf::Drawable{
    sf::RectangleShape box;

    sf::Text text;
    sf::Font* font;

    sf::Color defaultColor;
    sf::Color hoverColor;
    sf::Color activeColor;

    int cod;
    int isHover;

public:
    /**
     * @brief Construieste un nou buton
     *
     * @param cod Codul butonului
     * @param x Coordonata x
     * @param y Coordonata Y
     * @param height Inaltimea butonului
     * @param width Lungimea butonului
     * @param text Textul butonului
     * @param font Fontul textului
     * @param defaultColor Culoarea implicita
     * @param hoverColor Culoarea cand mouse-ul e deasupra
     * @param activeColor Culoarea cand e apasat
     */
    Button(int cod, float x, float y, float height, float width, std::string text, sf::Font* font,
           sf::Color defaultColor, sf::Color hoverColor, sf::Color activeColor);

    /**
     * @brief Actualizeaza butonul
     *
     * @param Window Fereastra
     */
    void update(sf::RenderWindow& Window);

    /**
     * @brief Returneaza codul butonului sau 0
     *
     * @return int
     */
    int onClick();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(box);
        target.draw(text);
    }
};

#endif // BUTTON_H_INCLUDED
