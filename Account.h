
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class InsufficientFunds{};

class Account {
private:
	long accountnumber;
	string firstname;
	string lastname;
	float balance;
	static long nextaccountnumber;
public:
	Account();
	Account(string fname, string lname, float balance);
	long getaccno();
	string getfirstname();
	string getlastname();
	float getbalance();


	void Deposit(float amount);
	void withdraw(float amount);
	static void setlastaccountnumber(long accountnumber);
	static long getlastaccountnumber();

	friend ofstream & operator<<(ofstream &ofs, Account& acc);
	friend ifstream& operator>>(ifstream &ifs, Account& acc);
	friend ostream& operator<<(ostream &os, Account& acc); 



};


#endif