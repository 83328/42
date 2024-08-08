/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:57:15 by alimpens          #+#    #+#             */
/*   Updated: 2024/07/24 10:37:58 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
    private:
        std::string _type;
    public:
        Weapon();
        Weapon(std::string type);
        ~Weapon();
        const std::string &getType();
        void setType(std::string type);
};

#endif