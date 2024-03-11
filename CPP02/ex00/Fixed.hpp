#pragma once

# include <iostream>
# include <cmath>
# include <ostream>

class Fixed{
	private:
		int					_fixedPointNumber;
		static const int	_fractionnalBits = 8;

	public:
		Fixed( void );
		Fixed( Fixed &fixed );
		~Fixed( void );

		Fixed& operator=( const Fixed& fixed );

		int getRawBits( void ) const;
		void setRawBits( int const raw );
};
