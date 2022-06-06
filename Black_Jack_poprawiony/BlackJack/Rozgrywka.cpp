#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>

thread_local std::mt19937 randomGenerator{ std::random_device{}() };

#include "Rozgrywka.h"

using namespace std;

Stany Rozgrywka::Wykonuj() {
    cout << "Rozgrywka\n";
    Gracz.zaladuj();
    RozpoczecieGry();

    Gracz.zapisz();
    return Stany::Menu;
}

void Rozgrywka::Krupier() {
    while (sumaKrupier < 17) {
        int KolejnaKarta = LosowanieKarty();
        kartyKrupiera[kartaKrupier] = KolejnaKarta;
        sumaKrupier += KolejnaKarta;
        kartaKrupier++;
    }
}

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
    shuffle(begin(talia), end(talia), randomGenerator);
 }

int Rozgrywka::LosowanieKarty() {
    if (kolejna >= 52) {
        kolejna = 0;
    }
    return talia[kolejna++];
}

void Rozgrywka::Hit() {
    int KolejnaKarta = LosowanieKarty();
        
    karty[karta] = KolejnaKarta;
    suma += KolejnaKarta;
    karta++;
    int a = Podsumuj();
    Krupier();
}


void Rozgrywka::Stand() {
    Krupier();

    cout << "Karty Krupiera to:";
    for (int i = 0; i < kartaKrupier; i++) {
        cout << kartyKrupiera[i] << ",";
    }
    cout << "\nSuma: " << sumaKrupier;
    if (suma >= sumaKrupier) {
        cout << "\nWygrales!" << endl;
    } else if (sumaKrupier > 21) {
        cout << "\nWygrales!" << endl;
    } else {
        cout << "\nPrzegrales, sprobuj kolejny raz" << endl;
    }
}

void Rozgrywka::WyswietlTalie() {
    for (auto element : talia) {
        printf("%d ", element);
    } puts("");
}

void Rozgrywka::WyswietlKarty(int n) {
    cout << "Twoje Karty to:\n";
    for (int i = 0; i < n; i++) {
        cout << karty[i] << ",";
    }
    cout << endl;
}

int Rozgrywka::Podsumuj() {
    int wybor;
    //cout << "Twoje Karty to:\n";
    WyswietlKarty(karta);
    if (suma <= 20) {
        cout << "\nSuma: " << suma;
        cout << "\nDo you want to draw a new card?";
        cout << "\n1. Tak";
        cout << "\n2. Nie";
        cout << "\nWybor: ";
        cin >> wybor;
        if (wybor == 1) {
            Hit();
        } else if (wybor == 2) {
            Stand();
        } else {
            cout << "Jesli to widzisz to wystapil jakis problem, prosze o kontakt z supportem";
        }
    } else if (suma == 21) {
        cout << "\nYou've got Blackjack!\n";
        blackJack = true;
        Gracz.zwiekszPunkty();
    } else {
        cout << "\nYou're out of the game!\n";
        isAlive = false;
    }
    return 0;
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
    Podsumuj();
}




