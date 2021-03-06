#include <iostream>
#include <vector>

using namespace std;

struct Tocka
{
	int x;
	int y;
};

using NizTocaka = vector<Tocka>;
NizTocaka tocke{ { 1, 2 }, { 3, 4 }, { 5, 6 }, { 7, 8 } };

int NajmanjiX(const NizTocaka& tocke)
{
	int min = numeric_limits<int>::max();
	for (const Tocka& t : tocke)
	{
		if (t.x < min)
			min = t.x;
	}
	return min;
}

int NajveciX(const NizTocaka& tocke)
{
	int max = numeric_limits<int>::min();
	for (const Tocka& t : tocke)
	{
		if (t.x > max)
			max = t.x;
	}
	return max;
}

int NajmanjiY(const NizTocaka& tocke)
{
	// prepuštamo čitatelju da popuni...
	return 0;
}

int NajveciY(const NizTocaka& tocke)
{
	// prepuštamo čitatelju da popuni...
	return 0;
}

void PostaviNaNulu(Tocka& tocka)
{
	int Tocka::*pokKoord[]{
								&Tocka::x,
								&Tocka::y
	};
	for (int i = 0; i < 4; ++i)
		tocka.*pokKoord[i] = 0;
}

int Najmanji(const NizTocaka& tocke, const int Tocka::* koordinata)
{
	int min = numeric_limits<int>::max();
	for (const Tocka& t : tocke)
	{
		if (t.*koordinata < min)
			min = t.*koordinata;
	}
	return min;
}

int main()
{
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
