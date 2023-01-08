#ifndef _VANOPSEGA_H_
#define _VANOPSEGA_H_

#include <iostream>

using namespace std;

class VanOpsega {
public:

	friend ostream& operator<<(ostream& it, const VanOpsega& v) {
		return it << "Indeks je izvan opsega!" << endl;
	}
};


#endif