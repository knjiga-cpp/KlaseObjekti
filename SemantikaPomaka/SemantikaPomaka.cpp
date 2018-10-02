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

void Tablica::PovecajNa(int novaDuljina)
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

int main()
{
	Tablica t1 = Tablica{ 1, 3, 5 };
	Tablica t2 = std::move(t1);

	std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
