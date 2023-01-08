#ifndef _STRANIFILM_H_
#define _STRANIFILM_H_

#include <iostream>
#include <string>
#include "Film.h"

using namespace std;

enum vrste_prevoda { TITLOVAN, SINHRONIZOVAN };

class StraniFilm : public Film {

public:

	StraniFilm(string n, int t, string zp, vrste_prevoda p) : Film(n, t), zemlja_porekla(zp), prevod(p) { oznaka = 'S'; }

private: 

	ostream& pisi(ostream& it, const Film& f) const override {
		return Film::pisi(it, f) << " " << zemlja_porekla << " " << prevod << endl;
	}

	string zemlja_porekla;
	vrste_prevoda prevod;

};

#endif
