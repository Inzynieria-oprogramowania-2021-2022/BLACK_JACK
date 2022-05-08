
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
/*ToDo:
* 1.Stand();
2.Zrobić w miarę sensowną instrukcję
*/
int karty[5];
int suma;
bool isAlive = false;
bool BlackJack = false;
int LosowanieKarty() {
    int liczba = (rand() % 11) + 1;
    return liczba;
}
void hit() {
    int KolejnaKarta = LosowanieKarty();
    karty[3] = KolejnaKarta;//zrobić by było i w sensie wiadomo o co mi cho
    wyswietl();
    
}
void stand() {
    //Sprawdzenie czy krupier ma więcej czy nie 
}
void wyswietl() {
    int wybor;
    cout << "Twoje Karty to:";
    for (int i = 0; i < 2; i++) {
        cout<<karty[i]<< ","; 
    }
    if (suma <= 20) {
        cout << "\nSuma: " << suma;
        cout << "\nDo you want to draw a new card?";
        cout << "\n1.Tak";
        cout << "\n1.Nie";
        cout << "\nWybor: ";
        cin >> wybor;
        if (wybor == 1) hit();
        else if (wybor == 2) stand();
        else cout << "Jesli to widzisz to wystapił jakis problem, proszę o kontakt z supportem";
    }
    else if (suma == 21) {
        cout << "\nYou've got Blackjack!";
        BlackJack = true;
    }
    else {
        cout << "\nYou're out of the game!";
        isAlive = false;
    }
}
void RozpoczecieGry() {
    int PierwszaKarta = LosowanieKarty();
    int DrugaKarta = LosowanieKarty();
    karty[0] = PierwszaKarta;
    karty[1] = DrugaKarta;
    suma = PierwszaKarta + DrugaKarta;
    wyswietl();
}

int punkty;
void Menu(int x) {
    switch (x)
    {
    case 1://funkcja gry
        cout << "Rozgrywka\n";
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
    srand(time(NULL));
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
