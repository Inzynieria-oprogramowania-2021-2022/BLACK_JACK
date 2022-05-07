
#include <iostream>
#include <stdlib.h> 
#include <time.h> 
using namespace std;
/*ToDo:
1.Pasuje by była jaka pentla żeby kończyło program dopiero po kliknięciu 4
2.Zrobić w miarę sensowną instrukcję
3.losowanie poprawić
*/
int LosowanieKarty() {
    srand(time(NULL));
    int liczba = (rand() % 11) + 1;
    cout << liczba;
    return liczba;
}
void hit() {

}
void stand() {

}
int karty[];
void wyswietl() {//trzeba zrobić jakby karty były więcej od 2 i do tego funckcje jakąś bo c++ jest gównem
    cout << "Twoje Karty to:";
    for (int i = 0; i < 2; i++) {
        karty[i];
        cout << ",";
    }
    if (suma <= 20) {
        cout << "Do you want to draw a new card?";
    }
    else if (suma == 21) {
        cout << "You've got Blackjack!";
            //hasBlackJack = true
    }
    else {
        cout << "You're out of the game!";
            //isAlive = false
    }
}
int suma;
void RozpoczecieGry() {
    int PierwszaKarta = LosowanieKarty();
    cout << PierwszaKarta << "/n";
    int DrugaKarta = LosowanieKarty();
    cout << DrugaKarta;
    karty[PierwszaKarta, DrugaKarta];
    suma = PierwszaKarta + DrugaKarta;
    wyswietl();
}
int punkty;
void Menu(int x) {
    switch (x)
    {
    case 1://funkcja gry
        cout << "Rozgrywka";
        RozpoczecieGry();
        break;
    case 2://funkcja sklepu
        cout << "Sklep";
        break;
    case 3://support
        cout << "Suport";
        break;
    case 4://instrukca
        cout << "instrukcja";
        cout << "Walet, Dama, Król – 10 punktów As – 1 lub 11 punktów, w zależności od tego, która opcja jest korzystniejsza dla gracza";
        cout << "Więc dla ułatwienia te karty będą pokazywać się w ten sposób";
        //ToDo.2
        break;
    case 5://exit
        cout << "Pa Pa";
        //exit;
        break;
    default:
        cout << "Jesli to widzisz to wystapił jakis problem, proszę o kontakt z supportem";
        break;
    }
}

void Start() {
    int x;
    cout << "Witam w BlackJaku!\n ";//jakiś opis czy coś
    cout << "Twoje Menu:\n";
    cout << "1.Rozpocznij rozgrywke.\n";
    cout << "2.Sklep.\n";
    cout << "3.Support.\n";
    cout << "4.zasady/instrukcja.\n";
    cout << "5.Exit.\n";
    cout << "Wybierz swoja akcje: ";
    cin >> x;
    Menu(x);
}

int main()
{
    Start();
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
