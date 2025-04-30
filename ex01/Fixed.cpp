#include "Fixed.hpp"

//CONSTRUCTEURS DESTRUCTEURS
Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed(float fparam)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(fparam * 256);
}

Fixed::Fixed(int iparam)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = (iparam << 8);
}
Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

//METHODES
int Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void Fixed::setRawBits( int const raw )
{
	_value = raw;
}

float	Fixed::toFloat( void ) const
{
	return static_cast<float>(_value) / (1 << 8);
}

int		Fixed::toInt( void ) const
{
	return static_cast<int>(_value) >> 8;
}

//OPERATEURS
void Fixed::operator=(const Fixed &f)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_value = f.getRawBits();
}

std::ostream&	operator<<(std::ostream& os, const Fixed& f)
{
	// std::cout << "Insert assignment operator called" << std::endl;
	os << f.toFloat();
	return os;
}
