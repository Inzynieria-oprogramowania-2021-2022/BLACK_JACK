#include "Sklep.h"

using namespace std;

void Sklep::Zakupy() {

}


Stany Sklep::Wykonuj() {
    cout << "Sklep\n";
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
