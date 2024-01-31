/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:04:03 by azgaoua           #+#    #+#             */
/*   Updated: 2024/01/31 13:34:13 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
    private:
        int value;
        static const int bits;

    public:
        Fixed( void );
        Fixed(Fixed const & src);
        Fixed &operator=(Fixed const &rhs);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
        ~Fixed( void );
};

#endif
