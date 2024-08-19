#ifndef MENIURI_H_INCLUDED
#define MENIURI_H_INCLUDED

#include "Menu.h"

sf::Font font;

Menu current;

void AfisareMeniuPrincipal(){
    current.clear();

    current.addButton(2, 100, 80, 20, 200, "  Introducere Angajat Nou", &font, sf::Color{51, 153, 102} , sf::Color{38, 115, 77} , sf::Color{19, 58, 38});
    current.addButton(3, 100, 110, 20, 200, "  Cautare Angajat", &font, sf::Color{51, 153, 102}, sf::Color{38, 115, 77}, sf::Color{19, 58, 38});
    current.addButton(4, 100, 140, 20, 200, "  Actualizare Angajat", &font, sf::Color{51, 153, 102}, sf::Color{38, 115, 77}, sf::Color{19, 58, 38});
    current.addButton(5, 100, 170, 20, 200, "  Stergere Angajat", &font, sf::Color{51, 153, 102}, sf::Color{38, 115, 77}, sf::Color{19, 58, 38});
    current.addButton(6, 100, 200, 20, 200, "  Listare Angajati", &font, sf::Color{51, 153, 102}, sf::Color{38, 115, 77}, sf::Color{19, 58, 38});
    current.addButton(7, 100, 230, 20, 200, "  Iesire", &font, sf::Color{51, 153, 102}, sf::Color{38, 115, 77}, sf::Color{19, 58, 38});

    current.addLabel(100, 50, "Sistem de Management al Angajatilor", &font, sf::Color::White, 20);
}

void AfisareMeniuIntroducereAngajat() {
    current.clear();

    current.addLabel(100, 50, "Introducere Angajat Nou", &font, sf::Color::White, 20);

    current.addLabel(100, 80, "Nume:", &font, sf::Color::White, 15);
    current.addLabel(100, 110, "Prenume:", &font, sf::Color::White, 15);
    current.addLabel(100, 140, "CNP:", &font, sf::Color::White, 15);
    current.addLabel(100, 170, "Serie buletin:", &font, sf::Color::White, 15);
    current.addLabel(100, 200, "Numar buletin:", &font, sf::Color::White, 15);
    current.addLabel(100, 230, "Adresa:", &font, sf::Color::White, 15);
    current.addLabel(100, 260, "Post ocupat:", &font, sf::Color::White, 15);
    current.addLabel(100, 290, "Salariul:", &font, sf::Color::White, 15);

    current.addTextBox(150.0f, 80.0f, &font, 15, sf::Color::White);
    current.addTextBox(175.0f, 110.0f, &font, 15, sf::Color::White);
    current.addTextBox(140.0f, 140.0f, &font, 15, sf::Color::White);
    current.addTextBox(200.0f, 170.0f, &font, 15, sf::Color::White);
    current.addTextBox(210.0f, 200.0f, &font, 15, sf::Color::White);
    current.addTextBox(160.0f, 230.0f, &font, 15, sf::Color::White);
    current.addTextBox(190.0f, 260.0f, &font, 15, sf::Color::White);
    current.addTextBox(160.0f, 290.0f, &font, 15, sf::Color::White);

    current.addButton(11, 100, 320, 20, 65, "  Inapoi", &font, sf::Color{51, 153, 102} , sf::Color{38, 115, 77} , sf::Color{19, 58, 38});
    current.addButton(12, 175, 320, 20, 75, "  Salveaza", &font, sf::Color{51, 153, 102} , sf::Color{38, 115, 77} , sf::Color{19, 58, 38});

}

void AfisareMeniuCautare() {
    current.clear();

    current.addLabel(100, 50, "Cautare Angajat", &font, sf::Color::White, 20);
    current.addLabel(100, 80, "Introduceti datele angajatului", &font, sf::Color::White, 15);

    current.addLabel(100, 110, "Nume:", &font, sf::Color::White, 15);
    current.addLabel(100, 140, "Prenume:", &font, sf::Color::White, 15);
    current.addLabel(100, 170, "Post ocupat:", &font, sf::Color::White, 15);
    current.addLabel(100, 200, "Salariul:", &font, sf::Color::White, 15);

    current.addTextBox(150.0f, 110.0f, &font, 15, sf::Color::White);
    current.addTextBox(175.0f, 140.0f, &font, 15, sf::Color::White);
    current.addTextBox(190.0f, 170.0f, &font, 15, sf::Color::White);
    current.addTextBox(160.0f, 200.0f, &font, 15, sf::Color::White);

    current.addButton(11, 100, 230, 20, 65, "  Inapoi", &font, sf::Color{51, 153, 102} , sf::Color{38, 115, 77} , sf::Color{19, 58, 38});
    current.addButton(22, 175, 230, 20, 55, "  Cauta", &font, sf::Color{51, 153, 102} , sf::Color{38, 115, 77} , sf::Color{19, 58, 38});


}

void AfisareMeniuActualizare() {
    current.clear();

    current.addLabel(100, 50, "Actualizare Angajat", &font, sf::Color::White, 20);
    current.addLabel(100, 80, "Introduceti datele angajatului", &font, sf::Color::White, 15);

    current.addLabel(100, 110, "Nume:", &font, sf::Color::White, 15);
    current.addLabel(100, 140, "Prenume:", &font, sf::Color::White, 15);
    current.addLabel(100, 170, "Post ocupat:", &font, sf::Color::White, 15);
    current.addLabel(100, 200, "Salariul:", &font, sf::Color::White, 15);

    current.addTextBox(150.0f, 110.0f, &font, 15, sf::Color::White);
    current.addTextBox(175.0f, 140.0f, &font, 15, sf::Color::White);
    current.addTextBox(190.0f, 170.0f, &font, 15, sf::Color::White);
    current.addTextBox(160.0f, 200.0f, &font, 15, sf::Color::White);

    current.addButton(11, 100, 230, 20, 65, "  Inapoi", &font, sf::Color{51, 153, 102} , sf::Color{38, 115, 77} , sf::Color{19, 58, 38});
    current.addButton(32, 175, 230, 20, 105, "  Actualizeaza", &font, sf::Color{51, 153, 102} , sf::Color{38, 115, 77} , sf::Color{19, 58, 38});

}

void AfisareActualizareDate(Lista& k) {
    current.clear();

    current.addLabel(100, 50, "Actualizare Angajat", &font, sf::Color::White, 20);

    current.addLabel(100, 80, "Angajat curent:", &font, sf::Color{153, 153, 102}, 17);
    k.afisareActualizare(current, font, 225);

    current.addLabel(100, 140, "Introduceti datele noi:", &font, sf::Color{153, 153, 102}, 17);

    current.addLabel(100, 170, "Nume:", &font, sf::Color::White, 15);
    current.addLabel(100, 200, "Prenume:", &font, sf::Color::White, 15);
    current.addLabel(100, 230, "CNP:", &font, sf::Color::White, 15);
    current.addLabel(100, 260, "Serie buletin:", &font, sf::Color::White, 15);
    current.addLabel(100, 290, "Numar buletin:", &font, sf::Color::White, 15);
    current.addLabel(100, 320, "Adresa:", &font, sf::Color::White, 15);
    current.addLabel(100, 350, "Post ocupat:", &font, sf::Color::White, 15);
    current.addLabel(100, 380, "Salariul:", &font, sf::Color::White, 15);

    current.addTextBox(150.0f, 170.0f, &font, 15, sf::Color::White);
    current.addTextBox(175.0f, 200.0f, &font, 15, sf::Color::White);
    current.addTextBox(140.0f, 230.0f, &font, 15, sf::Color::White);
    current.addTextBox(200.0f, 260.0f, &font, 15, sf::Color::White);
    current.addTextBox(210.0f, 290.0f, &font, 15, sf::Color::White);
    current.addTextBox(160.0f, 320.0f, &font, 15, sf::Color::White);
    current.addTextBox(190.0f, 350.0f, &font, 15, sf::Color::White);
    current.addTextBox(160.0f, 380.0f, &font, 15, sf::Color::White);

    current.addButton(11, 100, 410, 20, 65, "  Inapoi", &font, sf::Color{51, 153, 102} , sf::Color{38, 115, 77} , sf::Color{19, 58, 38});
    current.addButton(62, 175, 410, 20, 75, "  Salveaza", &font, sf::Color{51, 153, 102} , sf::Color{38, 115, 77} , sf::Color{19, 58, 38});

}

void AfisareMeniuStergere() {
    current.clear();

    current.addLabel(100, 50, "Stergere Angajat", &font, sf::Color::White, 20);
    current.addLabel(100, 80, "Introduceti datele angajatului", &font, sf::Color::White, 15);

    current.addLabel(100, 110, "Nume:", &font, sf::Color::White, 15);
    current.addLabel(100, 140, "Prenume:", &font, sf::Color::White, 15);
    current.addLabel(100, 170, "Post ocupat:", &font, sf::Color::White, 15);
    current.addLabel(100, 200, "Salariul:", &font, sf::Color::White, 15);

    current.addTextBox(150.0f, 110.0f, &font, 15, sf::Color::White);
    current.addTextBox(175.0f, 140.0f, &font, 15, sf::Color::White);
    current.addTextBox(190.0f, 170.0f, &font, 15, sf::Color::White);
    current.addTextBox(160.0f, 200.0f, &font, 15, sf::Color::White);

    current.addButton(11, 100, 230, 20, 65, "  Inapoi", &font, sf::Color{51, 153, 102} , sf::Color{38, 115, 77} , sf::Color{19, 58, 38});
    current.addButton(42, 175, 230, 20, 65, "  Sterge", &font, sf::Color{51, 153, 102} , sf::Color{38, 115, 77} , sf::Color{19, 58, 38});
}

void AfisareMeniuListareStergere(Lista&x){
    current.clear();

    current.addLabel(100, 50, "Stergere Angajat", &font, sf::Color::White, 20);

    current.addLabel(100, 80, "A fost sters angajatul:", &font, sf::Color{153, 153, 102}, 17);
    x.afisareActualizare(current, font, 275);

    current.addButton(11, 100, 140, 20, 65, "  Inapoi", &font, sf::Color{51, 153, 102} , sf::Color{38, 115, 77} , sf::Color{19, 58, 38});
}

void AfisareMeniuListare(Lista&x, unsigned& NrPagina, unsigned cod) {
    current.clear();

    current.addLabel(100, 50, "Listare Angajati", &font, sf::Color::White, 20);
    current.addButton(11, 100, 80, 20, 65, "  Inapoi", &font, sf::Color{51, 153, 102} , sf::Color{38, 115, 77} , sf::Color{19, 58, 38});

    if(x.exista()) {
        current.addLabel(100, 110, "Nume", &font, sf::Color::White, 15);
        current.addLabel(200, 110, "Prenume", &font, sf::Color::White, 15);
        current.addLabel(350, 110, "Post", &font, sf::Color::White, 15);
        current.addLabel(500, 110, "Salariu", &font, sf::Color::White, 15);

        current.addLabel(100, 120, "----------------------------------------------------------------------------", &font, sf::Color::White, 15);

        int lungime = x.numarDate();
        if(lungime > 8 ){
                int c1, c2;
                if(cod == 22){
                    c1 = 76; c2 = 86;
                } else if(cod == 6) {
                    c1 = 77; c2 = 88;
                }

                std::string s = to_string(int(NrPagina));
                current.addLabel(300, 380, s, &font, sf::Color::White, 20);

                int dif = lungime - 8*NrPagina;

                if(NrPagina == 1) {
                    current.addButton(c2, 330, 382, 20, 27, " >> ", &font, sf::Color{51, 153, 102} , sf::Color{38, 115, 77} , sf::Color{19, 58, 38});
                } else if (dif <= 0) {
                    current.addButton(c1, 250, 382, 20, 27, " << ", &font, sf::Color{51, 153, 102} , sf::Color{38, 115, 77} , sf::Color{19, 58, 38});
                } else if (dif > 0) {

                    current.addButton(c1, 250, 382, 20, 27, " << ", &font, sf::Color{51, 153, 102} , sf::Color{38, 115, 77} , sf::Color{19, 58, 38});
                    current.addButton(c2, 330, 382, 20, 27, " >> ", &font, sf::Color{51, 153, 102} , sf::Color{38, 115, 77} , sf::Color{19, 58, 38});
                }

                x.afisare(current, font, NrPagina);

        } else x.afisare(current, font);

    } else {
        current.addLabel(100, 110, "Nu exista angajati de afisat.", &font, sf::Color::White, 15);
    }


}

void AfisareMeniuListare2(Lista&x, unsigned cod) {
    current.clear();

    current.addLabel(100, 50, "Actualizare Angajati", &font, sf::Color::White, 20);
    current.addButton(11, 100, 80, 20, 65, "  Inapoi", &font, sf::Color{51, 153, 102} , sf::Color{38, 115, 77} , sf::Color{19, 58, 38});

    if(x.exista()) {

        current.addLabel(100, 110, "Nume", &font, sf::Color::White, 15);
        current.addLabel(200, 110, "Prenume", &font, sf::Color::White, 15);
        current.addLabel(350, 110, "Post", &font, sf::Color::White, 15);
        current.addLabel(500, 110, "Salariu", &font, sf::Color::White, 15);

        current.addLabel(100, 120, "----------------------------------------------------------------------------", &font, sf::Color::White, 15);

        x.afisare(current, font);

        unsigned lungime = x.numarDate();
        unsigned pozitie = 140;
        unsigned codB;

        if(cod == 32) {
            codB = 301;

            for(unsigned i = 0; i < lungime; i++){
                current.addButton(codB, 70, pozitie, 20, 20, " O ", &font, sf::Color{0, 102, 153} , sf::Color{0, 85, 128} , sf::Color{0, 68, 102});
                pozitie += 30;
                codB++;
            }
        }
        else if(cod == 42){
            codB = 201;

            for(unsigned i = 0; i < lungime; i++){
                current.addButton(codB, 70, pozitie, 20, 18, " X ", &font, sf::Color{179, 0, 0} , sf::Color{153, 0, 0} , sf::Color{128, 0, 0});
                pozitie += 30;
                codB++;
            }
        }

    }


}


#endif // MENIURI_H_INCLUDED
