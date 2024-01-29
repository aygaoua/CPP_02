/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:27:04 by azgaoua           #+#    #+#             */
/*   Updated: 2024/01/29 22:33:25 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const& src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}


Fixed &Fixed::operator=(Fixed const& rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    value = rhs.value;
    return (*this);
}

void Fixed::setRawBits( int const raw ) {
    value = raw;
}

Fixed::Fixed(const int n) {
    value = n << bits;
    std::cout << "Int constructor is called" << std::endl;
}

Fixed::Fixed(const float n) {
   value = std::roundf (n * 256.0f); // 2^8 = 256
   std::cout << "Float constructor is called" << std::endl;
}

float Fixed::toFloat(void) const {
    return ((float)value / 256.0f); // 2^8 = 256
}

int Fixed::toInt(void) const {
    return (value >> bits);
}

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (value);
}


std::ostream& operator<<(std::ostream& os,const Fixed & obj)
{
    os << obj.toFloat();
    return os;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}