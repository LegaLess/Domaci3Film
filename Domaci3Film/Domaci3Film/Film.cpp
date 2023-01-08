#include <iostream>
#include <string>
#include "Film.h"

using namespace std;

double Film::prosecna_ocena() const
{
    int s = 0;

    for (int i = 0; i < ocene.broj_podataka(); i++) {
        s += ocene[i];
    }

    return (double)s / ocene.broj_podataka();
}
