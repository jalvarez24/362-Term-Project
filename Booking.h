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
	int getAccountNumber();
	int getAssignedSeat();
	double getPrice();

private:
	string flightNumber;
	int accountNumber;
	int assignedSeat;
	double price;
};

#endif
