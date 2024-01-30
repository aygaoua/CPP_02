/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:37:56 by azgaoua           #+#    #+#             */
/*   Updated: 2024/01/30 02:32:01 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <cmath>

#ifndef FIXED_HPP
#define FIXED_HPP
#define EPSILON 1.0e-7f


class Fixed {
    private:
        int value;
        static const int bits = 8;

    public:
        Fixed( void );
        Fixed( Fixed const& src );
        ~Fixed(void);
        Fixed &operator=( Fixed const& rhs );
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        Fixed( const int n );
        Fixed( const float n );
        float toFloat( void ) const;
        int toInt( void ) const;
        bool operator< ( const Fixed& ComparedTo );
        bool operator<= ( const Fixed& ComparedTo ) const;
        bool operator> ( const Fixed& ComparedTo );
        bool operator>= ( const Fixed& ComparedTo ) const;
        bool operator== ( const Fixed& ComparedTo );
        bool operator!= ( const Fixed& ComparedTo );
        Fixed operator+ ( const Fixed& Right );
        Fixed operator- ( const Fixed& Right );
        Fixed operator* ( const Fixed& Right );
        Fixed operator/ ( const Fixed& Right );
        Fixed operator++ ( int n );
        Fixed operator++ ( void );
        Fixed operator-- ( int n );
        Fixed operator-- ( void );
        static Fixed& min( Fixed& a, Fixed& b );
        static Fixed& max( Fixed& a, Fixed& b );
        static Fixed& min( const Fixed& a, const Fixed& b );
        static Fixed& max( const Fixed& a, const Fixed& b );
};

std::ostream& operator<<(std::ostream& os,const Fixed & obj);

#endif