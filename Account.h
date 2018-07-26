/*  Name: Danny Pham
	Course: CPSC 362
	Purpose: Holds user Account information*/

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
using namespace std;

class Account
{
public:
	Account();
	Account(string, string, string, string, string, string, string, string, string, string, char);

	~Account();

	void setAccountHolderName(string);
	void setPassword(string);
	void setCreditCardNum(string);
	void setCreditCardExpiration(string);
	void setBillingAddress(string);
	void setEmail(string);
	void setDateOfBirth(string);
	void setHomePhone(string);
	void setCellPone(string);
	
	int getID() const;
	string getName() const;

	void print() const;




private:
	int accountID;
	string userName;
	string password;
	string accountHolderName;
	string creditCardNum;
	string creditCardExpiration;
	string billingAddress;
	string email;
	string dateOfBirth;
	string homePhone;
	string cellPhone;
	char sex;

	static int id;
};

#endif
