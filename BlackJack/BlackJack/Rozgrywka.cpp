#include <iostream>
#include <cstdlib>
#include <ctime>

#include "BlackJack.h"
#include <algorithm>

using namespace std;


void Rozgrywka::TworzenieTalii() {
    for (int i = 0; i < 12; i++) {
        talia[i] = { 10 };
    }    
    int b = 12; 
    for (int i = 0; i < 4; i++) {
        int a = 2;
        for (int j = b; j < b + 10; j++) {
            talia[j] = a;
            a++;
        }
        b += 10;
    } 
    //sprawdzenie wyœwietlania
    /*for (int i = 0; i < 52; i++) {
        cout << talia[i] << " ";
    }
    cout << endl;*/
    random_shuffle(begin(talia), end(talia));
    
 }

    int Rozgrywka :: LosowanieKarty() {
        //int liczba = (rand() % 11) + 1;        
        int  liczba = talia[kolejna];
        kolejna++;
        return liczba;
    }
    void Rozgrywka :: hit() {
        int KolejnaKarta = LosowanieKarty();
        
        karty[karta] = KolejnaKarta;
        suma += KolejnaKarta;
        karta++;
        wyswietl();
        Krupier();

    }
    void Rozgrywka :: stand() {
        Krupier();
        //Sprawdzenie czy krupier ma wiêcej czy nie
        cout << "Karty Krupiera to:";
        for (int i = 0; i < kartaKrupier; i++) {
            cout << kartyKrupiera[i] << ",";
        }
        cout << "\nSuma: " << sumaKrupier;
        if (suma >= sumaKrupier) cout << "\nWygrales!"<<endl;
        else if(sumaKrupier > 21) cout << "\nWygrales!" << endl;
        else cout<<"\nPrzegrales, sprobuj kolejny raz"<<endl;
        EkranMenu M;
        M.Start();

    }
    void Rozgrywka :: wyswietl() {
        int wybor;
        cout << "Twoje Karty to:";
        for (int i = 0; i < karta; i++) {
            cout << karty[i] << ",";
        }
        if (suma <= 20) {
            cout << "\nSuma: " << suma;
            cout << "\nDo you want to draw a new card?";
            cout << "\n1.Tak";
            cout << "\n2.Nie";
            cout << "\nWybor: ";
            cin >> wybor;
            if (wybor == 1) hit();
            else if (wybor == 2) stand();
            else cout << "Jesli to widzisz to wystapi³ jakis problem, proszê o kontakt z supportem";
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
    void Rozgrywka::RozpoczecieGry() {
        TworzenieTalii();
        kolejna = 0;
        //gracz
        int PierwszaKarta = LosowanieKarty();        
        int DrugaKarta = LosowanieKarty(); 
        karta = 2;
        karty[0] = PierwszaKarta;
        karty[1] = DrugaKarta;
        suma = PierwszaKarta + DrugaKarta;
        //krupier
        int PierwszaKartaKrupier = LosowanieKarty();
        int DrugaKartaKrupier = LosowanieKarty();
        kartaKrupier = 2;
        kartyKrupiera[0] = PierwszaKartaKrupier;
        kartyKrupiera[1] = DrugaKartaKrupier;
        sumaKrupier = PierwszaKartaKrupier + DrugaKartaKrupier;
        wyswietl();
    }
    void Rozgrywka::Krupier() {
        if (sumaKrupier <= 16) {
            int KolejnaKarta = LosowanieKarty();
            kartyKrupiera[kartaKrupier] = KolejnaKarta;
            sumaKrupier += KolejnaKarta;
            kartaKrupier++;            
        }
       
    }

    void EkranMenu::Menu(int x) {
        Rozgrywka R;
        switch (x)
        {
        case 1://funkcja gry
            cout << "Rozgrywka\n";
            R.RozpoczecieGry();
            break;
        case 2://funkcja sklepu
            cout << "Sklep";
            break;
        case 3://support
            cout << "Suport";
            break;
        case 4://instrukca
            cout << "instrukcja";
            cout << "Walet, Dama, Król – 10 punktów As – 1 lub 11 punktów, w zale¿noœci od tego, która opcja jest korzystniejsza dla gracza";
            cout << "Wiêc dla u³atwienia te karty bêd¹ pokazywaæ siê w ten sposób";
            //ToDo.2
            break;
        case 5://exit
            cout << "Pa Pa";
            //exit;
            break;
        default:
            cout << "Jesli to widzisz to wystapi³ jakis problem, proszê o kontakt z supportem";
            break;
        }
    }

    void EkranMenu::Start() {        
        cout << "Witam w BlackJaku!\n ";//jakiœ opis czy coœ
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