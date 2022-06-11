#pragma once

#include "Stan.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


class EkranMenu :public Stan {
public:
    int Start();
    int Menu(int x);
    int Zakupy();
    virtual Stany Wykonuj();
private:
    int x;
};
