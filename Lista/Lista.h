/**
 * @file Lista.h
 * @author Stanculete Andreea <andreea.stanculete02@e-uvt.ro>
 *
 * @brief Include definitia clasei lista
 */

#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <fstream>

#include "../Angajat/Angajat.h"

/**
 * @brief Stocheaza o lista de elemente
 *
 */
class Lista {
    struct Nod {
        Angajat valoare;
        Nod *next;
        Nod *prev;
    };

    Nod *prim;

    unsigned dimensiune=0;

    /**
     * @brief Sterge un nod din lista
     *
     * @param t Nodul care va fi sters
     */
    void stergereNod(Nod* t);

public:
    friend class Menu;

    /**
     * @brief Goleste toata lista inainte de a elibera memoria
     */
    ~Lista();

    /**
     * @brief Creeaza o lista goala
     */
    Lista();

    /**
     * @brief Sterge un element din lista
     *
     * @param k Stocheaza datele despre elementul care se doreste a fi sters
     * @note Lista k contine intotdeauna un singur element.
     */
    void stergere(Lista& k);

    /**
     * @brief Adauga un nou element in lista
     *
     * @param x Stocheaza datele despre elementul care se doreste a fi adaugat
     */
    void adaugareNod(const Angajat& x);

    /**
     * @brief Citeste datele din fisier
     *
     * @param file Fisierul din care vor fi citite datele
     */
    void readData(std::fstream& file);

    /**
     * @brief Scrie datele in fisier
     *
     * @param file Fisierul in care vor fi scrise datele
     */
    void writeData(std::fstream& file);

    /**
     * @brief Cauta un element in lista
     *
     * @param k Lista in care vor fi puse elementele care corespund criteriilor
     */
    void cautare(Lista& k, const Angajat& x);

    /**
     * @brief Sterge toate elementele din lista
     */
    void golire();

    /**
     * @brief Numara al catelea element trebuie sters
     *
     * @param h Lista in care sunt stocate rezultatele
     * @param codB indicele elementului
     */
    void memorareStergere(Lista& h, unsigned);

    /**
     * @brief Afiseaza elementele listei pe un ecran
     *
     * @param current Meniul pe care sa se afiseze
     * @param font Fontul textului
     */
    void afisare(Menu& current, sf::Font& font);

    /**
     * @brief Afiseaza doar anumite rezultate in functie de pagina
     *
     * Aceasta functie este folosita cand rezultatele unei cautari sunt prea multe
     * pentru a fi puse pe un singur ecran.
     *
     * @param current Meniul pe care se afiseaza
     * @param font Fontul textului
     * @param NrPagina Numarul paginii dorite
     */
    void afisare(Menu& current, sf::Font& font, unsigned& NrPagina);

    /**
     * @brief Afiseaza datele vechi despre primul nod din lista
     *
     * @param current Meniul pe care se afiseaza
     * @param font Fontul textului
     * @param x Pozitia
     */
    void afisareActualizare(Menu& current, sf::Font& font, int x);

    /**
     * @brief Verifica daca lista e goala
     *
     * @return boolean
     * @retval True lista nu e goala
     * @retval False lista e goala
     */
    bool exista();

    /**
     * @brief Returneaza numarul de elemente din lista
     *
     * @return unsigned
     * @retval dimensiunea listei
     */
    unsigned numarDate();

    /**
     * @brief Modifica primul element din lista
     *
     * @param k Lista cu un singur element ce contine vechea valoare
     * @param x noua valoare a nodului
     */
    void modificare(Lista& k, Angajat& x);

    /**
     * @brief Sorteaza lista
     */
    void sortare();
};

#endif // LISTA_H_INCLUDED
