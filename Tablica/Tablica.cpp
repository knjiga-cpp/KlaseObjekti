#include <iostream>
#include <cassert>            // deklaracija funkcije assert
using namespace std;

class Tablica
{
private:
	const int podrazumijevanaPocetnaDuljina{ 16 };
	int* elementi;
	int brojElemenata, duljina;
public:
	Tablica();
	Tablica(int pocetnaDuljina);
	void PovecajNa(int novaDuljina);
	void DodajElement(int noviElement);
	void BrisiElement(int pozicija);
};

//Tablica::Tablica()
//	: elementi{ new int[podrazumijevanaPocetnaDuljina] },
//	brojElemenata{ 0 },
//	duljina{ podrazumijevanaPocetnaDuljina }
//{
//	assert(elementi != nullptr);        // provjera uspješnosti operacije
//}
//
//Tablica::Tablica(int pocetnaDuljina)
//	: elementi{ new int[pocetnaDuljina] },
//	brojElemenata{ 0 },
//	duljina{ pocetnaDuljina }
//{
//	assert(elementi != nullptr);		// provjera uspješnosti operacije
//}

Tablica::Tablica()
	: Tablica{ podrazumijevanaPocetnaDuljina }
{
}

Tablica::Tablica(int pocetnaDuljina)
	: elementi{ new int[pocetnaDuljina] },
	brojElemenata{ 0 },
	duljina{ pocetnaDuljina }
{
	assert(elementi != nullptr);
}

void Tablica::PovecajNa(int novaDuljina)
{
	assert(novaDuljina > duljina);    // provjera ispravnosti argumenta
	// budući da nije moguće jednostavno povećati duljinu niza,
	// moramo prvo stvoriti novi niz:
	int* noviElementi = new int[novaDuljina];
	// ... u koji ćemo preslikati elemente iz postojećeg:
	for (auto i = 0; i < brojElemenata; ++i)
		noviElementi[i] = elementi[i];
	// oslobodimo prostor starog niza:
	delete[] elementi;
	// ažuriramo članove klase:
	elementi = noviElementi;
	duljina = novaDuljina;
}

void Tablica::DodajElement(int noviElement)
{
	if (duljina == brojElemenata)        // ako nema više mjesta...
		PovecajNa(duljina * 2);            // udvostručimo duljinu
	elementi[brojElemenata++] = noviElement;
}

void Tablica::BrisiElement(int pozicija)
{
	assert(pozicija < brojElemenata); // provjera ispravnosti argumenta
	for (auto i = pozicija; i < brojElemenata - 1; ++i)
		elementi[i] = elementi[i + 1];
	--brojElemenata;
}


int main()
{
    std::cout << "Hello World!\n"; 
}

