#include <iostream>
#include <string>
#include "Lista.h"

using namespace std;

int main() {
	
	Lista<int> lista;

	lista += 1;
	lista += 2;
	lista += 3;

	cout << lista.broj_podataka() << endl;

	try
	{
		cout << lista[2];
	}
	catch (const VanOpsega ex)
	{
		cout << ex;
	}

	return 0;
}