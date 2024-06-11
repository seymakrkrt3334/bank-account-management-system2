#include<iostream>
#include "Bank.h"
#include "Account.h"
using namespace std;

int main() {
	Bank b;
	Account acc;
	int choice;
	long accountnumber;
	string fname, lname;
	float balance;
	float amount;

	cout << "***Banking System***" << endl;
	do {
		cout << "\n\tSelect one option below:";
		cout << "\n\t1 Open an Account";
		cout << "\n\t2 Balance Enquiry";
		cout << "\n\t3 Deposit";
		cout << "\n\t4 Withdrawal";
		cout << "\n\t5 Close an Account";
		cout << "\n\t6 Show all Accounts";
		cout << "\n\t7 Quit";
		cout << "Enter your choice:";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Enter first Name:";
			cin >> fname;
			cout << "Enter last name:";
			cin >> lname;
			cout << "Enter initial balance:";
			cin >> balance;
			acc = b.openaccount(fname, lname, balance);
			cout << endl << "Congratulations Account is Created" << endl;
			cout << acc;
			break;


		case 2:
			cout << "Enter Account number:";
			cin >> accountnumber;
			acc = b.balanceenquiry(accountnumber);
			cout << endl << "Your Account Details" << endl;
			cout << acc;
			break;


		case 3:
			cout << "Enter Account number:";
			cin >> accountnumber;
			cout << "Enter balance:";
			cin >> amount;
			acc = b.deposit(accountnumber, amount);
			cout << endl << "Amount is deposited" << endl;
			cout << acc;
			break;

		case 4:
			cout << "Enter Account number:";
			cin >> accountnumber;
			cout << "Enter balance:";
			cin >> amount;
			acc = b.withdraw(accountnumber, amount);
			cout << endl << "Amount Withdrawn" << endl;
			cout << acc;
			break;

		case 5:
			cout << "Enter Account Number:";
			cin >> accountnumber;
			b.closeaccount(accountnumber);
			cout << endl << "Account is closed" << endl;
			break;

		case 6:
			b.showallaccounts();
			break;

		case 7:
			break;
		default:
			cout << "\nEnter correct choice";
			exit(0);
		}
	} while (choice != 7);

	return 0;
}