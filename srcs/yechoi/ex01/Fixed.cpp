/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechoi <yechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 15:12:55 by yechoi            #+#    #+#             */
/*   Updated: 2020/11/08 19:45:18 by yechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout<<"Default constructor called"<<std::endl;
    _value = 0;   
}

Fixed::Fixed(const Fixed &ref) 
{
    std::cout<<"Copy constructor called"<<std::endl;
    *this = ref;
}

Fixed&  Fixed::operator=(const Fixed &ref)
{
    std::cout<<"Assignation operator called"<<std::endl;
    _value = ref.getRawBits();
    return (*this);
}

Fixed::Fixed(int const value)
{
    std::cout<<"Int constructor called"<<std::endl;
    _value = value << _bits;
}

Fixed::Fixed(float const value)
{
    std::cout<<"Float constructor called"<<std::endl;
    _value = roundf(value * (1 << _bits));
}

Fixed::~Fixed(void)
{
    std::cout<<"Destructor called"<<std::endl;
}

int     Fixed::getRawBits(void) const
{
    return (_value);
}

void    Fixed::setRawBits(int const raw)
{
    _value = raw;
}

float   Fixed::toFloat(void) const
{
    return ((float)_value / (1 << _bits));
}

int     Fixed::toInt(void) const
{
    return (_value >> _bits);
}

std::ostream& operator<<(std::ostream& os, const Fixed &ref)
{
    return (os << ref.toFloat());
}