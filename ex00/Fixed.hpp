#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <iomanip>
#include <cctype>
#include <limits.h>

class Fixed
{
	private:
		int	_value;
		static const int _eight = 8;
	public:
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		void	operator=(const Fixed &f);
		Fixed(void);
		Fixed(const Fixed &f);
		~Fixed(void);
};

#endif