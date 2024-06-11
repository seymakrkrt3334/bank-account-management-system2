#ifndef BANK_H
#define BANK_H
#include "Account.h"
#include <map>

class Bank {
private:
	map<long, Account> accounts;

public:
	Bank();
	Account openaccount(string fname, string lname, float balance);
	Account balanceenquiry(long accountnumber);
	Account deposit(long accountnumber, float amount);
	Account withdraw(long accountnumber, float amount);
	void closeaccount(long accountnumber);
	void showallaccounts();
	~Bank();
};

























#endif
