/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:39:49 by azgaoua           #+#    #+#             */
/*   Updated: 2024/02/01 10:56:00 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

#ifndef FIXED_HPP
# define FIXED_HPP


class Fixed {
	private:
		int					value;
		static const int	bits;

	public:
	/*-------  Orthodox Canonical Form  -------*/
		Fixed		( void );
		Fixed		(Fixed const& src);
		Fixed&		operator =(const Fixed& b);
		~Fixed		(void);
	/*-----------------------------------------*/
		int			getRawBits( void ) const;
		void		setRawBits( int const raw );
		Fixed		( const int n );
		Fixed		( const float n );
		float		toFloat( void ) const;
		int			toInt (void ) const;
};

std::ostream&	operator<<(std::ostream& os, const Fixed& obj);


#endif