#include "Konto.h"

#include <iostream>
#include <fstream>


void Konto::zaladuj(const string& lokalizacjaPliku) {
    fstream file(lokalizacjaPliku, ios::in);
    if (file) {
        file >> punkty;
        file.close();
    } else {
        cout << "Nie udalo sie odczytać danych gracza\n";
        cout << "Tworzę nowy plik zapisu\n";
        zapisz(lokalizacjaPliku);
    }
}

void Konto::zapisz(const string& lokalizacjaPliku) {
    fstream file(lokalizacjaPliku, ios::out);
    if (file.good()) {
        file << punkty << endl;
        file.close();
    } else {
        cout << "Nie udalo sie zapisac danych gracza\n";
    }
}

int Konto::zwiekszPunkty() {
    punkty++;
    return punkty;
}

int Konto::getPunkty() {
    return punkty;
}

void Konto::setPunkty(int punkty) {
    this->punkty = punkty;
}
