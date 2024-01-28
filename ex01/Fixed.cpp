/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:27:04 by azgaoua           #+#    #+#             */
/*   Updated: 2024/01/28 20:22:20 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const& src) {
    std::cout << "Copy assignment operator called" << std::endl;
    value = src.getRawBits();
}


Fixed &Fixed::operator=(Fixed const& rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    value = rhs.getRawBits();
    return (*this);
}

void Fixed::setRawBits( int const raw ) {
    value = raw;
}

Fixed::Fixed(const int n) {
    /*
        # do the left shifting in the right way !!
    */
    value = n << bits;
    std::cout << "int constructor is called" << std::endl;
}

Fixed::Fixed(const float n) {
    /*
        # do the left shifting in the right way and use the roundf (from <cmath>)!!
    */
   value = roundf (n * (1 << bits));
   std::cout << "float constructor is called" << std::endl;
}

float Fixed::toFloat(void) const {
    return (float)value / (1 << bits);
}

int Fixed::toInt(void) const {
    return (value >> bits);
}

int Fixed::getRawBits( void ) const {
    // std::cout << "getRawBits member function called" << std::endl;
    return (value);
}


std::ostream& operator<<(std::ostream& os,const Fixed & obj)
{
    os << obj.getRawBits();
    return os;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}