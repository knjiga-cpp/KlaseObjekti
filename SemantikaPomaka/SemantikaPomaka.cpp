#include <iostream>
#include <initializer_list>
using namespace std;

class Tablica
{
private:
	static const size_t podrazumijevanaPocetnaDuljina{ 16 };
	int* elementi;
	size_t brojElemenata, duljina;
public:
	Tablica();
	Tablica(size_t pocetnaDuljina);
	Tablica(const Tablica& tablica);
	Tablica(Tablica&& tablica);
	Tablica(initializer_list<int> lista);
	void PovecajNa(size_t novaDuljina);
	void DodajElement(int noviElement);
	void BrisiElement(int pozicija);
	size_t DajBrojElemenata() { return brojElemenata; }
	int& DajElement(int indeks) { return elementi[indeks]; }
};

Tablica::Tablica()
	: Tablica(podrazumijevanaPocetnaDuljina)
{
}

Tablica::Tablica(size_t pocetnaDuljina)
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
	for (size_t i = 0; i < brojElemenata; ++i)
		elementi[i] = tablica.elementi[i];
}

Tablica::Tablica(initializer_list<int> lista)
	: elementi{ new int[lista.size()] },
	brojElemenata{ 0 },
	duljina{ lista.size() }
{
	for (const int& clan : lista)
		elementi[brojElemenata++] = clan;
}

void Tablica::PovecajNa(size_t novaDuljina)
{
	// budući da nije moguće jednostavno povećati duljinu niza,
	// moramo prvo stvoriti novi niz:
	int* noviElementi = new int[novaDuljina];
	// ... u koji ćemo preslikati elemente iz postojećeg:
	for (size_t i = 0; i < brojElemenata; ++i)
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
	for (size_t i = pozicija; i < brojElemenata - 1; ++i)
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

class ProsjekOcjena
{
private:
	Tablica ocjene;

public:
	ProsjekOcjena(const Tablica& ocjene)
		: ocjene(ocjene)
	{
	}

	//ProsjekOcjena(Tablica l)
	//	: ocjene(std::move(l))
	//{
	//}

	double Prosjek() const;
};

double ProsjekOcjena::Prosjek() const
{
	return 0.0;
}

int main()
{
	Tablica t1{ 1, 3, 5 };
	//Tablica t2 = std::move(t1);

	ProsjekOcjena pt1(t1);

	ProsjekOcjena pt2({ 5, 10, 15 });

	ProsjekOcjena pt3(Tablica(5));

	return 0;
}

