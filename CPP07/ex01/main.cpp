#include "iter.hpp"

class Awesome
{
	public:
	Awesome( void ) : _n( 42 ) { return; }
	int get( void ) const { return this->_n; }
	private:
	int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

template< typename T >
void print( T const & x ) { std::cout << x << std::endl; return; }

int main() {
	{
		int tab[] = { 0, 1, 2, 3, 4 };  // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
		Awesome tab2[5];

		iter( tab, 5, print<int> );
		iter( tab2, 5, print<Awesome> );
	}
	{
		int arrayInt[5];

		for (int i = 0; i < 5; i++) {
			arrayInt[i] = i;
		}
		iter(arrayInt, 5, a);
		for (int i = 0; i < 5; i++)
			std::cout << arrayInt[i] << std::endl;
	}
	{
		char arrayChar[5] = "allo";

		iter(arrayChar, 4, a);
		std::cout << arrayChar << std::endl;
	}
	return 0;
}