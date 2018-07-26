/*Name: Jayro Alvarez
Booking class holds:
-flight number, account number, assigned seat, price paid.
*/
#ifndef BOOKING_H
#define BOOKING_H

#include <iostream>
#include <string>
using namespace std;

class Booking
{
public:
	Booking();
	~Booking();
	Booking(string, string, int, double);
	string getFlightNumber();
	string getAccountNumber();
	int getAssignedSeat();

private:
	string flightNumber;
	string accountNumber;
	int assignedSeat;
	double price;
};

Booking::Booking(string flightNum, string accountNum, int seat, double _price)
{
	flightNumber = flightNum;
	accountNumber = accountNum;
	assignedSeat = seat;
	price = _price;
}

string Booking::getFlightNumber()
{
	return flightNumber;
}

string Booking::getAccountNumber()
{
	return accountNumber;
}

int Booking::getAssignedSeat()
{
	return assignedSeat;
}

#endif