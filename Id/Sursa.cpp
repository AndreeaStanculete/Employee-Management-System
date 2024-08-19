#include "Identificare.h"

Identificare::~Identificare()
{

}

Identificare::Identificare() {
    CNP = "";
    Serie = "";
    Numar = 0;
}

Identificare::Identificare(const std::string& adresa, const std::string& cnp, const std::string& serie, unsigned numar) {
    Adresa = adresa;
    CNP = cnp;
    Serie = serie;

    Numar = numar;
}

Identificare & Identificare::operator = (const Identificare& x) {

    if(x.Adresa != "")
        Adresa = x.Adresa;
    if(x.CNP != "")
        CNP = x.CNP;
    if(x.Serie != "")
        Serie = x.Serie;

    if(x.Numar != 0)
        Numar = x.Numar;

    return *this;
}

unsigned Identificare::verificare(){
    if(CNP.empty())
        return 3;
    if(Serie.empty())
        return 4;
    if(Numar == 0)
        return 5;
    if(Adresa.empty())
        return 6;

    return 0;
}

bool contineCaractere(std::string const &str) {
    return str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 1234567890.,/") ==
        std::string::npos;
}

bool contineCifre(std::string const &str) {
    return str.find_first_not_of("0123456789") ==
        std::string::npos;
}

bool verificareSerie(std::string const &str){
    string S[35] = {"AX","TR","AR","XC","MM","XB","XT","BV","XR","IF","KL","KX","KT","DX","HD","VL","GG","IZ","MX","MH","HR","NT","AS","PH","SM","KV","SB","OT","TZ","TM","SV","DD","DG","TC"};
    for(int i=0; i<34; i++){
        if(S[i].compare(str)==0)
            return true;
    }
    return false;
}

bool SpatiiX(std::string const &str){
    return str.find_first_not_of (' ') == str.npos;
}

unsigned Identificare::valid(){
    if(!contineCifre(CNP))
        return 3;
    if(CNP.length() != 13)
        return 3;
    if(!verificareSerie(Serie))
        return 4;
    if(Numar < 100000 || Numar > 999999)
        return 5;

    if(!contineCaractere(Adresa))
        return 6;
    if(SpatiiX(Adresa))
        return 6;

    return 0;
}

bool Identificare::validActualizare(){
    if(!Adresa.empty() && contineCaractere(Adresa) && !SpatiiX(Adresa))
        return true;
    if(!CNP.empty() && contineCifre(CNP))
        return true;
    if(!CNP.empty() && CNP.length() == 13)
        return true;
    if(!(Numar < 100000 || Numar > 999999))
        return true;
    if(!Serie.empty() && verificareSerie(Serie))
        return true;

    return false;
}

void Identificare::afisareActual(Menu& current, sf::Font& font){

    std::string s = "CNP: " + CNP + " , " + Serie + to_string(int(Numar)) + "; Adresa: " + Adresa;
    current.addLabel(115, 108, s, &font, sf::Color::White, 15);

}

ostream & operator << (ostream& st, const Identificare& x){
    st << x.CNP << ',' << x.Serie << ',' << x.Numar << ',' << x.Adresa << '\n';
    return st;
}

istream & operator >> (istream& st, Identificare& x){
    st >> x.CNP >> x.Serie >> x.Numar >> x.Adresa;
    return st;
}
