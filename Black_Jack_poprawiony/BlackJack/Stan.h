#pragma once

enum class Stany {
	Menu = 0,
	Gra,
	Sklep,
	Credits,
	Support,
	Koniec
};


class Stan {
public:
	virtual Stany Wykonuj() = 0;
private:
};

