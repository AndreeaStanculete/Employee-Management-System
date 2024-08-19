#include "Label.h"

Label::Label(float x, float y, std::string text, sf::Font *font, sf::Color defaultColor, int size) {
    this->font = font;
    this->defaultColor = defaultColor;

    this->text.setPosition(sf::Vector2f(x, y));
    this->text.setFont(*this->font);
    this->text.setString(text);
    this->text.setCharacterSize(size);
    this->text.setFillColor(defaultColor);
}
