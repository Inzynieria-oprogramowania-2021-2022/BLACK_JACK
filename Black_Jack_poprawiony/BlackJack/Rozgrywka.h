#pragma once

#include "Stan.h"
#include "Konto.h"

class Rozgrywka :public Stan {
public:
    Rozgrywka()
        : karta(0)
        , suma(0)
        , sumaKrupier(0)
        , kartaKrupier(0)
        , kolejna(0)
        , karty()
        , kartyKrupiera()
        , talia()
    {
    }

    void TworzenieTalii();
    int LosowanieKarty();
    void WyswietlTalie();
    void WyswietlKarty(int n);
    
    void Hit();
    void Stand();

    int Podsumuj();

    void Krupier();
    void RozpoczecieGry();

    virtual Stany Wykonuj();
    
private:
    Konto Gracz;

    int karty[5] = { 0 };
    int talia[52] = { 0 };
    int kartyKrupiera[5] = { 0 };
    int suma;
    int sumaKrupier;
    int karta;
    int kartaKrupier;
    int kolejna;
    bool isAlive = true;
    bool blackJack = false;
};