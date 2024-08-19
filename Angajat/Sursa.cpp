#include "Angajat.h"

Angajat::~Angajat()
{

}

Angajat::Angajat() {
    Nume = "";
    Prenume = "";
    Post = "";

    Id = Identificare();

    Salariu = 0;
}

Angajat::Angajat(const std::string& nume, const std::string& prenume, const std::string& post, Identificare& id, const double& salariu) {

    Nume = nume;
    Prenume = prenume;
    Post = post;

    Salariu = salariu;

    Id = id;
}

Angajat::Angajat(Angajat&x) {
    Nume = x.Nume;
    Prenume = x.Prenume;
    Post = x.Post;
    Salariu = x.Salariu;

    Id = x.Id;
}

void Angajat::afisare(Menu& current, sf::Font& font, const int& x){
    current.addLabel(100, x, this->Nume, &font, sf::Color::White, 15);
    current.addLabel(200, x, this->Prenume, &font, sf::Color::White, 15);
    current.addLabel(350, x, this->Post, &font, sf::Color::White, 15);

    std::string s = to_string(int(this->Salariu));
    current.addLabel(500, x, s, &font, sf::Color::White, 15);
}

void Angajat::afisareActual(Menu& current, sf::Font& font, int x){

    std::string s = Nume + " " + Prenume + ", " + Post + ", Salariu: " + to_string(int(this->Salariu));
    current.addLabel(x, 82, s, &font, sf::Color::White, 15);

    Id.afisareActual(current, font);

}

unsigned Angajat::verificare(){
    if(Nume.empty())
        return 1;
    if(Prenume.empty())
        return 2;

    unsigned i = Id.verificare();
    if(i != 0)
        return i;

    if(Post.empty())
        return 7;
    if(Salariu == 0)
        return 8;

    return 0;
}

bool contineLitere(std::string const &str) {
    return str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ") ==
        std::string::npos;
}

bool Spatii(std::string const &str){
    return str.find_first_not_of (' ') == str.npos;
}

unsigned Angajat::valid(){
    if(!contineLitere(Nume))
        return 1;
    if(Spatii(Nume))
        return 1;

    if(!contineLitere(Prenume))
        return 2;
    if(Spatii(Prenume))
        return 2;

    unsigned i = Id.valid();
    if(i != 0)
        return i;

    if(!contineLitere(Post))
        return 7;
    if(Spatii(Post))
        return 7;

    if(Salariu < 0)
        return 8;

    return 0;
}

bool Angajat::validActualizare(){
    if(!Nume.empty() && contineLitere(Nume) && !Spatii(Nume))
        return true;
    if(!Prenume.empty() && contineLitere(Prenume) && !Spatii(Prenume))
        return true;
    if(!Post.empty() && contineLitere(Post) && !Spatii(Post))
        return true;
    if(Salariu > 0)
        return true;
    if(!Id.valid())
        return true;

    return false;
}

bool Angajat::verificareCautare(){
    if(!Nume.empty())
        return true;
    if(!Prenume.empty())
        return true;
    if(!Post.empty())
        return true;
    if(Salariu != 0)
        return true;

    return false;
}

Angajat & Angajat::operator = (const Angajat& x) {

    if(x.Nume != "")
        Nume = x.Nume;
    if(x.Post != "")
        Post = x.Post;
    if(x.Prenume != "")
        Prenume = x.Prenume;

    Id = x.Id;
    if(x.Salariu != 0)
        Salariu = x.Salariu;

    return *this;
}

bool Angajat::operator > (const Angajat&x){
    if(x.Post.compare(Post) < 0)
        return true;
    else return false;
}

bool Angajat::operator == (const Angajat&x){

    if(x.Nume == "" || x.Nume.compare(Nume) == 0)
    {
        if(x.Prenume == "" || x.Prenume.compare(Prenume) == 0)
        {
            if(x.Post == "" || x.Post.compare(Post) == 0)
            {
                if(x.Salariu == 0 || x.Salariu == Salariu)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

ostream & operator << (ostream& st, const Angajat& x){
    st << x.Nume << ',' << x.Prenume << ',' << x.Post << ',' << x.Salariu << ',' << x.Id ;
    return st;
}

istream & operator >> (istream& st, Angajat& x){
    st >> x.Nume >> x.Prenume >> x.Post >> x.Salariu >> x.Id ;
    return st;
}
