/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Account.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bewong <bewong@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/08 15:34:17 by bewong        #+#    #+#                 */
/*   Updated: 2025/04/10 09:33:33 by bewong        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	this->_accountIndex = _nbAccounts;
	_nbAccounts++;
	this->_amount = initial_deposit;
	_totalAmount += initial_deposit;
	std::cout << "index:" << _accountIndex << ";amount:"
				<< _amount << ";created" << std::endl;
	return ;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:"
				<< _amount << ";closed" << std::endl;
	return ;
}

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::_displayTimestamp(void)
{
	std::time_t	now;
	std::tm		*ltm;

	now = std::time(0);
	ltm = std::localtime(&now);
	std::cout << "["
			  << std::setfill('0') << std::setw(4) << 1900 + ltm->tm_year
			  << std::setw(2) << ltm->tm_mon + 1
			  << std::setw(2) << ltm->tm_mday << "_"
			  << std::setw(2) << ltm->tm_hour
			  << std::setw(2) << ltm->tm_min
			  << std::setw(2) << ltm->tm_sec
			  << "]";
}
void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts()
				<< ";total:" << getTotalAmount()
				<< ";deposits:" << getNbDeposits()
				<< ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->checkAmount();
	std::cout << ";deposit:" << deposit;
	this->_amount += deposit;
	_totalAmount += deposit;
	this->_nbDeposits++;
	_totalNbDeposits++;
	std::cout << ";amount:" << this->checkAmount();
	std::cout << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->checkAmount();
	if (withdrawal > this->checkAmount())
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	else
	{
		std::cout << ";withdrawal:" << withdrawal;
		_totalAmount -= withdrawal;
		this->_amount -= withdrawal;
		_totalNbWithdrawals++;
		this->_nbWithdrawals++;
		std::cout << ";amount:" << this->checkAmount();
		std::cout << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return (true);
	}
}

int	Account::checkAmount(void) const
{
	return (this->_amount);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
				<< ";amout:" << this->checkAmount()
				<< ";deposits:" << this->_nbDeposits
				<< ";withdrawals:" << this->_nbWithdrawals << std::endl;
	
}
