#include "./Include/ScalarConverter.hpp"

#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>

Scalar::Scalar() {
}

Scalar::~Scalar() {
}

Scalar::Scalar(const Scalar& obj) {
    *this = obj;
}

Scalar& Scalar::operator=(const Scalar& obj) {
    (void)obj; return *this; 
}

void Scalar::convert(const std::string& literal) {
	std::string edge_cases[6] = {
		"-inff", "+inff", "nanf",
		"-inf", "+inf", "nan"
	};
	std::string toChar = "";
	int toInt = 0;
	float toFloat = 0;
	double toDouble = 0;

	if (literal.size() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])) {
		toChar = literal[0];
		std::cout << "char: " << toChar << std::endl;
		std::cout << "int: " << static_cast<int>(toChar[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(toChar[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(toChar[0]) << ".0" << std::endl;
		return;
	}

	toInt = std::atoi(literal.c_str());

	if (literal[literal.length() - 1] == 'f') {
		toFloat = std::atof(literal.c_str());
		toDouble = static_cast<double>(toFloat);
	} else {
		toDouble = std::atof(literal.c_str());
		toFloat = static_cast<float>(toDouble);
	}

	for (int i = 0; i < 6; ++i) {
		if (literal == edge_cases[i]) {
			toChar = "Impossible"; break;
		}
	}
	if (toChar == "" && (toInt >= 32 && toInt <= 126)) {
		toChar += "'";
		toChar += static_cast<char>(toInt);
		toChar += "'";
	} 
	else if (toChar == "") {
		toChar = "Non displayable";
	}

	std::cout << "char: " << toChar << std::endl;
	if (toChar == "Impossible") {
		std::cout << "int: Impossible" << std::endl;
	} 
	else {
		std::cout << "int: " << toInt << std::endl;
	}

	if (toChar == "Impossible" && toFloat == 0) {
		std::cout << "float: Impossible" << std::endl;
		std::cout << "double: Impossible" << std::endl;
	} 
	else {
		if (toChar != "Impossible" && toFloat - static_cast<int>(toFloat) == 0) {
			std::cout << "float: " << toFloat << ".0f" << std::endl;
			std::cout << "double: " << toDouble << ".0" << std::endl;
		} 
		else {
			std::cout << "float: " << toFloat << "f" << std::endl;
			std::cout << "double: " << toDouble << std::endl;
		}
	}
}