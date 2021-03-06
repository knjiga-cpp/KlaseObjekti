#include <iostream>
using namespace std;

class Vektor
{
	friend void ZbrojiVektore(const Vektor& a, const Vektor& b,
		Vektor& rez);

private:
	static int brojac;
	int redbr{ 0 };
	double ax{ 0.0 }, ay{ 0.0 };

public:
	Vektor(double x = 0, double y = 0);
	Vektor(const Vektor& ref);
	~Vektor();

	double DajX() const noexcept { return ax; }
	double DajY() const noexcept { return ay; }
	void PostaviXY(double x, double y) { ax = x; ay = y; }
	void IspisiVektor() const;
};

int Vektor::brojac = 0;

Vektor::Vektor(double x, double y) : ax(x), ay(y), redbr(++brojac)
{
	cout << "Stvoren vektor pod brojem " << redbr << endl;
	cout << "X: " << ax << "    Y: " << ay << endl;
}

Vektor::Vektor(const Vektor& v) : ax(v.ax), ay(v.ay), redbr(++brojac)
{
	cout << "Stvoren vektor pomoću konstruktora kopije "
		<< "pod brojem " << redbr << endl
		<< "X: " << ax << "    Y: " << ay << endl;
}

Vektor::~Vektor()
{
	cout << "Uništen vektor pod brojem " << redbr << endl;
	cout << "X: " << ax << "    Y: " << ay << endl;
}

//void ZbrojiVektore(const Vektor& a, const Vektor& b, Vektor& rez)
//{
//	cout << "Zbrajam" << endl;
//	rez.ax = a.ax + b.ax;
//	rez.ay = a.ay + b.ay;
//	cout << "Zbrojio sam" << endl;
//}

//Vektor ZbrojiVektore(const Vektor& a, const Vektor& b)
//{
//	cout << "Ušao u ZbrojiVektore" << endl;
//	Vektor rez = { a.DajX() + b.DajX(), a.DajY() + b.DajY() };
//	return rez;
//}

Vektor ZbrojiVektore(const Vektor& a, const Vektor& b)
{
	cout << "Ušao u ZbrojiVektore" << endl;
	return (a.DajX() + b.DajX(), a.DajY() + b.DajY());
}

void Vektor::IspisiVektor() const
{
	cout << "Ispis (" << ax << "," << ay << ")" << endl;
}

void NaNulu(Vektor v)
{
	cout << "Ušao u NaNulu" << endl;
	v.PostaviXY(0, 0);
	cout << "Postavio sam" << endl;
}


int main()
{
	//cout << "Ulazak u main" << endl;
	//Vektor c;

	//cout << "Pozivam ZbrojiVektore" << endl;
	//ZbrojiVektore(Vektor{ 10.0, 2.8 }, Vektor{ -2.0, 5.0 }, c);

	//Vektor a{ 10.0, 2.8 };
	//Vektor b{ -2.0, 5.0 };
	//cout << "Pozivam ZbrojiVektore" << endl;
	//ZbrojiVektore(a, b, c);
	//cout << "Završavam" << endl;

	//cout << "Prije izraza" << endl;
	//Vektor{ 12.0, 3.0 }.IspisiVektor();
	//cout << "Nakon izraza" << endl;

	//Vektor a;
	//for (int i = 0; i < 10; ++i)
	//	a = Vektor{ static_cast<double>(i), static_cast<double>(i + 1) };

	//for (int i = 0; i < 10; ++i)
	//	Vektor a{ static_cast<double>(i), static_cast<double>(i + 1) };

	//cout << "Ušao sam u main" << endl;
	//Vektor c{ 12.0, 3.0 };
	//cout << "Pozivam NaNulu" << endl;
	//NaNulu(c);
	//cout << "Završavam" << endl;

	//Vektor a = Vektor{ 12.0, 3.0 };

	cout << "Ušao u main" << endl;
	Vektor a{ 12.0, 3.0 }, b{ -2.0, -6.0 }, c;
	cout << "Ulazim u ZbrojiVektore" << endl;
	c = ZbrojiVektore(a, b);
	cout << "Završavam" << endl;

	return 0;
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
