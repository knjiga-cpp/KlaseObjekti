#include <iostream>
#include <vector>

using namespace std;

class Vektor;		// deklaracija unaprijed

class Matrica
{
private:
	double a11, a12, a21, a22;
public:
	// ...
	Vektor MnoziVektorom(const Vektor& v);
};

class Vektor
{
	// proglašavamo član druge klase prijateljem:
	friend Vektor Matrica::MnoziVektorom(const Vektor& v);
	// prijateljska umetnuta funkcija:
	friend Vektor ZbrojiVektore(const Vektor& a, const Vektor& b)
	{
		Vektor c;
		c.ax = a.ax + b.ax;
		c.ay = a.ay + b.ay;
		return c;
	}

private:
	double ax, ay;
public:

	// deklaracija i definicija prvog (praznog) konstruktora:
	//Vektor() { ax = 0; ay = 0; }
	//// deklaracija drugog konstruktora:
	//Vektor(double x, double y);

	Vektor(const Vektor& refVektor)
		: ax(refVektor.ax), ay(refVektor.ay)
	{}

	constexpr Vektor() : ax{ 0 }, ay{ 0 } {}
	constexpr Vektor(double x, double y) : ax{ x }, ay{ y } {}

	void PostaviXY(double x, double y) { ax = x; ay = y; }

	double DajX() const noexcept { return ax; }

	double DajY() const noexcept { return ay; }

	void MnoziSkalarom(double skalar)
	{
		ax *= skalar;
		ay *= skalar;
	}
};

//Vektor::Vektor(double x, double y)
//{
//	ax = x;
//	ay = y;
//}

Vektor Matrica::MnoziVektorom(const Vektor& v)
{
	Vektor rez;
	rez.ax = a11 * v.ax + a12 * v.ay;
	rez.ay = a21 * v.ax + a22 * v.ay;
	return rez;
}

class TablicaSeNeDaKopirati
{
	// ...
private:
	// onemogućavamo generiranje konstruktora kopije:
	TablicaSeNeDaKopirati(const TablicaSeNeDaKopirati&) = delete;
	// onemogućavamo generiranje operatora pridruživanja:
	TablicaSeNeDaKopirati& operator=(const TablicaSeNeDaKopirati&)
		= delete;
};


int main()
{
	Vektor vektor1{ 12.0, 3.0 };
	Vektor vektor2{ vektor1 };    // eksplicitni poziv konstruktora kopije
	Vektor vektor3 = vektor1;     // implicitni poziv konstruktora kopije

	return 0;
}

