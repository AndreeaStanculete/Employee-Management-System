#include "Button.h"

Button::Button(int cod, float x, float y, float height, float width, std::string text, sf::Font* font,
       sf::Color defaultColor, sf::Color hoverColor, sf::Color activeColor)
{
    this->cod = cod;

    this->box.setPosition(sf::Vector2f(x, y));
    this->box.setSize(sf::Vector2f(width, height));

    this->font = font;
    this->text.setFont(*this->font);
    this->text.setString(text);
    this->text.setCharacterSize(15);
    this->text.setFillColor(sf::Color::White);
    this->text.setPosition(sf::Vector2f(x, y));
    /*this->text.setPosition(
            this->box.getPosition().x /2.f - this->text.getGlobalBounds().width /2.f,
            this->box.getPosition().y /2.f - this->text.getGlobalBounds().height /2.f
        );*/

    this->defaultColor = defaultColor;
    this->hoverColor = hoverColor;
    this->activeColor = activeColor;

    this->box.setFillColor(this->defaultColor);
}


void Button::update(sf::RenderWindow& Window){
    //if(this->box.getGlobalBounds().contains((Window.mapPixelToCoords(sf::Mouse::getPosition(Window)))))
    if(sf::Mouse::getPosition(Window).x >= this->box.getPosition().x
        && sf::Mouse::getPosition(Window).x <= this->box.getPosition().x + this->box.getSize().x
        && sf::Mouse::getPosition(Window).y >= this->box.getPosition().y
        && sf::Mouse::getPosition(Window).y <= this->box.getPosition().y + this->box.getSize().y)
    {
        this->box.setFillColor(this->hoverColor);
        isHover = 1;
    } else {
        this->box.setFillColor(this->defaultColor);
        isHover = 0;
    }
}

int Button::onClick() {
    if(isHover == 1) {
        this->box.setFillColor(this->activeColor);
        return cod;
    }
    return 0;
}
