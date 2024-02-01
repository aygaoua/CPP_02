/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:37:56 by azgaoua           #+#    #+#             */
/*   Updated: 2024/02/01 21:33:36 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <cmath>

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
	private:
		int					value;
		static const int	bits;

	public:
	/*-------  Orthodox Canonical Form  -------*/
		Fixed			( void );
		Fixed			( Fixed const& src );
		Fixed&			operator =( Fixed const& rhs );
		~Fixed			(void);
	/*-----------------------------------------*/

		Fixed		( const int n );
		Fixed		( const float n );
		void		setRawBits( int const raw );
		int			getRawBits( void ) const;
		float		toFloat( void ) const;
		int 		toInt( void ) const;

	/*------------  Comparison operators  ------------*/
		bool 		operator==(const Fixed& b)	const;
		bool 		operator!=(const Fixed& b)	const;
		bool 		operator>(const Fixed& b)	const;
		bool 		operator>=(const Fixed& b)	const;
		bool 		operator<(const Fixed& b)	const;
		bool 		operator<=(const Fixed& b)	const;
	/*------------------------------------------------*/

	/*------------  Arithmetic operators  ------------*/
		Fixed 		operator+(const Fixed &b) const;
		Fixed 		operator-(const Fixed &b) const;
		Fixed 		operator/(const Fixed &b) const;
		Fixed 		operator*(const Fixed &b) const;
	/*------------------------------------------------*/

	/*------------  (increment, decrement) operators  ------------*/
		Fixed&		operator++();
		Fixed&		operator--();
		Fixed		operator++(int);
		Fixed		operator--(int);
	/*-----------------------------------------------------------*/

	/*------------  (max, min) overloaded member functions ------------*/
		static Fixed&	min( Fixed& a, Fixed& b );
		static Fixed&	max( Fixed& a, Fixed& b );
		static Fixed&	min( const Fixed& a, const Fixed& b );
		static Fixed&	max( const Fixed& a, const Fixed& b );
	/*-----------------------------------------------------------------*/

};

std::ostream& 			operator<<(std::ostream& os,const Fixed & obj);

#endif