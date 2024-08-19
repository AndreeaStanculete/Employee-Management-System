/**
 * @file Label.h
 * @author Stanculete Andreea <andreea.stanculete02@e-uvt.ro>
 *
 * @brief Include definitia clasei de label
 */

#ifndef LABEL_H_INCLUDED
#define LABEL_H_INCLUDED

#include <SFML/Graphics.hpp>

class Label : public sf::Drawable {

    sf::Text text;
    sf::Font* font;
    sf::Color defaultColor;

public:
    /**
     * @brief Construieste un nou Titlu
     *
     * @param x Coordonata x
     * @param y Coordonata Y
     * @param text Textul butonului
     * @param font Fontul textului
     * @param defaultColor Culoarea implicita
     * @param size Dimensiunea textului
     */
    Label(float x, float y, std::string text, sf::Font *font, sf::Color defaultColor, int size);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(text);
    }
};

#endif // LABEL_H_INCLUDED
