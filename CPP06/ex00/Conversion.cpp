#include "Conversion.hpp"
#include <string>

Conversion::Conversion(): _str(""), _type(NONE) {

}

Conversion::Conversion(std::string str): _str(str), _type(NONE) {

}

Conversion::Conversion(const Conversion& inst): _str(inst._str), _type(inst._type) {
	*this = inst;
}

Conversion::~Conversion() {

}

Conversion& Conversion::operator=(const Conversion& inst) {
	this->_str = inst._str;
	this->_type = inst._type;
	return *this;
}

bool	Conversion::isPseudo() {
	std::string str[] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};

	for (int i = 0; i < 6; i++)
		if (str[i] == _str)
			return (_type = PSEUDO, true);
	return false;
}

int	Conversion::countChar(char c) {
	int	count = 0;

	for (int i = 0; _str[i]; i++)
		if (_str[i] == c)
			count++;
	return count;
}

bool	Conversion::isChar() {
	if (_str.length() == 1 && isascii(_str[0]) && !std::isdigit(_str[0]))
		return (_type = CHAR, true);
	return false;
}

bool	Conversion::isFloat() {
	try {
		std::stof(_str);
	} catch (std::exception & e) {
		return false;
	}
	for (int i = 0; _str[i]; i++) {
		if (i == 0 && _str[0] == '-')
			i++;
		if (!std::isdigit(_str[i]) && _str[i] != '.' && _str[i] != 'f')
			return false;
	}
	if (countChar('f') == 1 && _str.back() == 'f' && countChar('.') == 1 \
	&& std::isdigit(_str[_str.find(".") + 1]) && std::isdigit(_str[_str.find(".") - 1]))
		return (_type = FLOAT, true);
	return false;
}

bool	Conversion::isDouble() {
	try {
		std::stod(_str);
	} catch (std::exception & e) {
		return false;
	}
	for (int i = 0; _str[i]; i++) {
		if (i == 0 && _str[0] == '-')
			i++;
		if (!std::isdigit(_str[i]) && _str[i] != '.')
			return false;
	}
	if (countChar('.') == 1 && std::isdigit(_str[_str.find(".") + 1]) \
	&& std::isdigit(_str[_str.find(".") - 1]))
		return (_type = DOUBLE, true);
	return false;
}

bool	Conversion::isInt() {
	try {
		std::stoi(_str);
	} catch (std::exception & e) {
		return false;
	}
	for (int i = 0; _str[i]; i++) {
		if (i == 0 && _str[0] == '-')
			i++;
		if (!std::isdigit(_str[i]))
			return false;
	}
	return (_type = INT, true);
}

void	Conversion::displayPseudo() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (_str == "nan" || _str == "-inf") {
		double value = std::stod(_str);
		std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
		std::cout << "double: " << value << std::endl;
	}
	else if (_str == "+inf") {
		double value = std::stod(_str);
		std::cout << "float: +" << static_cast<float>(value) << "f" << std::endl;
		std::cout << "double: +" << value << std::endl;
	}
	else if (_str == "+inff") {
		float value = std::stof(_str);
		std::cout << "float: +" << value << "f" << std::endl;
		std::cout << "double: +" << static_cast<double>(value) << std::endl;
	}
	else if (_str == "nanf" || _str == "-inff") {
		float value = std::stof(_str);
		std::cout << "float: " << value << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(value) << std::endl;
	}
}

void	Conversion::displayChar(char str) {
	if (std::isprint(str))
		std::cout << "char: '" << str << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(str) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(str) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(str) << std::endl;
}

void	Conversion::displayFloat(float str) {
	if (std::isprint(str))
		std::cout << "char: '" << static_cast<char>(str) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	try {
		std::stoi(std::to_string(str));
		std::cout << "int: " << static_cast<int>(str) << std::endl;
	} catch (std::exception & e) {
		std::cout << "int: impossible" << std::endl;
	}
	std::cout << "float: " << std::fixed << std::setprecision(1) << str << "f" << std::endl;
	if (str <= DBL_MAX && str >= -DBL_MAX)
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(str) << std::endl;
	else
		std::cout << "double: impossible" << std::endl;
}

void	Conversion::displayDouble(double str) {
	if (std::isprint(str))
		std::cout << "char: '" << static_cast<char>(str) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (str <= INT_MAX && str >= INT_MIN)
		std::cout << "int: " << static_cast<int>(str) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	if (str <= FLT_MAX && str >= -FLT_MAX)
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(str) << "f" << std::endl;
	else
		std::cout << "float: impossible" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << str << std::endl;
}

void	Conversion::displayInt(int str) {
	if (std::isprint(str))
		std::cout << "char: '" << static_cast<char>(str) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << str << std::endl;
	if (str <= FLT_MAX && str >= -FLT_MAX)
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(str) << "f" << std::endl;
	else
		std::cout << "float: impossible" << std::endl;
	if (str <= DBL_MAX && str >= -DBL_MAX)
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(str) << std::endl;
	else
		std::cout << "double: impossible" << std::endl;
}

void	Conversion::setType() {
	isPseudo();
	isChar();
	isDouble();
	isFloat();
	isInt();
}

void	Conversion::display() {
	switch (_type) {
		case PSEUDO:
			displayPseudo();
			break ;
		case CHAR:
			displayChar(_str[0]);
			break ;
		case FLOAT:
			displayFloat(std::stof(_str));
			break ;
		case DOUBLE:
			displayDouble(std::stod(_str));
			break ;
		case INT:
			displayInt(std::stoi(_str));
			break ;
		default:
			std::cout << "Bad input" << std::endl;
	}
}
