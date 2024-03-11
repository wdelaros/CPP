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
		Fixed( const Fixed &fixed );
		Fixed( const int fixedPointValue );
		Fixed( const float fixedPointNumber );
		~Fixed( void );

		Fixed&	operator=( const Fixed& fixed );

		int		toInt( void ) const;
		float	toFloat( void ) const;

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};
std::ostream& operator<<( std::ostream& os,  const Fixed& fixed );
