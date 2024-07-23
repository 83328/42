/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:46:36 by alimpens          #+#    #+#             */
/*   Updated: 2024/07/22 15:12:28 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
# include <string>
# include <iostream>
# include <iomanip>
# include <cctype>
# include <cstdlib>
# include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{

	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_accountIndex = _nbAccounts++;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	
	Account::_displayTimestamp();
	
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();

	
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
}

int Account::checkAmount(void) const
{
	return(_amount);
}

int Account::getNbAccounts(void) 
{
	return (Account::_nbAccounts);
}

int Account::getTotalAmount(void) 
{
	return (Account::_totalAmount);
}

int Account::getNbDeposits(void) 
{
	return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals(void) 
{
	return (Account::_totalNbWithdrawals);
}

void    Account::displayStatus(void) const
{
	_displayTimestamp();

	
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

void    Account::displayAccountsInfos(void)
{
	_displayTimestamp();

	
	std::cout << " accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void    Account::makeDeposit(int deposit)
{
	_nbDeposits = 0;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "deposit:" << deposit << ";";

	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits += 1;
	_nbDeposits += 1;

	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

bool    Account::makeWithdrawal(int withdrawal)
{
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	
	if (_amount < withdrawal)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (0);
	}

	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals += 1;
	_nbWithdrawals += 1;

	std::cout << "withdrawal:" << withdrawal << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;

	return (1);
}

void    Account::_displayTimestamp()
{
	std::time_t currentTime;
	std::time (&currentTime);
	
	std::tm* localTime = std::localtime(&currentTime);

	char    timeBuffer[20];

	std::strftime(timeBuffer, sizeof(timeBuffer),"%Y%m%d_%H%M%S", localTime);

	std::cout << "[" << timeBuffer << "]";
}
