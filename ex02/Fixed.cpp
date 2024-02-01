/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:37:59 by azgaoua           #+#    #+#             */
/*   Updated: 2024/02/01 21:31:01 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed() {
    value = 0;
    /* std::cout << "Default constructor called" << std::endl;*/
}

Fixed::Fixed(Fixed const& src) {
    /* std::cout << "Copy constructor called" << std::endl;*/
    *this = src;
}


Fixed &Fixed::operator=(Fixed const& rhs) {
    /* std::cout << "Copy assignment operator called" << std::endl;*/
    value = rhs.value;
    return (*this);
}

void Fixed::setRawBits( int const raw ) {
    value = raw;
}

Fixed::Fixed(const int n) {
    value = n << bits;
    /* std::cout << "Int constructor is called" << std::endl;*/
}

Fixed::Fixed(const float n) {
    value = std::roundf(n * (1 << bits));
    /*std::cout << "Float constructor is called" << std::endl;*/
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
std::ostream& operator<<(std::ostream& os,const Fixed& obj)
{
    os << obj.toFloat();
    return os;
}

/*---------------  Comparison operators  ---------------*/
bool 		Fixed::operator==(const Fixed& b) const {
    return (value == b.value);
}

bool 		Fixed::operator>(const Fixed& b) const {
    return value > b.value;
}

bool 		Fixed::operator>=(const Fixed& b) const {
    return value >= b.value;
}

bool 		Fixed::operator<=(const Fixed& b) const {
    return value <= b.value;
}

bool 		Fixed::operator<(const Fixed& b) const {
    return value < b.value;
}

bool 		Fixed::operator!=(const Fixed& b) const {
    return value != b.value;
}
/*------------------------------------------------------*/


/*---------------  Arithmetic operators  ---------------*/
Fixed 		Fixed::operator+(const Fixed &b) const {
    Fixed obj;

    obj.setRawBits(value + b.value);
    return obj;
}

Fixed 		Fixed::operator-(const Fixed &b) const {
    Fixed obj;

    obj.setRawBits(value - b.value);
    return obj;
}

Fixed 		Fixed::operator*(const Fixed &b) const {
    Fixed obj;

    obj.setRawBits((value * b.value) >> bits);
    return obj;
}

Fixed 		Fixed::operator/(const Fixed &b) const {
    Fixed obj;

    obj.setRawBits((value << bits) / b.value);
    return obj;
}
/*------------------------------------------------------*/


/*------------  (increment, decrement) operators  ------------*/
Fixed Fixed::operator++ ( int ) {
    Fixed temp = *this;

    ++value;
    return temp;
}

Fixed &Fixed::operator++ () {
    value++;
    return *this;
}

Fixed Fixed::operator--( int ) {
    Fixed temp = *this;

    --value;
    return temp;
}

Fixed &Fixed::operator--() {
    value--;
    return *this;
}
/*------------------------------------------------------------*/


/*------  (max, min) overloaded member functions -------*/
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? (Fixed&)a : (Fixed&)b;
}

Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? (Fixed&)a : (Fixed&)b;
}
/*------------------------------------------------------*/

Fixed::~Fixed() {
    /*std::cout << "Destructor called" << std::endl;*/
}
