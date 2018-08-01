// Authors: Royce Nguyen, Jayro Alvarez, Brian Trinh, Danny Pham
// Course: CPSC 362
// Filename: Booking.cpp
// Last updated: 7/31/2018

#include "Booking.h"

int Booking::id = 1;

Booking::Booking(){}

Booking::~Booking(){}

Booking::Booking(string flightNum, int accountNum, int seat)
{
	bookingID = id;
	id++;
	flightNumber = flightNum;
	accountNumber = accountNum;
	assignedSeat = seat;
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
