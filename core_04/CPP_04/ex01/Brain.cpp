/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:55:24 by alimpens          #+#    #+#             */
/*   Updated: 2024/08/02 11:31:55 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &to_copy)
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = to_copy;
}

Brain &Brain::operator=(const Brain &original)
{
    if (this != &original)
    {
        for (size_t i = 0; i < 100; i++)
            this->_ideas[i] = original._ideas[i];
    }
    std::cout << "Brain assignment operator called" << std::endl;
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}
