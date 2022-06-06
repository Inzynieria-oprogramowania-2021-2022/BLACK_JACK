#pragma once
#include "Stan.h"
#include <iostream>

class Sklep :public Stan {
    int x;
public:
    void Zakupy();
    virtual Stany Wykonuj();
};
