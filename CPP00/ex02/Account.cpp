#include "Account.hpp"
#include <iomanip> //std::put_time localtime
#include <iostream> //std::cout

int Account::_nbAccounts = 0;

int Account::_totalAmount = 0;

int Account::_totalNbDeposits = 0;

int Account::_totalNbWithdrawals = 0;

Account::Account(int)
{
    Account::_displayTimestamp();
    std::cout << "index:" << Account::_nbAccounts << ";amount:" <<this->Account::_totalAmount;
    std::cout << ";created";
    std::cout << std::endl;
    Account::_nbAccounts++;
}

Account::~Account()
{

}



void Account::_displayTimestamp(void)
{
    time_t now; //time_t is a type to store the time

    now = time(0);
    std::cout  << std::put_time(std::localtime(&now), "[%Y%m%d_%H%M%S] "); //put_time formats the pointer now in YmdHMS        //localtime converts the time_t to a tm struct
}

void Account::displayAccountsInfos(void)
{
    Account::_displayTimestamp();
}



void Account::makeDeposit(int)
{

}

bool Account::makeWithdrawal(int)
{
    //code
    return(true);
}




void Account::displayStatus() const
{

}