/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 21:33:15 by mki               #+#    #+#             */
/*   Updated: 2021/07/08 21:32:04 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	setRawBits(0);
}

Fixed::Fixed(const int i)
{
	setRawBits(i << _fractionalBits);
}

Fixed::Fixed(const float f)
{
	setRawBits(roundf(f * (1 << _fractionalBits)));
}

Fixed::Fixed(const Fixed& f)
{
	*this = f;
}

Fixed	&Fixed::operator=(const Fixed &f)
{
	setRawBits(f.getRawBits());
	return (*this);
}

Fixed::~Fixed()
{
}

int		Fixed::getRawBits(void) const
{
	return _fixedPointValue;
}

void	Fixed::setRawBits(int const raw)
{
	_fixedPointValue = raw;
}

float	Fixed::toFloat(void) const
{
	return static_cast<float>(getRawBits()) / (1 << _fractionalBits);
}

int		Fixed::toInt(void) const
{
	return getRawBits() >> _fractionalBits;
}

std::ostream	&operator<<(std::ostream &os, const Fixed &f)
{
	os << f.toFloat();
	return os;
}

bool	Fixed::operator>(const Fixed &f) const
{
	return getRawBits() > f.getRawBits();
}

bool	Fixed::operator<(const Fixed &f) const
{
	return getRawBits() < f.getRawBits();
}

bool	Fixed::operator>=(const Fixed &f) const
{
	return getRawBits() >= f.getRawBits();
}

bool	Fixed::operator<=(const Fixed &f) const
{
	return getRawBits() <= f.getRawBits();
}

bool	Fixed::operator==(const Fixed &f) const
{
	return getRawBits() == f.getRawBits();
}

bool	Fixed::operator!=(const Fixed &f) const
{
	return getRawBits() != f.getRawBits();
}

Fixed	Fixed::operator+(const Fixed &f) const
{
	Fixed	tmp;

	tmp.setRawBits(getRawBits() + f.getRawBits());
	return tmp;
}

Fixed	Fixed::operator-(const Fixed &f) const
{
	Fixed	tmp;

	tmp.setRawBits(getRawBits() - f.getRawBits());
	return tmp;
}

Fixed	Fixed::operator*(const Fixed &f) const
{
	Fixed	tmp;

	tmp.setRawBits(getRawBits() * f.getRawBits() >> this->_fractionalBits);
	return tmp;
}

Fixed	Fixed::operator/(const Fixed &f) const
{
	Fixed	tmp;

	tmp.setRawBits((getRawBits() << this->_fractionalBits) / f.getRawBits());
	return tmp;
}

Fixed	Fixed::operator++()
{
	this->_fixedPointValue++;
	return *this;
}

Fixed	Fixed::operator--()
{
	this->_fixedPointValue--;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);

	operator++();
	return (temp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);

	operator--();
	return (temp);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}
