#include "RPN.hpp"
#include <sstream>
#include <exception>

int main (int argc, char *argv[])
{
	RPN int_storage;
	std::string equation;

	if (argc < 2){
		std::cout << "Program requires input" << std::endl;
		return 0;
	}
	equation = argv[1];
	try {
		for (size_t i = 0; i < equation.size(); ++i) {
			if (equation[i] == ADD || equation[i] == SUB || equation[i] == DIV || equation[i] == MUL) {
				int_storage.calculate((Operation)equation[i]);
			} else if (equation[i] != ' ') {
				int_storage.add_to_stack(equation[i]);
			}
		}
		std::cout << int_storage.top() << std::endl;
	} catch (std::invalid_argument& e) {
		std::cerr << e.what() << std::endl;
    }
	return 0;
}