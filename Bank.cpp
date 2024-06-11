#include "Bank.h"
#include <fstream>

Bank::Bank() {
	Account account;
	ifstream infile;

	infile.open("Database.txt");

	if (!infile) {
		return;
	}

	while (!infile.eof()) {
		infile >> account;
		accounts.insert(pair<long, Account>(account.getaccno(), account));

	}
	Account::setlastaccountnumber(account.getaccno());

	infile.close();

}

Account Bank::openaccount(string fname, string lname, float balance) {
	ofstream outfile;

	Account account(fname, lname, balance);
	accounts.insert(pair<long, Account>(account.getaccno(), account));
	outfile.open("Database.txt", ios::trunc);
	map<long, Account>::iterator itr;
	for (itr = accounts.begin(); itr != accounts.end(); itr++) {
		outfile << itr->second;
	}
	outfile.close();
	return account;

}

Account Bank::balanceenquiry(long accountnumber) {
	map<long, Account>::iterator itr = accounts.find(accountnumber);
	return itr->second;
}

Account Bank::deposit(long accountnumber, float amount) {
	map<long, Account>::iterator itr = accounts.find(accountnumber);
	itr->second.Deposit(amount);
	return itr->second;
}

Account Bank::withdraw(long accountnumber, float amount) {
	map<long, Account>::iterator itr = accounts.find(accountnumber);
	itr->second.withdraw(amount);
	return itr->second;
}

void Bank::closeaccount(long accountnumber){
	map<long,Account>::iterator itr =accounts.find(accountnumber);
cout << "Account deleted" << itr->second;
accounts.erase(accountnumber);
	
	}

void Bank::showallaccounts() {
	map<long, Account>::iterator itr;
	for (itr = accounts.begin(); itr != accounts.end(); itr++) {
		cout << "Account " << itr->first << endl << itr->second << endl;

	}
}

Bank::~Bank() {
	ofstream outfile;
	outfile.open("Database.txt", ios::trunc);

	map<long, Account>::iterator itr;
	for (itr = accounts.begin(); itr != accounts.end(); itr++) {
		outfile << itr->second;
	}
	outfile.close();

}