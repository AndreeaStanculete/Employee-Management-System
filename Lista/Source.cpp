#include "Lista.h"

Lista::~Lista() {
    while(prim != NULL) {
        stergereNod(prim);
    }
}

Lista::Lista() {
    prim = NULL;
    dimensiune = 0;
}

void Lista::readData(std::fstream&file){
    std::string Nume;
    while(std::getline(file, Nume, ',')){

        std::string Prenume; std::getline(file, Prenume, ',');
        std::string Post; std::getline(file, Post, ',');
        std::string Salariu; std::getline(file, Salariu, ',');

        std::string CNP; std::getline(file, CNP, ',');
        std::string Serie; std::getline(file, Serie, ',');
        std::string Numar; std::getline(file, Numar, ',');
        std::string Adresa; std::getline(file, Adresa, '\n');

        Identificare id(Adresa, CNP, Serie, atoi(Numar.c_str()));
        Angajat temp(Nume, Prenume, Post, id, atoi(Salariu.c_str()));

        this->adaugareNod(temp);
    }
}

void Lista::writeData(std::fstream&file){
    Nod *p = this->prim;
    for(unsigned i=0; i<dimensiune; i++){
        file << p->valoare;
        p = p->next;
    }
}

void Lista::stergereNod(Nod* t){
    if(prim == t) {
        prim = t->next;
    }

    if(t->prev != NULL) {
        t->prev->next = t->next;
    }

    if(t->next != NULL) {
        t->next->prev = t->prev;
    }

    t->prev = NULL;
    t->next = NULL;
    delete t;

    dimensiune--;
}

void Lista::stergere(Lista& k){
    Nod *p = this->prim;
    Nod *t = k.prim;

    while(p != NULL){
        if(p->valoare == t->valoare){
            stergereNod(p);
            break;
        }
        p = p->next;
    }
}

void Lista::adaugareNod(const Angajat& x) {
    Nod* p = new Nod;

    p->valoare = x;
    p->next = NULL;
    p->prev = NULL;

    if(this->prim == NULL) {
        this->prim = p;
    }
    else {
        p->next = this->prim;
        this->prim->prev = p;
        this->prim = p;
    }

    dimensiune++;
}

void Lista::cautare(Lista& k, const Angajat& x) {
    Nod *p = this->prim;
    while(p != NULL)
    {
        if(p->valoare == x){
            k.adaugareNod(p->valoare);
        }
        p = p->next;
    }
}

void Lista::golire(){
    while(this->prim != NULL){
        this->stergereNod(this->prim);
    }
}

void Lista::afisare(Menu& current, sf::Font& font){
    Nod *p = this->prim;
    int x = 140;

    while(p != NULL)
    {
        p->valoare.afisare(current, font, x);
        x += 30;
        p = p->next;
    }
}

void Lista::afisare(Menu& current, sf::Font& font, unsigned& NrPagina){
    Nod *p = this->prim;
    int x = 140;

    unsigned nr = 1;
    unsigned nrAfisari;

    switch(NrPagina){
        case 1:
            nrAfisari = 1;
            break;
        case 2:
            nrAfisari = 9;
            break;
        case 3:
            nrAfisari = 17;
            break;
        case 4:
            nrAfisari = 25;
            break;
        default:
            nrAfisari = 1;
            break;
    }

    while(p != NULL && nr < nrAfisari)
    {
        p = p->next;
        nr++;
    }

    nr = 1;
    while(p != NULL && nr < 9)
    {
        p->valoare.afisare(current, font, x);
        x += 30;
        nr++;
        p = p->next;
    }
}

void Lista::afisareActualizare(Menu& current, sf::Font& font, int x){
    Nod *p = this->prim;
    p->valoare.afisareActual(current, font, x);
}

bool Lista::exista(){
    if(this->prim != NULL)
        return true;
    else return false;
}

unsigned Lista::numarDate(){
    unsigned nr = 0;
    Nod *p = this->prim;

    while(p != NULL){
        nr++;
        p = p->next;
    }
    return nr;
}

void Lista::modificare(Lista& k, Angajat& x){
    Nod *p = this->prim;
    Nod *t = k.prim;

    while(p != NULL){

        if(p->valoare == t->valoare){
            p->valoare = x;
            break;
        }
        p = p->next;
    }
}

void Lista::memorareStergere(Lista& h, unsigned codB){
    Nod *p = this->prim;
    unsigned nr = 1;

    while(p != NULL){
        if(nr == codB){
            h.adaugareNod(p->valoare);
            break;
        }
        nr++;
        p = p->next;
    }
}

void Lista::sortare(){
    if(this->prim != NULL){
        Nod *p = this->prim;

        while(p != NULL && p->next != NULL){
            Nod *t = p->next;

            while(t != NULL){
                if(p->valoare > t->valoare){
                    Angajat aux;
                    aux = p->valoare ;
                    p->valoare = t->valoare;
                    t->valoare = aux;
                }
                t = t->next;
            }

            p = p->next;
        }
    }
}
