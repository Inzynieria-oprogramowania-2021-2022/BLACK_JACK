#pragma once

#include <string>

using namespace std;

class Konto {
public:
    Konto()
        : punkty(0) {

    }
    void zaladuj(const string& lokalizacjaPliku = "gracz.txt");
    void zapisz(const string& lokalizacjaPliku = "gracz.txt");
    int zwiekszPunkty();

    int getPunkty();
    void setPunkty(int punkty);
private:
    int punkty;
};