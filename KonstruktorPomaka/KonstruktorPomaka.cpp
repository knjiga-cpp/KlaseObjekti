#include <iostream>

using namespace std;

class Tablica
{
private:
	static const int podrazumijevanaPocetnaDuljina{ 16 };
	int* elementi;
	int brojElemenata, duljina;
public:
	Tablica();
	Tablica(int pocetnaDuljina);
	Tablica(const Tablica& tablica);
	Tablica(Tablica&& tablica);
	void PovecajNa(int novaDuljina);
	void DodajElement(int noviElement);
	void BrisiElement(int pozicija);
	int DajBrojElemenata() { return brojElemenata; }
	int& DajElement(int indeks) { return elementi[indeks]; }
};

Tablica::Tablica()
	: Tablica(podrazumijevanaPocetnaDuljina)
{
}

Tablica::Tablica(int pocetnaDuljina)
	: elementi{ new int[pocetnaDuljina] },
	brojElemenata{ 0 },
	duljina{ pocetnaDuljina }
{
}

Tablica::Tablica(const Tablica& tablica)
	: elementi{ new int[tablica.duljina] },
	duljina{ tablica.duljina },
	brojElemenata{ tablica.brojElemenata }
{
	for (int i = 0; i < brojElemenata; ++i)
		elementi[i] = tablica.elementi[i];
}

void Tablica::PovecajNa(int novaDuljina)
{
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
	for (auto i = pozicija; i < brojElemenata - 1; ++i)
		elementi[i] = elementi[i + 1];
	--brojElemenata;
}

Tablica::Tablica(Tablica&& tablica)
	: elementi(tablica.elementi),
	duljina(tablica.duljina),
	brojElemenata(tablica.brojElemenata)
{
	tablica.elementi = nullptr;
	tablica.duljina = 0;
	tablica.brojElemenata = 0;
}

Tablica NapuniTablicu(int n)
{
	Tablica t{ n };
	for (int i = 0; i < n; ++i)
		t.DodajElement(i);
	return t;
}

int main()
{
	Tablica t{ NapuniTablicu(100) };
    return 0; 
}

