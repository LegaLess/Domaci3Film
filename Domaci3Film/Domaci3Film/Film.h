#ifndef _FILM_H_
#define _FILM_H_

#include <iostream>
#include <string>
#include "Lista.h"

using namespace std;

class Film {

public:

	Film& oceni(int ocena) { ocene.dodaj(ocena); return *this; }

	int get_trajanje() const { return trajanje; }

	friend ostream& operator<<(ostream& it, const Film& f) { return f.pisi(it, f); }

	double prosecna_ocena() const;
	
	char get_oznaka() const { return oznaka; }

	Film(string n, int t) : naziv(n), trajanje(t) {}

protected:

	virtual ostream& pisi(ostream& it, const Film& f) const { return it << f.oznaka << " " << f.naziv << " " << f.trajanje << " " << f.prosecna_ocena(); }
	char oznaka;

private:

	int trajanje = 0;
	string naziv;
	Lista<int> ocene;

};

#endif


