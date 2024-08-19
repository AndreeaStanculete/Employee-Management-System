/**
 * @file Menu.h
 * @author Stanculete Andreea <andreea.stanculete02@e-uvt.ro>
 *
 * @brief Include definitia clasei Menu
 */

#ifndef CLASS_MENU_H_INCLUDED
#define CLASS_MENU_H_INCLUDED

#include "../Design/Button.h"
#include "../Design/Label.h"
#include "../Design/TextBox.h"
#include <vector>

class Menu : public sf::Drawable {
    std::vector<Label*> Labels;
    std::vector<Button*> Buttons;
    std::vector<TextBox*> Boxes;

public:
    /**
     * @brief Distruge obiectul Meniu
     *
     */
    ~Menu();

    /**
     * @brief Construieste un nou obiect Meniu
     *
     */
    Menu();

    /**
     * @brief Deseneaza continutul meniului pe fereastra.
     *
     */
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        for(Button* x : Buttons) {
            target.draw(*x, states);
        }

        for(Label* x : Labels) {
            target.draw(*x, states);
        }

        for(TextBox* x : Boxes) {
            x->DrawTo(target);
        }
    }

    /**
     * @brief Adauga un nou titlu
     *
     * @param x Coordonata x
     * @param y Coordonata Y
     * @param text Textul titlului
     * @param font Fontul textului
     * @param defaultColor Culoarea implicita
     * @param size Marimea textului
     */
    void addLabel(float x, float y, std::string text, sf::Font *font, sf::Color defaultColor, int size);

    /**
     * @brief Adauga un nou buton
     *
     * @param cod Codul butonului
     * @param x Coordonata x
     * @param y Coordonata y
     * @param height Inaltimea butonului
     * @param width Lungimea butonului
     * @param text Textul butonului
     * @param font Fontul textului
     * @param defaultColor Culoarea implicita
     * @param hoverColor Culoarea cand mouse-ul e deasupra
     * @param activeColor Culoarea cand e apasat
     */
    void addButton(int cod, float x, float y, float height, float width, std::string text, sf::Font* font,
           sf::Color defaultColor, sf::Color hoverColor, sf::Color activeColor);

    /**
     * @brief Adauga o noua caseta de text
     *
     * @param x Coordonata x
     * @param y Coordonata Y
     * @param font Fontul textului
     * @param size Dimensiunea textului
     * @param color Culoarea textului
     */
    void addTextBox(float x, float y, sf::Font *font, int size, sf::Color color);

    /**
     * @brief Goleste meniul
     *
     */
    void clear();

    /**
     * @brief Apeleaza functia de onClick a elementelor.
     *
     * @param window Fereastra
     * @return int
     */
    int onClick(sf::RenderWindow& window);

    /**
     * @brief Actualizeaza elementele
     *
     * @param window Fereastra
     */
    void update(sf::RenderWindow& window);
    void update(sf::RenderWindow& window, int v);

    /**
     * @brief Trimite cheia introdusa la toate casetele de text pentru actualizare.
     *
     * @param e Evenimentul
     */
    void passKey(sf::Event e);

    /**
     * @brief Preia textul de la o anumita caseta.
     *
     * @param index Indicele casetei
     * @return std::string
     */
    std::string getText(int index);
};

#endif // CLASS_MENU_H_INCLUDED
