#include "Menu.h"

Menu:: ~Menu() {
    for(Button* x : Buttons) {
        delete x;
    }

    for(Label* x : Labels) {
        delete x;
    }

    for(TextBox* x : Boxes) {
        delete x;
    }
}

Menu::Menu() {

}

void Menu::addLabel(float x, float y, std::string text, sf::Font *font, sf::Color defaultColor, int size){
    Labels.push_back(new Label(x,y,text,font,defaultColor,size));
}

void Menu::clear() {
    for(Button* x : Buttons) {
        delete x;
    }

    for(Label* x : Labels) {
        delete x;
    }

    for(TextBox* x : Boxes) {
        delete x;
    }

    Buttons.clear();
    Labels.clear();
    Boxes.clear();
}

void Menu::addButton(int cod, float x, float y, float height, float width, std::string text, sf::Font* font,
           sf::Color defaultColor, sf::Color hoverColor, sf::Color activeColor) {
    Buttons.push_back(new Button(cod,x,y,height,width,text,font,defaultColor,hoverColor,activeColor));
}

void Menu::addTextBox(float x, float y, sf::Font* font, int size, sf::Color color) {
    Boxes.push_back(new TextBox(x,y,font,size,color));
}

void Menu::update(sf::RenderWindow& window)
{
    for(Button* x : Buttons) {
        x->update(window);
    }
}

void Menu::update(sf::RenderWindow& window, int v)
{
    for(Button* x : Buttons) {
        x->update(window);
    }

    for(TextBox* x : Boxes) {
        x->update(window, 0);
    }

    Boxes.at(v)->update(window, 1);
}


int Menu::onClick(sf::RenderWindow& window)
{
    int sum = 0;

    for(Button* x : Buttons) {
        sum += x->onClick();
    }

    for(TextBox* x : Boxes) {
        x->onClick(window);
    }

    return sum;
}

void Menu::passKey(sf::Event e)
{
    for(TextBox* x : Boxes) {
        x->typeOn(e.text.unicode);
    }
}

std::string Menu::getText(int index) {
    return Boxes.at(index)->getText();
}
