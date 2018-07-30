/*  Name: Danny Pham
	Course: CPSC 362
	Purpose: Holds user Account information*/

#include "Account.h"

int Account::id = 1;

Account::Account()
{
	accountID = id;
	id++;
	
	userName = "N/A";
	password = "N/A";
	accountHolderName = "N/A";
	creditCardNum = "N/A";
	creditCardExpiration = "N/A";
	billingAddress = "N/A";
	email = "N/A";
	dateOfBirth = "N/A";
	homePhone = "N/A";
	cellPhone = "N/A";
	sex = '0';
}

Account::Account(string _username, string _pw, string _name, string _ccn, string _cce, string _addr, string _email, string _dob, string _home, string _cell, string _sex)
{
	accountID = id;
	id++;

	userName = _username;
	password = _pw;
	accountHolderName = _name;
	creditCardNum = _ccn;
	creditCardExpiration = _cce;
	billingAddress = _addr;
	email = _email;
	dateOfBirth = _dob;
	homePhone = _home;
	cellPhone = _cell;
	sex = _sex;
}


Account::~Account()
{
}

void Account::setAccountHolderName(string _name)
{
	accountHolderName = _name;
}

void Account::setPassword(string _pw)
{
	password = _pw;
}

void Account::setCreditCardNum(string _num)
{
	creditCardNum = _num;
}

void Account::setCreditCardExpiration(string _exp)
{
	creditCardExpiration = _exp;
}

void Account::setBillingAddress(string _addr)
{
	billingAddress = _addr;
}

void Account::setEmail(string _email)
{
	email = _email;
}

void Account::setDateOfBirth(string _dob)
{
	dateOfBirth = _dob;
}

void Account::setHomePhone(string _home)
{
	homePhone = _home;
}

void Account::setCellPhone(string _cell)
{
	cellPhone = _cell;
}

int Account::getID() const
{
	return accountID;
}

string Account::getName() const
{
	return accountHolderName;
}

string Account::getUsername() const
{
	return userName;
}

bool Account::validatePassword(string _pw) const
{
	return password == _pw;
}


void Account::print() const
{
	cout << "Hello, " << accountHolderName << "!\tID: " << accountID << "\n";
	cout << "Addr: " << billingAddress << endl;
	cout << "Home Phone: " << homePhone << endl;
	cout << "Cell Phone: " << cellPhone << endl;
	cout << "Credit Card Num: " << creditCardNum << endl;
	cout << "Credit Card Exp: " << creditCardExpiration << endl;
	cout << "Email: " << email << endl;
	cout << "DOB: " << dateOfBirth << endl;
	cout << "Sex: " << sex << endl;
	cout << "Username: " << userName << endl;
	cout << "PW: " << password << endl;
}

void Account::addBooking(string _flightNum, int _accNum, int _seat)
{
	bookingslist.push_back(Booking(_flightNum, _accNum, _seat));
}
			       
void Account::reviewBookings() const
{
	//Review Bookings Header to align info. 
	cout << "Booking ID:\t" << "Flight#:\t" << "Seat:\n";

	//Print to screen: all bookings inside of bookingslist vector
	for (int x = 0; x < bookingslist.size(); x ++)
	{
		cout << bookingslist[x].bookingID << "\t\t" << bookingslist[x].flightNumber << "\t\t" << 
		bookingslist[x].assignedSeat << endl;
	}
}
