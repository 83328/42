/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:58:28 by alimpens          #+#    #+#             */
/*   Updated: 2024/07/24 10:37:51 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	private:
		Weapon &_weapon;
		std::string _name;
	public:
		void attack();
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
};

#endif