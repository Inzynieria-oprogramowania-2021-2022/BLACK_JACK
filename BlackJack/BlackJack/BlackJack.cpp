
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

#include "BlackJack.h"
using namespace std;
/*ToDo:
* 1.Stand();
2.Zrobić w miarę sensowną instrukcję
*/
int punkty;

int main()
{
    Konto G;
    
    fstream file;
    file.open("gracz.txt", ios::in);
    if (!file) {
        file.open("gracz.txt", ios::out);
        file << punkty << endl;
        file.close();
    }
    file >> punkty;
    file.close();
    G.punkty = punkty;
    //srand(time(NULL));
    EkranMenu  Menu;
    Menu.Start();
    file.open("gracz.txt", ios::out);
    if (!file) {
        cout << "Błąd w utworzeniu konta" << endl;
        return 0;
    }
    punkty = G.punkty;
    file << punkty << endl;
    file.close();
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

