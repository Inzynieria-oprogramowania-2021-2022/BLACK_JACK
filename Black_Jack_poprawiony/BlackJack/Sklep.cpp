#include "Sklep.h"

using namespace std;

void Sklep::Zakupy() {
    if (Gracz.getPunkty() >= 5) {
        int x = Gracz.getPunkty();
        x -= 5;
        Gracz.setPunkty(x);
        Gracz.zapisz();
    }
    else
        cout << "Masz za malo punktow\n";
}


Stany Sklep::Wykonuj() {
    Gracz.zaladuj();
    cout << "Sklep\n" << 
    "Twoje punkty: " << Gracz.getPunkty()<< "\n";
    cout << "1. Zamiana 5 punktow na bonus.\n"
         << "3. Opusc sklep.\n";
    cout << "Wybierz akcje: ";

    int x;
    cin >> x;

    switch (x) {
    case 1:
        // dodaj bonus czy coś
        Zakupy();
        break;
    case 3:
        return Stany::Menu;
    }

    return Stany::Sklep;
}
