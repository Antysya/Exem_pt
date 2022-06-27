#include "Pizza.h"
#include <Windows.h>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

Cheque::Cheque() {
	pObj = NULL;
}

Cheque::~Cheque() {
	if (pObj) {
		delete pObj;
	};
}

void Cheque::PutCheque(string message) {

	SYSTEMTIME timer;
	GetLocalTime(&timer);
	ofstream fObj("cheque.txt", ios::app);
	if (!fObj) {
		cout << "\nError with file\n";
		exit(EXIT_FAILURE);
	}
	fObj << message.c_str() << "\t" << timer.wDay << ':' << setfill('0') << setw(2) << timer.wMonth << ':' << timer.wYear << endl;
};

Cheque* Cheque::pObj;

void Pizza::addPizza(Pizza* p) {
	pizza.push_back(p);;
}

void Dough::info() {
	cout << "Тесто" << endl;
};

void Sauce::info() {
	cout << "Соус" << endl;
};

void Cheeses::info() {
	cout << "Сыр" << endl;
};

void Pepperoni::info() {
	cout << "Пепперони" << endl;
};

void Tomato::info() {
	cout << "Помидор" << endl;
};

void Meat::info() {
	cout << "Мясо" << endl;
};

void Chicken::info() {
	cout << "Курица" << endl;
}

void Pineapples::info() {
	cout << "Ананас" << endl;
}

void Mushrooms::info() {
	cout << "Грибы" << endl;
}

void CompositeBase::info() {
	for (int i = 0; i < base.size(); i++)
		base[i]->info();
};
void CompositeBase::addPizza(Pizza* p) {
	base.push_back(p);
}

CompositeBase* createBase() { // основа
	CompositeBase* base = new CompositeBase;
	base->addPizza(new Dough);
	base->addPizza(new Sauce);
	base->addPizza(new Cheeses);
	return base;
}

CompositeBase* createMeat() { // набор для мясной
	CompositeBase* base = new CompositeBase;
	base->addPizza(new Pepperoni);
	base->addPizza(new Tomato);
	base->addPizza(new Meat);
	base->addPizza(new Chicken);
	base->addPizza(new Mushrooms);
	return base;
}