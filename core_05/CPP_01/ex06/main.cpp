/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:01:02 by alimpens          #+#    #+#             */
/*   Updated: 2024/07/24 12:18:49 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Usage: ./harlFilter <LEVEL>\n";
		return (1);
	}
	Harl harl;
	harl.harlFilter(argv[1]);
	return (0);
}
