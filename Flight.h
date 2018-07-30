// Authors: Royce Nguyen, Jayro Alvarez, Brian Trinh, Danny Pham
// Course: CPSC 362
// Filename: Flight.h
// Purpose: Declares Flight class
// Last updated: 7/30/18

#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
#include <string>
using namespace std;

class Flight
{

	public:
		Flight();
		~Flight();
		Flight(string, string, string, int, int, int, int, int, int, int, int, char[], double);
		
		string getFlightNumber();
		int getDepartureTime();
		int getArrivalTime();
		string getDepartureLocation();
		string getArrivalLocation();
		void print();
		void displaySeats();
		double getprice();
		void addFlight(Flight);

	private:
		string flightNumber;
		string toLocation;
		string fromLocation;
		int departureMonth;
		int departureDay;
		int departureYear;
		int departureTime;
		int arrivalMonth;
		int arrivalDay;
		int arrivalYear;
		int arrivalTime;
		char seats[72];	
		double price;
};

#endif
