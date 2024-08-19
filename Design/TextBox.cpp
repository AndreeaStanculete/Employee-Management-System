#include "TextBox.h"
#include <SFML/Graphics.hpp>

/**
 * PRIVATE
 *
 */

void TextBox::inputLogic(int charTyped) {
    if(charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY) {
        text << static_cast<char>(charTyped);
    } else if (charTyped == DELETE_KEY) {
        if(text.str().length() > 0){
            DeleteLastChar();
        }
    }
    textBox.setString(text.str() + "_");
}

void TextBox::DeleteLastChar() {
    std::string T = text.str();
    std::string newT = T.substr(0, T.length() - 1);

    // for(int i = 0; i < T.length() -1; i++)
    //     newT += T[i];

    text.str("");
    text << newT;
    textBox.setString(text.str());
}

TextBox::TextBox(float x, float y, sf::Font *font, int size, sf::Color color){
    textBox.setFont(*font);
    textBox.setPosition(sf::Vector2f(x, y));

    textBox.setCharacterSize(size);
    textBox.setColor(color);
    isSelected = false;

    textBox.setString("");

    box.setPosition(sf::Vector2f(x,y));
    box.setSize(sf::Vector2f(150, 20));
    box.setFillColor(sf::Color::Black);

}

void TextBox::setSelected(bool sel) {
    isSelected = sel;

    if(sel) {
        textBox.setString(text.str() + "_");
        box.setOutlineThickness(0);
    } else if(!sel) {
        std::string s = text.str().substr(0, text.str().length());
        textBox.setString(s);
        box.setOutlineThickness(0);
    }
}

void TextBox::typeOn(int input) {
    if(isSelected) {
        if(input < 128) {
            inputLogic(input);
        }
    }
}

void TextBox::onClick(sf::RenderWindow& Window) {
    //setSelected(false);

    if(sf::Mouse::getPosition(Window).x >= this->textBox.getPosition().x
        && sf::Mouse::getPosition(Window).x <= this->textBox.getPosition().x + 100
        && sf::Mouse::getPosition(Window).y >= this->textBox.getPosition().y
        && sf::Mouse::getPosition(Window).y <= this->textBox.getPosition().y + 20)
    {
        setSelected(true);
    }
    else
    {
        setSelected(false);
    }
}

void TextBox::update(sf::RenderWindow& Window, int v){
    if(v == 1)
        box.setOutlineColor(sf::Color::Red);
    else
        box.setOutlineColor(sf::Color::Black);
    box.setOutlineThickness(1);
}
