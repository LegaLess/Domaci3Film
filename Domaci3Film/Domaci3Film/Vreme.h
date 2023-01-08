#ifndef _VREME_H_
#define _VREME_H_

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Vreme {

public:

	Vreme(int s, int m) : sati(s), minuti(m) {}

	friend bool operator>(const Vreme& v1, const Vreme& v2) {
		return v1.sati > v2.sati || ((v1.sati == v2.sati) && v1.minuti > v2.minuti);
	}

	friend Vreme operator+(const Vreme& v1, const Vreme& v2) {
		int minuti = v1.sati * 60 + v2.sati * 60 + v1.minuti + v2.minuti;
		return Vreme(minuti / 60, minuti % 60);
	}

	friend ostream& operator<<(ostream& it, const Vreme& v) {
		return it << setfill('0') << setw(2) << v.sati << ":" << setfill('0') << setw(2) << v.minuti << endl;
	}


private:

	int sati, minuti;

};


#endif