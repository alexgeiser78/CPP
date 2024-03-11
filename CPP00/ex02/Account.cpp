

#include "Account.hpp"
#include <iomanip> //std::put_time localtime
#include <iostream> //std::cout

int Account::_nbAccounts = 0;

int Account::_totalAmount = 0;

int Account::_totalNbDeposits = 0;

int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) //constructor to assign the amount to the account
{
    std::cout << "constructor";
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    this->_accountIndex = this->getNbAccounts();
    this->_amount = initial_deposit;
    Account::_totalAmount += initial_deposit;
    
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex;
    std::cout << ";amount:" << this-> checkAmount();
    std::cout << ";created";
    std::cout << std::endl;
    Account::_nbAccounts++;
}

Account::~Account()
{
   std::cout << "destructor";
	//Account::_nbAccounts--;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
    std::cout << ";amount:" << this->checkAmount();
    std::cout << ";closed";
    std::cout << std::endl;
    Account::_nbAccounts--;
}


    


void Account::_displayTimestamp(void)
{
    time_t now; //time_t is a type to store the time

    now = time(0);
    std::cout  << std::put_time(std::localtime(&now), "[%Y%m%d_%H%M%S] "); //put_time formats the pointer now in YmdHMS        //localtime converts the time_t to a tm struct
}

void Account::displayAccountsInfos(void)
{
    std::cout << "display accounts infos";
    Account::_displayTimestamp();
    std::cout << "account" << Account::getNbAccounts(); 
    std::cout << ";total:" << Account::getTotalAmount();
    std::cout << ";deposits:" << Account::getNbDeposits();
    std::cout << ";withdrawals:" << Account::getNbWithdrawals();
    std::cout << std::endl;
}

void Account::makeDeposit(int deposit)
{
    std::cout << "make deposit";
    this->_nbDeposits++; //increment the number of deposits
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex;
    std::cout << ";p_amount:" << this->_amount;
    std::cout << ";deposit:" << deposit;
    std::cout << ";amount:" << this->_amount + deposit;
    std::cout << ";nb_deposits:" << this->_nbDeposits;
    std::cout << std::endl;
    this->_amount += deposit; //add the deposit to the amount
    Account::_totalNbDeposits++; //increment the total number of deposits
    Account::_totalAmount += deposit; //add the deposit to the total amount
    
    //this->_nbAccounts++;

}

bool Account::makeWithdrawal(int withdrawal)
{
    std::cout << "make withdrawal";
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex;
    std::cout << ";p_amount:" << this->_amount;
    std::cout << ";withdrawal:";
    if (withdrawal > this->checkAmount())
    {
        std::cout << "refused";
        std::cout << std::endl;
        return(false);
    }
    this->_nbWithdrawals++;
    Account::_totalNbWithdrawals++;
    std::cout << withdrawal << ";amount:" << this->checkAmount() - withdrawal;
    std::cout << ";nb_withdrawals:" << this->_nbWithdrawals;
    std::cout << std::endl;
    this->_amount -= withdrawal;
    Account::_totalAmount -= withdrawal;
    return(true);
}

void Account::displayStatus() const
{
    std::cout << "display status";
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex;
    std::cout << ";amount:" << this->checkAmount();
    std::cout << ";deposits:" << this->_nbDeposits;
    std::cout << ";withdrawals:" << this->_nbWithdrawals;
    std::cout << std::endl;
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int	Account::checkAmount(void) const
{
	return (this->_amount);
}

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}




