#include <iostream>
#include"Credits.h"
#include"Stan.h"

Stany Credits :: Wykonuj() {
	std::cout<< "Instrukcja\n"
    << "Walet, Dama, Krol - 10 punktow As - 11 punktow. " //1 lub 11 punkt�w, w zaleznosci od tego, ktora opcja jest korzystniejsza dla gracza";
    << "Wiec dla ulatwienia te karty beda pokazywac sie w ten sposob\n\n";
    return Stany::Menu;
}
