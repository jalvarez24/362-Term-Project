// Authors: Royce Nguyen, Jayro Alvarez, Brian Trinh, Danny Pham
// Course: CPSC 362
// Filename: Booking.h
// Purpose: Holds flight number, account number, assigned seat, price paid
// Last updated: 7/31/2018

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
		Booking(string, int, int);
		
		// Getters
		int getBookingID();
		string getFlightNumber();
		int getAccountNumber();
		int getAssignedSeat();

		// Variables
		int bookingID;
		string flightNumber;
		int accountNumber;
		int assignedSeat;

	private:
		static int id;
};

#endif
