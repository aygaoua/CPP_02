/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:37:59 by azgaoua           #+#    #+#             */
/*   Updated: 2024/01/31 16:15:17 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed() {
    value = 0;
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const& src) {
    // std::cout << "Copy constructor called" << std::endl;
    *this = src;
}


Fixed &Fixed::operator=(Fixed const& rhs) {
    // std::cout << "Copy assignment operator called" << std::endl;
    value = rhs.value;
    return (*this);
}

void Fixed::setRawBits( int const raw ) {
    value = raw;
}

Fixed::Fixed(const int n) {
    value = n << bits;
    // std::cout << "Int constructor is called" << std::endl;
}

Fixed::Fixed(const float n) {
    value = std::roundf(n * (1 << bits));
//    std::cout << "Float constructor is called" << std::endl;
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

bool Fixed::operator< (const Fixed& ComparedTo) {
    return value < ComparedTo.value;
}

bool Fixed::operator> (const Fixed& ComparedTo) {
    return value > ComparedTo.value;
}

bool Fixed::operator>= (const Fixed& ComparedTo) const {
    return value >= ComparedTo.value;
}

bool Fixed::operator<= (const Fixed& ComparedTo) const {
    return value <= ComparedTo.value;
}

bool Fixed::operator== (Fixed const &ComparedTo) {
    return value == ComparedTo.value;
}

bool Fixed::operator!= (Fixed const &ComparedTo) {
    return value != ComparedTo.value;
}

Fixed Fixed::operator+ (const Fixed& Right) {
    return Fixed(toFloat() + Right.toFloat());
}

Fixed Fixed::operator- (const Fixed& Right) {
    return Fixed(toFloat() - Right.toFloat());
}

Fixed Fixed::operator* (const Fixed& Right) {
    return Fixed(toFloat() * Right.toFloat());
}

Fixed Fixed::operator/ (const Fixed& Right) {
    return Fixed(toFloat() / Right.toFloat());
}

Fixed Fixed::operator++ ( int ) {
    Fixed temp = *this;

    ++value;
    return temp;
}

Fixed Fixed::operator++ () {
    value++;
    return *this;
}

Fixed Fixed::operator-- ( int ) {
    Fixed temp = *this;

    --value;
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a <= b) ? (Fixed&)(a) : (Fixed&)(b);
}

Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a >= b) ? (Fixed&)(a) : (Fixed&)(b);
}

Fixed Fixed::operator-- () {
    value--;
    return *this;
}

Fixed::~Fixed() {
    // std::cout << "Destructor called" << std::endl;
}