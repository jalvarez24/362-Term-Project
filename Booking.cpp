/*Name: Jayro Alvarez
Booking class holds:
-flight number, account number, assigned seat, price paid.
*/
#include "Booking.h"

int Booking::id = 1;

Booking::Booking(){}

Booking::~Booking(){}

Booking::Booking(string flightNum, int accountNum, int seat, double _price)
{
	bookingID = id;
	id++;
	flightNumber = flightNum;
	accountNumber = accountNum;
	assignedSeat = seat;
	price = _price;
}

int Booking::getBookingID()
{
	return bookingID;
}

string Booking::getFlightNumber()
{
	return flightNumber;
}

int Booking::getAccountNumber()
{
	return accountNumber;
}

int Booking::getAssignedSeat()
{
	return assignedSeat;
}

double Booking::getPrice()
{
	return price;
}
