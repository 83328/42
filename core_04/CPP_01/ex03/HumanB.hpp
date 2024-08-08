/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:58:59 by alimpens          #+#    #+#             */
/*   Updated: 2024/07/24 10:37:44 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
    private:
        Weapon *_weapon;
        std::string _name;
    public:
        HumanB();
        HumanB(std::string name);
        void setWeapon(Weapon &weapon);
        void attack();
        ~HumanB();
};

#endif