#ifndef _LISTA_H_
#define _LISTA_H_

#include <iostream>

using namespace std;

class VanOpsega {
public:

	friend ostream& operator<<(ostream& it, const VanOpsega& v) {
		return it << "Indeks je izvan opsega!" << endl;
	}
};

template <typename T> class Lista {

public:

	void dodaj(T);
	int broj_podataka() const;

	Lista() = default;
	Lista(const Lista& l) { kopiraj(l); }
	Lista(Lista&& l) { premesti(l); }
	~Lista() { brisi(); }

	const T& operator[](int) const;
	T& operator[](int);

	Lista& operator+=(T);
	Lista& operator=(Lista<T>&);

private:

	struct Elem {
		T val;
		Elem* next;
		Elem(T v) : val(v), next(nullptr) {}
	};

	Elem* prvi = nullptr;
	Elem* posl = nullptr;

	void kopiraj(const Lista&);
	void premesti(Lista&);
	void brisi();

};

#endif

template<typename T>
inline void Lista<T>::dodaj(T obj){

	Elem* novi = new Elem(obj);

	if (!prvi) {
		prvi = novi;
		posl = novi;
	}
	else {
		posl->next = novi;
		posl = novi;
	}
}

template<typename T>
inline int Lista<T>::broj_podataka() const
{
	int counter = 0;
	Elem* tek = prvi;

	while (tek) {
		tek = tek->next;
		counter++;
	}

	return counter;
}

template<typename T>
inline const T& Lista<T>::operator[](int i) const
{
	if (i < 0 || i > broj_podataka()) throw VanOpsega();

	int counter = 0;
	Elem* tek = prvi;

	while (tek && counter != i) {
		tek = tek->next;
		counter++;
	}

	return tek->val;
}

template<typename T>
inline T& Lista<T>::operator[](int i)
{
	if (i < 0 || i > broj_podataka()) throw VanOpsega();

	int counter = 0;
	Elem* tek = prvi;

	while (tek && counter != i) {
		tek = tek->next;
		counter++;
	}

	return tek->val;
}

template<typename T>
inline Lista<T>& Lista<T>::operator+=(T obj)
{
	dodaj(obj);

	return *this;
}

template<typename T>
inline Lista<T>& Lista<T>::operator=(Lista<T>& obj)
{
	if (this != &obj) {
		brisi();
		kopiraj(obj);
	}

	return *this;
}

template<typename T>
inline void Lista<T>::kopiraj(const Lista<T>& l)
{
	Elem* tek = l.prvi;

	while (tek) {
		dodaj(tek->val);
		tek = tek->next;
	}
}

template<typename T>
inline void Lista<T>::premesti(Lista<T>& l)
{
	prvi = l.prvi;
	posl = l.posl;
	l.prvi = nullptr;
	l.posl = nullptr;
}

template<typename T>
inline void Lista<T>::brisi()
{
	Elem* tmp;

	while (tmp = prvi) {
		prvi = prvi->next;
		delete tmp;
	}

	prvi = nullptr;
	posl = nullptr;

}
