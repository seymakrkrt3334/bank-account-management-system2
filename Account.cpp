#include "Account.h"
#define MIN_BALANCE 500
long Account::nextaccountnumber = 0;

Account::Account() {}

Account::Account(string fname, string lname, float balance) {
    nextaccountnumber++;
    accountnumber = nextaccountnumber;
    firstname = fname;
    lastname = lname;
    this->balance = balance;
}

long Account::getaccno() {
    return accountnumber;
}

string Account::getfirstname() {
    return firstname;
}

string Account::getlastname() {
    return lastname;
}

float Account::getbalance() {
    return balance;
}

void Account::withdraw(float amount) {
    if (balance - amount < MIN_BALANCE) {
        throw InsufficientFunds();
    }
    balance -= amount;
}

void Account::Deposit(float amount) {
    balance += amount;
}

void Account::setlastaccountnumber(long accountnumber) {
    nextaccountnumber = accountnumber;
}

long Account::getlastaccountnumber() {
    return nextaccountnumber;
}

ofstream& operator<<(ofstream& ofs, Account& acc) {
    ofs << acc.accountnumber << endl;
    ofs << acc.firstname << endl;
    ofs << acc.lastname << endl;
    ofs << acc.balance << endl;
    return ofs;
}

ifstream& operator>>(ifstream& ifs, Account& acc) {
    ifs >> acc.accountnumber;
    ifs >> acc.firstname;
    ifs >> acc.lastname;
    ifs >> acc.balance;
    return ifs;
}

ostream& operator<<(ostream& os, Account& acc) {
    os << "First name: " << acc.getfirstname() << endl;
    os << "Last name: " << acc.getlastname() << endl;
    os << "Account Number:" << acc.getaccno() << endl;
    os << "Balance:" << acc.getbalance() << endl;
    return os;
}