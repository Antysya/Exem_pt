#pragma once
#include <vector>
#include <iostream>
using namespace std;

class Cheque {
private:
	static Cheque* pObj;
	Cheque(); 
	~Cheque(); 

public:
	static Cheque* GetInstance() {
		if (!pObj) {
			pObj = new Cheque();
		}
		return pObj;
	}

	void PutCheque(string message);
};

class Pizza {
	vector <Pizza*> pizza;
public:
	virtual void info() = 0;
	virtual void addPizza(Pizza* p);
	virtual ~Pizza() {}
};

class Dough : public Pizza {
public:
	void info();
};

class Sauce : public Pizza
{
public:
	void info();
};

class Cheeses : public Pizza
{
public:
	void info();
};

class Pepperoni : public Pizza
{
public:
	void info();
};

class Tomato : public Pizza
{
public:
	void info();
};

class Meat : public Pizza {
public:
	void info();
};

class Chicken : public Pizza {
public:
	void info();
};

class Pineapples : public Pizza {
public:
	void info();
};

class Mushrooms : public Pizza {
public:
	void info();
};

// Фабрики объектов
class Factory
{
public:
	virtual Pizza* createPizza() = 0;
	virtual ~Factory() {}
};

class DoughFactory : public Factory {
public:
	Pizza* createPizza() {
		return new Dough;
	};
};

class SauceFactory : public Factory {
public:
	Pizza* createPizza() {
		return new Sauce;
	}
};

class CheesesFactory : public Factory
{
public:
	Pizza* createPizza() {
		return new Cheeses;
	}
};

class PepperoniFactory : public Factory
{
public:
	Pizza* createPizza() {
		return new Pepperoni;
	}
};

class TomatoFactory : public Factory
{
public:
	Pizza* createPizza() {
		return new Tomato;
	}
};

class MeatFactory : public Factory
{
public:
	Pizza* createPizza() {
		return new Meat;
	}
};

class ChickenFactory : public Factory
{
public:
	Pizza* createPizza() {
		return new Chicken;
	}
};

class PineapplesFactory : public Factory
{
public:
	Pizza* createPizza() {
		return new Pineapples;
	}
};

//паттерн Composite 
class CompositeBase : public Pizza {
private:
	vector <Pizza*> base;
public:
	void info();
	void addPizza(Pizza* p);
	~CompositeBase() {}
};

CompositeBase* createBase();
CompositeBase* createMeat();