#pragma once

# include <iostream>
# include <string>
# include <iomanip>
# include <climits>
#include <cfloat>


enum {
	NONE,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO
};

class Conversion {
	private:
		std::string	_str;
		int			_type;

	public:
		Conversion();
		Conversion(std::string str);
		Conversion(const Conversion& inst);
		~Conversion();

		void	setType();

		bool	isPseudo();
		bool	isChar();
		bool	isDouble();
		bool	isFloat();
		bool	isInt();

		int		countChar(char c);
		void	display();
		void	displayPseudo();
		void	displayChar(char str);
		void	displayFloat(float str);
		void	displayDouble(double str);
		void	displayInt(int str);

		Conversion& operator=(const Conversion& inst);
};
