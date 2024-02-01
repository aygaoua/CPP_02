/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:27:04 by azgaoua           #+#    #+#             */
/*   Updated: 2024/02/01 13:11:22 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const& src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed &Fixed::operator=(Fixed const& b) {
	if (this != &b)
		return (*this);
	std::cout << "Copy assignment operator called" << std::endl;
	value = b.value;
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
	value = std::roundf (n * (1 << bits));
	std::cout << "Float constructor is called" << std::endl;
}

float Fixed::toFloat(void) const {
	return ((float)value / (1 << bits));
}

int Fixed::toInt(void) const {
	return (value >> bits);
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (value);
}


std::ostream& operator<<(std::ostream& os,const Fixed & obj) {
	os << obj.toFloat();
	return os;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}
