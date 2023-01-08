#ifndef _DOMACIFILM_H_
#define _DOMACIFILM_H_

#include <iostream>
#include "Film.h"

class DomaciFilm : public Film {

public:

	DomaciFilm(string s, int t) : Film(s, t) { oznaka = 'D'; }

};


#endif
