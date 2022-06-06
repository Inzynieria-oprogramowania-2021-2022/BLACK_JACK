#include "EkranMenu.h"


int EkranMenu::Menu(int x) {
    switch (x)  {
    case 1://funkcja gry
        return 1;
    case 2://funkcja sklepu
        return 2;
    case 3://support
        cout << "Support\n"
            << "W celu skonsultowania sie z obsluga prosze pisac na adres barasinski@student.agh.edu.pl\n";
        return 3;
    case 4://instrukca
        cout << "Instrukcja\n";
        cout << "Walet, Dama, Kr�l � 10 punkt�w As � 1 lub 11 punkt�w, w zale�no�ci od tego, kt�ra opcja jest korzystniejsza dla gracza";
        cout << "Wi�c dla u�atwienia te karty b�d� pokazywa� si� w ten spos�b";
        return 4;
    case 5://exit
        cout << "Pa Pa";
        return 5;
    default:
        cout << "Jesli to widzisz to wystapi� jakis problem, prosz� o kontakt z supportem";
        return 6;
    }
    cin >> x;
}


Stany EkranMenu::Wykonuj() {
    cout << "Witam w BlackJacku!\n ";//jaki� opis czy co�
    cout << "Twoje Menu:\n";
    cout << "1.Rozpocznij rozgrywke.\n";
    cout << "2.Sklep.\n";
    cout << "3.Support.\n";
    cout << "4.Zasady/instrukcja.\n";
    cout << "5.Exit.\n";
    cout << "Wybierz swoja akcje: ";

    int x;
    cin >> x;

    switch (x) {
    case 1:
        return Stany::Gra;
    case 2:
        return Stany::Sklep;
    case 3:
        return Stany::Support;
    case 4:
        return Stany::Credits;
    case 5:
        return Stany::Koniec;
    default:
        cout << "Jesli to widzisz to wystapis jakis problem, prosze o kontakt z supportem";
    }
    return Stany::Koniec;
}
