#include <iostream>

enum SmjerPomaka
{
	PomakGore, PomakDolje, PomakLijevo, PomakDesno
};

class GrafObjekt
{
	// detalji implementacije su nebitni
public:
	void Crtaj() const;
	bool Gore();
	bool Dolje();
	bool Lijevo();
	bool Desno();
	void PostaviVelicinu(int sirina, int visina);
	// funkcija PonoviPomak ima argument smjer koji je
	// tipa pokazivač na funkcijski član klase GrafObjekt
	// koji ne uzima argumente i vraća cijeli broj:
	//void PonoviPomak(bool (GrafObjekt::*smjer)(), int puta);
	void PonoviPomak(SmjerPomaka smjer, int puta);

private:
	// niz pokazivača na funkcijske članove:
	PokNaFClanBezArg funkcije[4]{
									&GrafObjekt::Gore,
									&GrafObjekt::Dolje,
									&GrafObjekt::Lijevo,
									&GrafObjekt::Desno
	};

};

using PokNaFClanBezArg = bool (GrafObjekt::*)();
using PokNaFClan2Arg = void (GrafObjekt::*)(int, int);
using PonNaFClanCrtaj = void (GrafObjekt::*)() const;

//void GrafObjekt::PonoviPomak(PokNaFClanBezArg smjer, int puta)
//// potpis bez sinonima bio bi:
//// void GrafObjekt::PonoviPomak(int (GrafObjekt::* smjer)(), int puta)
//{
//	for (int i = 0; i < puta; ++i)
//	{
//		if ((this->*smjer)())		// ako smo došli do ruba,
//			break;					// prekidaj!
//	}
//}

void GrafObjekt::PonoviPomak(SmjerPomaka smjer, int puta)
{
	for (int i = 0; i < puta; ++i)
	{
		if ((this->*funkcije[smjer])())
			break;
	}
}


int main()
{
	GrafObjekt grObj;                    // deklaracija objekta
	PokNaFClanBezArg fcBezArg;            // deklaracija pokazivača na f. č.
	fcBezArg = &GrafObjekt::Gore;         // uzimanje adrese f.č.
	(grObj.*fcBezArg)();                // poziv preko pokazivača na f.č.

	GrafObjekt* pokNaGrObj = &grObj;    // pokazivač na objekt
	// deklaracija pokazivača na funkcijski član i pridruživanje člana:
	PokNaFClan2Arg fcDvaArg = &GrafObjekt::PostaviVelicinu;
	(pokNaGrObj->*fcDvaArg)(5, 6);        // poziv preko pokazivača na f.č

	GrafObjekt nekiObjekt;
	nekiObjekt.PonoviPomak(GrafObjekt::Dolje, 4);
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
