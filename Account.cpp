// Authors: Royce Nguyen, Jayro Alvarez, Brian Trinh, Danny Pham
// Course: CPSC 362
// Filename: Account.cpp
// Purpose: Holds user Account information
// Last updated: 7/31/2018


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
	//cout << "PW: " << password << endl;
	cout << "PW: ****" << endl;
}

void Account::addBooking(string _flightNum, int _accNum, int _seat)
{
	bookingslist.push_back(Booking(_flightNum, _accNum, _seat));
}
			       
void Account::reviewBookings() 
{
	cout << "\t\tREVIEWING FLIGHTS\n";
	//Review Bookings Header to align info. 
		cout << "Booking ID:\t" << "Flight#:\t" << "Seat:\n";

		//Print to screen: all bookings inside of bookingslist vector
		for (int x = 0; x < bookingslist.size(); x ++)
		{
			cout << bookingslist[x].bookingID << "\t\t" << bookingslist[x].flightNumber << "\t\t" << 
			seatIntToStr(bookingslist[x].assignedSeat) << endl;
		}
		cout << "==================================================" << endl;
}

void Account::printBooking(string flightNum, vector<Flight> flightList)
{
	int index = 0;

	// Match user input to reservation from booking vector
	for (int i = 0; i < bookingslist.size(); i++)
	{
		if (flightNum == bookingslist[i].getFlightNumber())
		{
			index = i;
		}
	}

	/*
	If booking vector contained flight, match to flight vector
	Print ticket using information contained in flight vector index
	*/
	for (int j = 0; j < flightList.size(); j++)
	{
		if (flightNum == flightList[j].getFlightNumber())
		{
			system("CLS");
			cout << "Here is your ticket.\n";
			cout << "====================================================================\n"
				<< "\tNortheast Airlines Ticket" << "\tFlight Number: " << flightList[j].getFlightNumber() << "\n\n"
				<< "\tPassenger: " << accountHolderName << "\t\tAccount ID: " << accountID << "\n\n"
				<< "\tFrom: " << flightList[j].getDepartureLocation() << "\tSeat: " << seatIntToStr(bookingslist[index].assignedSeat) << "\tDeparture Time: " << flightList[j].getDepartureTime() << "\n"
				<< "\tTo: " << flightList[j].getArrivalLocation() << "\t\t\t\tArrival Time: " << flightList[j].getArrivalTime() << "\n"
				<< "====================================================================\n\n";
		}
	}
}

void Account::cancelBooking(string flightNum, vector<Flight> & flightList)
{
	int index = 0;
	int bookingSeat = 0;

	// Match user input to reservation from booking vector
	for (int i = 0; i < bookingslist.size(); i++)
	{
		if (flightNum == bookingslist[i].getFlightNumber())
		{
			bookingSeat = bookingslist[i].getAssignedSeat();
			index = i;
		}
	}

	for (int j = 0; j < flightList.size(); j++)
	{
		if (flightNum == flightList[j].getFlightNumber())
		{
			bookingslist.erase(bookingslist.begin() + index);

			flightList[j].seats[bookingSeat] = '_';

			system("CLS");
			cout << "Your booking has been cancelled.\n"
				<< "Refund amount: " << flightList[j].getprice() << "\n\n";
		}
	}
}

bool Account::checkCC()
{ 
	if (creditCardNum != "N/A" && creditCardExpiration != "N/A")
	{
		return true;
	}
	else
		return false;
}
string Account::getCreditCardNum()
{
	return creditCardNum;
}

//takes in seat# as int in seating array, returns seat# as string version
//(i.e: input 0 => returns "A1")
//(i.e: input 71 => returns "D18")
//(i.e: input 4 => "A2"
string Account::seatIntToStr(int x)
{
	string seatstring = "";
	int seatnum = x + 1;

	if (x == 0 || x == 4 || x == 8 || x == 12 || x == 16 || x == 20 || x == 24 ||
		x == 28 || x == 32 || x == 36 || x == 40 || x == 44 || x == 48 || x == 52 ||
		x == 56 || x == 60 || x == 64 || x == 68)
	{
		seatstring += "A";
		if (x >= 4)
			seatnum = (seatnum / 4) + 1;
		seatstring += to_string(seatnum);
	}
	else if (x == 1 || x == 5 || x == 9 || x == 13 || x == 17 || x == 21 || x == 25 ||
		x == 29 || x == 33 || x == 37 || x == 41 || x == 45 || x == 49 || x == 53 ||
		x == 57 || x == 61 || x == 65 || x == 69)
	{
		seatstring += "B";
		if (x >= 5)
		{
			seatnum = (seatnum / 4) + 1;
			seatstring += to_string(seatnum);
		}
		else
			seatstring += to_string(seatnum - 1);
	}
	else if (x == 2 || x == 6 || x == 10 || x == 14 || x == 18 || x == 22 || x == 26 ||
		x == 30 || x == 34 || x == 38 || x == 42 || x == 46 || x == 50 || x == 54 ||
		x == 58 || x == 62 || x == 66 || x == 70)
	{
		seatstring += "C";
		if (x >= 6)
		{
			seatnum = (seatnum / 4) + 1;
			seatstring += to_string(seatnum);
		}
		else
			seatstring += to_string(seatnum - 2);
	}
	else
	{
		seatstring += "D";
		if (x >= 7)
		{
			seatnum = (x / 4) + 1;
			seatstring += to_string(seatnum);
		}
		else
			seatstring += to_string(seatnum - 3);
	}
	return seatstring;
}

bool Account::isBookingsEmpty()
{
	if (bookingslist.empty() == true)
		return true;
	else
		return false;
}
