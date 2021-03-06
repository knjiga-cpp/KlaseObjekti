#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MemorijskiAlokator
{
private:
	// definicija ugniježđene klase:
	class Alokacija
	{
	private:
		void* adresa{ nullptr };     // adresa početka bloka
		size_t velicina{ 0 };        // veličina alokacije
		string datoteka;             // ime datoteke
		int linija{ 0 };             // redni broj linije u kôdu
	public:
		Alokacija(void* adr, size_t vel, const char* dat, int lin);
		void Ispisi() const;
		void* DajAdresu() const { return adresa; }
	};

	vector<Alokacija> alokacije;
public:
	~MemorijskiAlokator();
	void Dodaj(void* adr, size_t vel, const char* dat, int lin);
	void Brisi(void* adr);
	void Ispisi() const;
};

// definicije članova ugnježđene klase Alokacija:
MemorijskiAlokator::Alokacija::Alokacija(void* adr, size_t vel,
	const char* dat, int lin)
	: adresa{ adr }, velicina{ vel }, datoteka{ dat }, linija{ lin }
{
}

void MemorijskiAlokator::Alokacija::Ispisi() const
{
	cout << datoteka << ": Ln " << linija << " = " << velicina;
	cout << " : " << adresa << endl;
}

// destruktor ispisuje sve neoslobođene alokacije:
MemorijskiAlokator::~MemorijskiAlokator()
{
	cout << "Neoslobođene alokacije:" << endl;
	Ispisi();
}

void MemorijskiAlokator::Dodaj(void* adr, size_t vel,
	const char* dat, int lin)
{
	alokacije.push_back(Alokacija{ adr, vel, dat, lin });
}

void MemorijskiAlokator::Brisi(void* adr)
{
	// traži alokaciju koja pokazuje na proslijeđenu memorijsku adresu
	for (auto it = alokacije.begin(); it != alokacije.end(); ++it)
	{
		if ((*it).DajAdresu() == adr)
		{
			alokacije.erase(it);         // briše pronađenu alokaciju
			return;
		}
	}
}

void MemorijskiAlokator::Ispisi() const
{
	// ispisuje trenutno neoslobođene alokacije
	for (const Alokacija& alok : alokacije)
		alok.Ispisi();
}

int main()
{
	return 0;
}
