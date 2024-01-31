/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:39:49 by azgaoua           #+#    #+#             */
/*   Updated: 2024/01/31 15:19:51 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

#ifndef FIXED_HPP
# define FIXED_HPP


class Fixed {
    private:
        int value;
        static const int bits;

    public:
        Fixed( void );
        Fixed(Fixed const& src);
        ~Fixed(void);
        Fixed &operator=(Fixed const& rhs);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        Fixed( const int n );
        Fixed( const float n );
        float toFloat( void ) const;
        int toInt (void ) const;
};
std::ostream& operator<<(std::ostream& os, const Fixed& obj);


#endif