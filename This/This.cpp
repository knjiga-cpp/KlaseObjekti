#include <iostream>
#include <string>

using namespace std;

class RodnaOsoba
{
public:
	string ime;

private:
	RodnaOsoba* otac{ nullptr };         // pokazivač na oca

public:
	RodnaOsoba(const string& ime) : ime(ime) {}

	void BitCuTiOtac(RodnaOsoba* osoba)
	{
		osoba->otac = this;
	}
};


int main()
{
	RodnaOsoba japa{ "Francek" };
	RodnaOsoba sinek{ "Štefek" };
	japa.BitCuTiOtac(&sinek);

	return 0;
}

