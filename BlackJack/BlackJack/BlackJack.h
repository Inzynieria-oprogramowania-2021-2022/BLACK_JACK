//klasy do Black Jacka
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class EkranMenu;
class Rozgrywka {
    int karty[5];
    int talia[52];
    int kartyKrupiera[5];
    int suma;
    int sumaKrupier;
    int karta;
    int kartaKrupier;
    int kolejna;
    bool isAlive = false;
    bool BlackJack = false;
public:
    friend class EkranMenu;    
    void TworzenieTalii();
    int LosowanieKarty();
    void hit();
    void stand();
    void wyswietl();
    void RozpoczecieGry();
    void Krupier();
};
class EkranMenu {
    int x;
public:
    friend class Rozgrywka;
    friend class Sklep;
    //friend void RozpoczecieGry();
    void Start();
    void Menu(int x);

};
class Sklep {
    int x;
public:
    void Zakupy();
};