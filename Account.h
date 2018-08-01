// Authors: Royce Nguyen, Jayro Alvarez, Brian Trinh, Danny Pham
// Course: CPSC 362
// Filename: Account.h
// Purpose: Holds user account information
// Last updated: 7/31/2018

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
#include <vector>
#include "Booking.h"
using namespace std;

class Account
{
	public:
		Account();
		Account(string, string, string, string, string, string, string, string, string, string, string);
		~Account();

		// Setters
		void setAccountHolderName(string);
		void setPassword(string);
		void setCreditCardNum(string);
		void setCreditCardExpiration(string);
		void setBillingAddress(string);
		void setEmail(string);
		void setDateOfBirth(string);
		void setHomePhone(string);
		void setCellPhone(string);
	
		// Getters
		int getID() const;
		string getName() const;
		string getUsername() const;
		string getCreditCardNum();

		// Functions
		bool validatePassword(string) const;
		void print() const;
		void addBooking(string, int, int);	
		void reviewBookings();
		bool checkCC();
		string seatIntToStr(int);
		bool isBookingsEmpty();
	
		vector<Booking> bookingslist;
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
		string sex;

		static int id;
};

#endif
