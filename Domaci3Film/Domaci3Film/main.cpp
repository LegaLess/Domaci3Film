#include <iostream>
#include <string>
#include "Vreme.h"
#include "DomaciFilm.h"
#include "StraniFilm.h"

using namespace std;

int main() {
	
	Lista<int> lista;

	lista += 1;
	lista += 2;
	lista += 3;

	cout << lista.broj_podataka() << endl;

	try
	{
		cout << lista[-2] << endl;
	}
	catch (const VanOpsega ex)
	{
		cout << ex;
	}
	
	Vreme v1(3, 22);
	Vreme v2(3, 40);

	cout << v1 + v2;

	cout << (v2 > v1) << endl;
	

	StraniFilm spartanac("spartanac", 120, "Amerika", TITLOVAN);
	spartanac.oceni(7).oceni(7).oceni(8);

	DomaciFilm film2("varljivo leto", 100);
	film2.oceni(9).oceni(10).oceni(3).oceni(6);

	cout << spartanac;

	cout << film2;

	return 0;
}