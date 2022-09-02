/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechoi <yechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 19:06:39 by yechoi            #+#    #+#             */
/*   Updated: 2020/11/08 18:04:13 by yechoi           ###   ########.fr       */
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
    _value = ref.getRawBits(); 
}

Fixed&  Fixed::operator=(const Fixed &ref)
{
    std::cout<<"Assignation operator called"<<std::endl;
    _value = ref.getRawBits();
    return (*this);
}

Fixed::~Fixed(void)
{
    std::cout<<"Destructor called"<<std::endl;
}

int     Fixed::getRawBits(void) const
{
    std::cout<<"getRawBits member function called"<<std::endl;
    return (_value);
}

void    Fixed::setRawBits(int const raw)
{
    _value = raw;
}