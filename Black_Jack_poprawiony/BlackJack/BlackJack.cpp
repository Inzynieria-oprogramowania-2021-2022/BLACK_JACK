#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

#include "Rozgrywka.h"
#include "Sklep.h"
#include "Konto.h"
#include "Stan.h"
#include "EkranMenu.h"

using namespace std;
/*ToDo:
* 1.Stand();
  2.Zrobić w miarę sensowną instrukcję
*/


int main() {
    Stan* stan = new EkranMenu();
    while (stan) {
        Stany nowyStan = stan->Wykonuj();
        delete stan;

        switch (nowyStan) {
        case Stany::Menu:
            stan = new EkranMenu; break;
        case Stany::Sklep:
            stan = new Sklep; break;
        case Stany::Gra:
            stan = new Rozgrywka; break;
        case Stany::Support:
            stan = nullptr; break;
        case Stany::Credits:
            stan = nullptr; break;
        case Stany::Koniec:
            stan = nullptr; break;
        default:
            stan = nullptr; break;
        }
    }
    std::cout << "Koniec\n";

    return 0;
}
