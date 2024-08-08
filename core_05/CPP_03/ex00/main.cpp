/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:48:22 by alimpens          #+#    #+#             */
/*   Updated: 2024/07/29 12:06:19 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* int main()
{
	ClapTrap ct("Monster");

	ct.attack("Innocent victim 1");
	ct.takeDamage(5);
	ct.beRepaired(3);
	ct.attack("Innocent victim 2");
	ct.takeDamage(10);
	ct.beRepaired(5);

	return 0;
} */
int main(void) 
{
	ClapTrap aaa("Monster 1");
	ClapTrap bbb("Monster 2");
	std::cout << '\n';
	aaa.beRepaired(3);
	std::cout << '\n';
	aaa.attack("Monster 2");
	std::cout << '\n';
	bbb.takeDamage(4);
	std::cout << '\n';
	aaa.attack("Monster 2");
	std::cout << '\n';
	bbb.takeDamage(6);
	std::cout << '\n';
	bbb.attack("Monster 1");
	std::cout << '\n';
	aaa.takeDamage(0);
	std::cout << '\n';
	aaa.attack("Monster 2");
	std::cout << '\n';
	bbb.takeDamage(4);
	std::cout << '\n';
	return (0);
}
