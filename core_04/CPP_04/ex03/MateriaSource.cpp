/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:31:52 by alimpens          #+#    #+#             */
/*   Updated: 2024/08/02 16:45:23 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		_materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	for (int i = 0; i < 4; i++)
	{
		if (src._materias[i])
		{
			if (this->_materias[i])
				delete this->_materias[i];

		_materias[i] = src._materias[i]->clone();
		}
		else
			_materias[i] = NULL;
	}
	std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &original)
{
	if (this != &original)
	{
		for (int i = 0; i < 4; i++)
		{
			if (original._materias[i])
			{
				if (this->_materias[i])
					delete this->_materias[i];
			}
			if (original._materias[i])
			{
				this->_materias[i] = original._materias[i]->clone();
			}
			else
				this->_materias[i] = NULL;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i])
			delete _materias[i];
	}
}

void MateriaSource::learnMateria(AMateria* materia)
{
	int i = 0;
	
	while (this->_materias[i] && i < 4)
		i++;
	if (i > 3 || i < 0)
	{
		std::cout << "MateriaSource is full" << std::endl;
		return;
	}
	this->_materias[i] = materia;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	int i = 0;
	while (i < 4 && this->_materias[i] && this->_materias[i]->getType() != type)
		i++;
	if (i > 3 || i < 0)
	{
		std::cout << "Materia not found" << std::endl;
		return (NULL);
	}
	return (this->_materias[i]->clone());
}
