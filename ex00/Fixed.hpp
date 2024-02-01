/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:04:03 by azgaoua           #+#    #+#             */
/*   Updated: 2024/02/01 10:54:42 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int					value;
		static const int	bits;

	public:
	/*-------  Orthodox Canonical Form  -------*/
		Fixed		( void );
		Fixed		(Fixed const & src);
		Fixed&		operator =(const Fixed& b);
		~Fixed		( void );
	/*-----------------------------------------*/
		int			getRawBits( void ) const;
		void		setRawBits( int const raw );
};

#endif
