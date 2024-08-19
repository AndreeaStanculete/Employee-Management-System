/**
 * @file TextBox.h
 * @author Stanculete Andreea <andreea.stanculete02@e-uvt.ro>
 *
 * @brief Include definitia clasei TextBox
 */

#ifndef TEXTBOX_H_INCLUDED
#define TEXTBOX_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <sstream>

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

class TextBox {
    sf::RectangleShape box;

    sf::Text textBox;
    std::ostringstream text;

    bool isSelected = false;

    /**
     * @brief Actualizeaza casuta de text cu caracterul introdus.
     *
     * @param charTyped Caracterul introdus.
     */
    void inputLogic(int charTyped);

    /**
     * @brief Sterge ultimul caracter din casuta de text.
     *
     */
    void DeleteLastChar();

    /**
     * @brief Actualizeaza casuta de text.
     *
     */
    void setSelected(bool);

public:
    /**
     * @brief Construieste o noua caseta de text.
     *
     * @param x Coordonata x
     * @param y Coordonata Y
     * @param font Fontul textului
     * @param size Dimensiunea textului
     * @param color Culoarea textului
     */
    TextBox(float x, float y, sf::Font *font, int size, sf::Color color);

    /**
     * @brief Returneaza textul introdus in caseta ca si string.
     *
     * @return std::string
     */
    std::string getText() {
        return text.str();
    }

    /**
     * @brief Deseneaza caseta de text. Echivalent cu sf::draw
     * @see sf::Drawable
     *
     * @param Window Fereastra
     */
    void DrawTo(sf::RenderTarget &Window) {
        Window.draw(box);
        Window.draw(textBox);
    }

    void update(sf::RenderWindow& Window, int v);

    /**
     * @brief Interfata pentru functia de input.
     *
     * @param input Evenimentul la care se tasteaza.
     */
    void typeOn(int input);

    /**
     * @brief Interfata pentru functia de selectare.
     *
     * @param window Fereastra
     */
    void onClick(sf::RenderWindow& window);
};

#endif // TEXTBOX_H_INCLUDED
