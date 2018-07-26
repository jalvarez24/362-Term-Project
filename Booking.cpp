/*Name: Jayro Alvarez
Booking class holds:
-flight number, account number, assigned seat, price paid.
*/
#include "Booking.h"

Booking::Booking() 
{

}

Booking::~Booking()
{

}

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

double Booking::getPrice()
{
	return price;
}
