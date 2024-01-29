/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:04:03 by azgaoua           #+#    #+#             */
/*   Updated: 2024/01/29 16:04:19 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

#ifndef FIXED_HPP
# define FIXED_HPP


class Fixed {
    private:
        int value;
        static const int bits = 8;

    public:
        Fixed(void);
        Fixed(Fixed const & src);
        Fixed &operator=(Fixed const &rhs);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
        ~Fixed(void);
};

#endif
