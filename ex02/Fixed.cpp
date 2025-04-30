#include "Fixed.hpp"

//CONSTRUCTEURS DESTRUCTEURS
Fixed::Fixed(void)
{
	this->_value = 0;
}

Fixed::Fixed(float fparam)
{
	this->_value = roundf(fparam * 256);
}

Fixed::Fixed(int iparam)
{
	this->_value = (iparam << 8);
}
Fixed::Fixed(const Fixed &f)
{
	*this = f;
}

Fixed::~Fixed(void)
{
}

//? METHODES
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

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}
const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}
Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}
const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

//? OPERATEURS
Fixed& Fixed::operator=(const Fixed &f)
{
	if (this != &f)
		_value = f.getRawBits();
	return *this;
}

//? OPERATEURS COMPARAISON
bool Fixed::operator<(const Fixed &f)
{
	if (getRawBits() < f.getRawBits())
		return true;
	return false;
}
bool Fixed::operator>(const Fixed &f)
{
	if (getRawBits() > f.getRawBits())
		return true;
	return false;
}
bool Fixed::operator<=(const Fixed &f)
{
	if (getRawBits() <= f.getRawBits())
		return true;
	return false;
}
bool Fixed::operator>=(const Fixed &f)
{
	if (getRawBits() >= f.getRawBits())
		return true;
	return false;
}
bool Fixed::operator==(const Fixed &f)
{
	if (getRawBits() == f.getRawBits())
		return true;
	return false;
}
bool Fixed::operator!=(const Fixed &f)
{
	if (getRawBits() != f.getRawBits())
		return true;
	return false;
}

//? OPERATEURS ARYTHMETIQUES
Fixed	Fixed::operator+(const Fixed &f)
{
	return Fixed(this->toFloat() + f.toFloat());
}
Fixed	Fixed::operator-(const Fixed &f)
{
	return Fixed(this->toFloat() - f.toFloat());
}
Fixed	Fixed::operator*(const Fixed &f)
{
	return Fixed(this->toFloat() * f.toFloat());
}
Fixed	Fixed::operator/(const Fixed &f)
{
	return Fixed(this->toFloat() / f.toFloat());
}

//? OPERATEURS D'INCREMENTATION
Fixed& Fixed::operator++()
{
	_value++;
	return *this;
}
Fixed Fixed::operator++(int)
{
	Fixed	temp = *this;
	++*this;
	return temp;
}

Fixed& Fixed::operator--()
{
	_value--;
	return *this;
}
Fixed Fixed::operator--(int)
{
	Fixed	temp = *this;
	--*this;
	return temp;
}

std::ostream&	operator<<(std::ostream& os, const Fixed& f)
{
	os << f.toFloat();
	return os;
}
