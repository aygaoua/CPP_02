/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:04:23 by azgaoua           #+#    #+#             */
/*   Updated: 2024/01/28 19:42:45 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed& Fixed::operator=(Fixed const& rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	value = rhs.getRawBits();
	return *this;
}

Fixed::Fixed(Fixed const& src) {
    std::cout << "Copy constructor called" << std::endl;
	this->value = src.getRawBits();
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return value;
}

void Fixed::setRawBits(int const raw) {
    value = raw;
}

Fixed::Fixed(const int n) {
    value = n << bits;
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n) {
    value = roundf(n * (1 << bits));
    std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat(void) const {
    return (float)value / (1 << bits);
}

int Fixed::toInt(void) const {
    return (value >> bits);
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

