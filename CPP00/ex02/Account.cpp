#include "Account.hpp"
#include <iomanip> //std::put_time localtime
#include <iostream> //std::cout

int Account::_nbAccounts = 0;

int Account::_totalAmount = 0;

int Account::_totalNbDeposits = 0;

int Account::_totalNbWithdrawals = 0;

Account::Account(int intial_amount) //constructor to assign the amount to the account
{
    std::cout << "constructor";
    this->_amount = intial_amount;
    this->_accountIndex = Account::_nbAccounts;
    Account::_totalAmount += intial_amount;

    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << intial_amount;
    std::cout << ";created";
    std::cout << std::endl;
    Account::_nbAccounts++;
}

Account::~Account()
{
    std::cout << "destructor";
    Account::_displayTimestamp();
    std::cout << "index:" <<this->_accountIndex;
    std::cout << ";amount:" << this->_amount;
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
    std::cout << "account" << Account::_nbAccounts; 
    std::cout << ";total:" << Account::_totalAmount;
    std::cout << ";deposits:" << Account::_totalNbDeposits;
    std::cout << ";withdrawals:" << Account::_totalNbWithdrawals;
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
    //this->_nbAccounts++;

}

bool Account::makeWithdrawal(int withdrawal)
{
    std::cout << "make withdrawal";
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex;
    std::cout << ";p_amount:" << this->_amount;
    std::cout << ";withdrawal:";
    if (withdrawal > this->_amount)
    {
        std::cout << "refused";
        std::cout << std::endl;
        return(false);
    }
    this->_nbWithdrawals++;
    Account::_totalNbWithdrawals++;
    std::cout << withdrawal << ";amount:" << this->_amount - withdrawal;
    std::cout << ";nb_withdrawals:" << this->_nbWithdrawals;
    std::cout << std::endl;
    return(true);
}

void Account::displayStatus() const
{
    std::cout << "display status";
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex;
    std::cout << ";amount:" << this->_amount;
    std::cout << ";deposits:" << this->_nbDeposits;
    std::cout << ";withdrawals:" << this->_nbWithdrawals;
    std::cout << std::endl;
}