#pragma once
#include "Stan.h"
#include "Konto.h"
#include <iostream>

class Sklep :public Stan {
    int x;
    Konto Gracz;
public:
    void Zakupy();
    virtual Stany Wykonuj();
};
