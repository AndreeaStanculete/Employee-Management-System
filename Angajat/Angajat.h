/**
 * @file Angajat.h
 * @author Stanculete Andreea <andreea.stanculete02@e-uvt.ro>
 *
 * @brief Include definitia clasei de angajat
 */

#ifndef ANGAJAT_H_INCLUDED
#define ANGAJAT_H_INCLUDED

#include "../Id/Identificare.h"

/**
 * @brief Stocheaza datele relevante despre un angajat
 *
 * Totodata aceasta clasa permite si afisarea angajatilor
 * folosind operatorul << si citirea, folosind >> .
 */
class Angajat {
    std::string Nume;
    std::string Prenume;
    std::string Post;

    Identificare Id;

    double Salariu;

public:
    ~Angajat();

    /**
     * @brief Creeaza un nou angajat.
     *
     * @param Nume Numele angajatului
     * @param Prenume Prenumele angajatului
     * @param Post Postul angajatului
     * @param Id Detaliile de identificare ale angajatului
     * @param Salariu Salariul angajatului
     *
     */
    Angajat();
    Angajat(const string&, const string&, const string&, Identificare&, const double&);
    Angajat(Angajat&x);

    /**
     * @brief Afiseaza datele despre un angajat.
     *
     * @param current Meniul curent
     * @param font Fontul textului
     * @param x Pozitia datelor pe fereastra
     *
     */
    void afisare(Menu& current, sf::Font& font, const int& x);
    void afisareActual(Menu& current, sf::Font& font, int x);

    /**
     * @brief Verifica daca au fost introduse toate datele despre un angajat
     */
    unsigned verificare();
    bool verificareCautare();

    /**
     * @brief Verifica daca datele introduse sunt corecte.
     */
    unsigned valid();
    bool validActualizare();

    bool operator > (const Angajat&x);
    bool operator == (const Angajat&x);
    Angajat & operator = (const Angajat&);
    friend ostream & operator << (ostream&, const Angajat&);
    friend istream & operator >> (istream&, Angajat&);
};

#endif // ANGAJAT_H_INCLUDED
