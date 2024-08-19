#include <string>
#include <SFML/Graphics.hpp>
#include "Lista/Lista.h"
#include "Meniuri/Meniuri.h"

Lista l;
Lista k;
Lista h;
std::fstream file;

unsigned eroare = 0;
unsigned nrPagina = 1;

/**
 * @brief Asigura functionalitatea butoanelor
 *
 * @param window fereastra afectata
 * @param cod Codul unic al butonului
 */
void handle(sf::RenderWindow& window, int cod)
{
    if(cod > 300){

        k.memorareStergere(h, cod%10);

        AfisareActualizareDate(h);

    }
    else if(cod > 200) {
        Identificare id("", "", "", 0);
        Angajat temp("", "", "", id, 0);

        k.memorareStergere(h, cod%10);

        AfisareMeniuListareStergere(h);

        l.stergere(h);
        file.open("date.in", std::ios::out);
        l.writeData(file);
        file.close();

    } else {
        switch(cod) {
            case 62:
                {
                    std::string t = current.getText(4);
                    std::string t4 = current.getText(7);

                    Identificare id(current.getText(5), current.getText(2), current.getText(3), atoi(t.c_str()));
                    Angajat temp(current.getText(0), current.getText(1), current.getText(6), id, atoi(t4.c_str()));
                    eroare = 0;

                    if(temp.validActualizare()) {
                        l.modificare(k, temp);
                        file.open("date.in", std::ios::out);
                        l.writeData(file);
                        file.close();

                        AfisareMeniuPrincipal();
                    } else {
                        eroare = 5;
                    }
                }
                break;
            case 42:
                {
                    std::string t4 = current.getText(3);

                    Identificare id("", "", "", 0);
                    Angajat temp(current.getText(0), current.getText(1), current.getText(2), id, atoi(t4.c_str()));
                    eroare = 0;

                    if(temp.verificareCautare()) {
                        l.cautare(k, temp);

                        if(k.exista()){
                            if(k.numarDate()==1){
                                AfisareMeniuListareStergere(k);

                                l.stergere(k);
                                file.open("date.in", std::ios::out);
                                l.writeData(file);
                                file.close();
                            } else
                            {
                                k.sortare();
                                AfisareMeniuListare2(k, 42);
                            }
                        } else eroare = 4;
                    } else {
                        eroare = 3;
                    }
                }
                break;
            case 32:
                {
                    std::string t4 = current.getText(3);

                    Identificare id("", "", "", 0);
                    Angajat temp(current.getText(0), current.getText(1), current.getText(2), id, atoi(t4.c_str()));
                    eroare = 0;

                    if(temp.verificareCautare()) {
                        l.cautare(k, temp);

                        if(k.exista()) {
                            if(k.numarDate() == 1){
                                AfisareActualizareDate(k);
                            } else {
                                k.sortare();
                                AfisareMeniuListare2(k, 32);
                            }

                        } else {
                            eroare = 4;
                        }
                    } else {
                        eroare = 3;
                    }
                }
                break;
            case 22:
                {
                    std::string t4 = current.getText(3);

                    Identificare id("", "", "", 0);
                    Angajat temp(current.getText(0), current.getText(1), current.getText(2), id, atoi(t4.c_str()));
                    eroare = 0;

                    if(temp.verificareCautare()) {
                        l.cautare(k, temp);
                        if(k.exista()){
                             k.sortare();
                             AfisareMeniuListare(k, nrPagina, 22);
                        } else eroare = 4;

                    } else {
                        eroare = 3;
                    }
                }
                break;
            case 11:
                eroare = 0;
                k.golire();
                nrPagina = 1;
                AfisareMeniuPrincipal();
                break;
            case 12:
                {
                    std::string t = current.getText(4);
                    std::string t4 = current.getText(7);

                    Identificare id(current.getText(5), current.getText(2), current.getText(3), atoi(t.c_str()));
                    Angajat temp(current.getText(0), current.getText(1), current.getText(6), id, atoi(t4.c_str()));
                    eroare = 0;

                    unsigned v = temp.verificare();
                    if(v == 0) {
                        unsigned t = temp.valid();
                        if(t == 0) {
                            l.adaugareNod(temp);
                            file.open("date.in", std::ios::out);
                            l.writeData(file);
                            file.close();

                            AfisareMeniuPrincipal();
                        } else {
                            eroare = 1;
                            current.update(window, t-1);
                        }
                    } else {
                        eroare = 2;
                        current.update(window, v-1);
                    }
                }
                break;
            case 1:
                AfisareMeniuPrincipal();
                break;
            case 2:
                AfisareMeniuIntroducereAngajat();
                break;
            case 3:
                AfisareMeniuCautare();
                break;
            case 4:
                AfisareMeniuActualizare();
                break;
            case 5:
                AfisareMeniuStergere();
                break;
            case 6:
                l.sortare();
                AfisareMeniuListare(l, nrPagina, 6);
                break;
            case 7:
                window.close();
                break;
            case 76:
                nrPagina--;
                k.sortare();
                AfisareMeniuListare(k, nrPagina, 22);
                break;
            case 77:
                nrPagina--;
                l.sortare();
                AfisareMeniuListare(l, nrPagina, 6);
                break;
            case 88:
                nrPagina++;
                l.sortare();
                AfisareMeniuListare(l, nrPagina, 6);
                break;
            case 86:
                nrPagina++;
                k.sortare();
                AfisareMeniuListare(k, nrPagina, 22);
                break;
            default:
                break;
        }
    }
}

int main()
{
    file.open("date.in", std::ios::in);

    if(file){
        l.readData(file);
    }
    file.close();


    int cod = 0;

    sf::RenderWindow window(sf::VideoMode(750, 500), "Sistem");

    font.loadFromFile("OpenSans-Regular.ttf");

    // The default menu is the main one
    AfisareMeniuPrincipal();

    while (window.isOpen())
    {
        cod = 0;
        current.update(window);

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::TextEntered)
                current.passKey(event);
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                cod = current.onClick(window);
        }

        if(cod != 0)
        {
            handle(window, cod);
            current.update(window);
        }

        if(cod == 7)
            break;

        window.clear();
        window.draw(current);

        switch(eroare)
        {
            case 1:
                window.draw(Label(100, 350, "Datele sunt incorecte.", &font, sf::Color::White, 15));
                break;
            case 2:
                window.draw(Label(100, 350, "Completati toate campurile.", &font, sf::Color::White, 15));
                break;
            case 3:
                window.draw(Label(100, 260, "Completati cel putin un camp.", &font, sf::Color::White, 15));
                break;
            case 4:
                window.draw(Label(100, 260, "Nu a fost gasit niciun angajat.", &font, sf::Color::White, 15));
                break;
            case 5:
                window.draw(Label(100, 440, "Completati cel putin un camp.", &font, sf::Color::White, 15));
                break;
            default:
                break;
        }

        window.display();
    }

    return 0;
}
