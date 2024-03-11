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

		bool	operator>( const Fixed &fixed ) const;
		bool	operator<( const Fixed &fixed ) const;
		bool	operator>=( const Fixed &fixed ) const;
		bool	operator<=( const Fixed &fixed ) const;
		bool	operator==( const Fixed &fixed ) const;
		bool	operator!=( const Fixed &fixed ) const;

		Fixed	operator+( const Fixed &fixed );
		Fixed	operator-( const Fixed &fixed );
		Fixed	operator*( const Fixed &fixed );
		Fixed	operator/( const Fixed &fixed );

		Fixed	operator++( int );
		Fixed	operator++( void );
		Fixed	operator--( int );
		Fixed	operator--( void );

		static Fixed& min(Fixed& nb1, Fixed& nb2);
		static const Fixed& min(const Fixed& nb1, const Fixed& nb2);

		static Fixed& max(Fixed& nb1, Fixed& nb2);
		static const Fixed& max(const Fixed& nb1, const Fixed& nb2);

		int		toInt( void ) const;
		float	toFloat( void ) const;

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

std::ostream& operator<<( std::ostream& os,  const Fixed& fixed );
