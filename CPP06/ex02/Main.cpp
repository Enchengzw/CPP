#include "./Include/Class.hpp"

Base::~Base() {
}

Base* generate() {
	std::srand(time(NULL));

	int n = rand() % 3;
	switch (n) {
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
	}
	return NULL;
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p) != NULL) {
		std::cout << "A class was identified" << std::endl;
	} 
	else if (dynamic_cast<B*>(p) != NULL) {
		std::cout << "B class was identified" << std::endl;
	} 
	else if (dynamic_cast<C*>(p) != NULL) {
	std::cout << "C class was identified" << std::endl;
	} 
	else {
		std::cout << "Can't identify the class" << std::endl;
	}
}

void identify(Base& p) {
	try {
		A& aux = dynamic_cast<A&>(p); (void)aux;
		std::cout << "A class was identified" << std::endl;
		return;
	} 
	
	catch (...) {}

	try {
		B& aux = dynamic_cast<B&>(p); (void)aux;
		std::cout << "B class was identified" << std::endl;
		return;
	} 
	
	catch (...) {}

	try {
		C& aux = dynamic_cast<C&>(p); (void)aux;
		std::cout << "C class was identified" << std::endl;
		return;
	} 
	
	catch (...) {}

	std::cout << "Can't identify the class" << std::endl;
}

int main() 
{
	Base *base;
	Base *a = 0;

	base = generate();
	identify(base);
	identify(*base);
	identify(*a);
	identify(a);

	return 0;
}