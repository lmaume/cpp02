#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <iomanip>
#include <cctype>
#include <limits.h>
#include <cmath>

class Fixed
{
	private:
		int					_value;
		static const int	_eight = 8;
	public:
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat( void ) const;
		int		toInt( void ) const;
		
		void			operator=(const Fixed &f);
		
		Fixed(float fparam);
		Fixed(int iparam);
		Fixed(const Fixed &f);
		Fixed(void);
		~Fixed(void);
};

std::ostream&	operator<<(std::ostream& os, const Fixed& f);

#endif