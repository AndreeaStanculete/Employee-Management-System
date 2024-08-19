/**
 * @file Identificare.h
 * @author Stanculete Andreea <andreea.stanculete02@e-uvt.ro>
 *
 * @brief Include definitia clasei de identificare
 */

#ifndef IDENTIFICARE_H_INCLUDED
#define IDENTIFICARE_H_INCLUDED

#include <string.h>
#include <iostream>

#include "../Meniuri/Menu.h"

using namespace std;

/**
 * @brief Stocheaza datele relevante despre o persoana
 *
 * Totodata aceasta clasa permite si afisarea identificarilor
 * folosind operatorul << si citirea, folosind >> .
 */
class Identificare {
    std::string Adresa;
    std::string CNP;
    std::string Serie;

    unsigned Numar;

public:
    ~Identificare();

    /**
     * @brief Creeaza o noua identificare.
     *
     * @param CNP CNP-ul de pe un act de identitate
     * @param Serie Seria de pe actul de identitate
     * @param Numar Numarul actului de identitate
     *
     */
    Identificare();
    Identificare(const std::string&, const std::string&, const std::string&, unsigned);

    /**
     * @brief Verifica daca toate datele au fost introduse.
     */
    unsigned verificare();

    /**
     * @brief Verifica ca datele au fost introduse corect.
     */
    unsigned valid();
    bool validActualizare();

    /**
     * @brief Afiseaza datele despre un angajat
     *
     * @param current Meniu curent
     * @param font Fontul textului
     */
    void afisareActual(Menu& current, sf::Font& font);

    Identificare & operator = (const Identificare&);
    friend ostream & operator << (ostream&, const Identificare&);
    friend istream & operator >> (istream&, Identificare&);
};

#endif // IDENTIFICARE_H_INCLUDED
