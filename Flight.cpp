#include "Flight.h"

Flight::Flight(){}

Flight::~Flight(){}

Flight::Flight(string flightNum, string toLoc, string fromLoc, int depMonth, int depDay, int depYear, int depTime, int arrMonth, int arrDay, int arrYear, int arrTime, char seating[], double _price) 
{
	flightNumber = flightNum;
	toLocation = toLoc;
	fromLocation = fromLoc;
	departureMonth = depMonth;
	departureDay = depDay;
	departureYear = depYear;
	departureTime = depTime;
	arrivalMonth = arrMonth;
	arrivalDay = arrDay;
	arrivalYear = arrYear;
	arrivalTime = arrTime;
	price = _price;
	for (int x = 0; x < 72; x++)
	{
		seats[x] = seating[x];
	}
	
}

string Flight::getFlightNumber() 
{
	return flightNumber;
}

int Flight::getDepartureTime()
{
	return departureTime;
}

int Flight::getArrivalTime() 
{
	return arrivalTime;
}

string Flight::getDepartureLocation()
{
	return fromLocation;
}

string Flight::getArrivalLocation()
{
	return toLocation;
}

void Flight::print()
{
	cout << flightNumber << "\t\t";
	cout << toLocation << "\t";
	cout << fromLocation << "\t";
	cout << departureMonth << "/" << departureDay << "/" << departureYear << " ";

	if (departureTime < 1000)
	{
		cout << "0" << departureTime << "\t";
	}
	else
	{
		cout << departureTime << "\t";
	}

	cout << arrivalMonth << "/" << arrivalDay << "/" << arrivalYear << " ";
	if (arrivalTime < 1000)
	{
		cout << "0" << arrivalTime << "\t";
	}
	else
	{
		cout << arrivalTime << "\t";
	}
	cout << endl;
}
void Flight::displaySeats() 
{
	cout << "\t\t\tROW#\n\t";
	cout << "1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18";
	cout << "\nS     A\t";
	//first 18 seats
	for (int x = 0; x < 18; x++)
	{
		if (seats[x] == 'X')
		{
			cout << "X  ";
		}
		else
			cout << "O  ";
	}
	cout << "\nE     B\t";
	for (int x = 18; x < 36; x++) 
	{
		if (seats[x] == 'X')
		{
			cout << "X  ";
		}
		else
			cout << "O  ";
	}
	cout << "\nA     C\t";
	for (int x = 36; x < 54; x++)
	{
		if (seats[x] == 'X')
		{
			cout << "X  ";
		}
		else
			cout << "O  ";
	}
	cout << "\nT     D\t";
	for (int x = 54; x < 72; x++) {
		if (seats[x] == 'X')
		{
			cout << "X  ";
		}
		else
			cout << "O  ";
	}
}

double Flight::getprice()
{
	return price;
}

void addFlight(Flight flight)
{
	flightList.push_back(flight);
}
