// Authors: Royce Nguyen, Jayro Alvarez, Brian Trinh, Danny Pham
// Course: CPSC 362
// Filename: Flight.cpp
// Last updated: 7/30/18

#include "Flight.h"

Flight::Flight(){}
Flight::~Flight(){}

// Constructor
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

// Getter functions
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
	/*cout << "\t\t\tROW#\n\t";
	cout << "1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18";
	cout << "\nS     A\t";

	// First 18 seats
	for (int i = 0; i < 18; i++)
	{
		if (seats[i] == 'X')
		{
			cout << "[X]  ";
		}
		else
			cout << "[O]  ";
	}

	cout << "\nE     B\t";
	for (int i = 18; i < 36; i++) 
	{
		if (seats[i] == 'X')
		{
			cout << "[X]  ";
		}
		else
			cout << "[O]  ";
	}

	cout << "\nA     C\t";
	for (int i = 36; i < 54; i++)
	{
		if (seats[i] == 'X')
		{
			cout << "[X]  ";
		}
		else
			cout << "[O]  ";
	}

	cout << "\nT     D\t";
	for (int i = 54; i < 72; i++) 
	{
		if (seats[i] == 'X')
		{
			cout << "[X]  ";
		}
		else
			cout << "[O]  ";
	}*/

	cout << "\t\t  RESERVE SEAT(S)" << endl << endl;
	cout << "\t\t    A B\t  C D" << endl;
	cout << "\t\t1   ";
	for (int i = 0; i < 4; i++)
	{
		if (seats[i] == 'X')
		{
			cout << "X ";
			if (i == 1)
			{
				cout << "  ";
			}
		}
		else
		{
			cout << "_ ";
			if (i == 1)
			{
				cout << "  ";
			}
		}
	}

	cout << "\n\t\t2   ";
	for (int i = 4; i < 8; i++)
	{
		if (seats[i] == 'X')
		{
			cout << "X ";
			if (i == 5)
			{
				cout << "  ";
			}
		}
		else
		{
			cout << "_ ";
			if (i == 5)
			{
				cout << "  ";
			}
		}
	}

	cout << "\n\t\t3   ";
	for (int i = 8; i < 12; i++)
	{
		if (seats[i] == 'X')
		{
			cout << "X ";
			if (i == 9)
			{
				cout << "  ";
			}
		}
		else
		{
			cout << "_ ";
			if (i == 9)
			{
				cout << "  ";
			}
		}
	}

	cout << "\n\t\t4   ";
	for (int i = 12; i < 16; i++)
	{
		if (seats[i] == 'X')
		{
			cout << "X ";
			if (i == 13)
			{
				cout << "  ";
			}
		}
		else
		{
			cout << "_ ";
			if (i == 13)
			{
				cout << "  ";
			}
		}
	}

	cout << "\n\t\t5   ";
	for (int i = 16; i < 20; i++)
	{
		if (seats[i] == 'X')
		{
			cout << "X ";
			if (i == 17)
			{
				cout << "  ";
			}
		}
		else
		{
			cout << "_ ";
			if (i == 17)
			{
				cout << "  ";
			}
		}
	}

	cout << "\n\t\t6   ";
	for (int i = 20; i < 24; i++)
	{
		if (seats[i] == 'X')
		{
			cout << "X ";
			if (i == 21)
			{
				cout << "  ";
			}
		}
		else
		{
			cout << "_ ";
			if (i == 21)
			{
				cout << "  ";
			}
		}
	}
	
	cout << "\n\t\t7   ";
	for (int i = 24; i < 28; i++)
	{
		if (seats[i] == 'X')
		{
			cout << "X ";
			if (i == 25)
			{
				cout << "  ";
			}
		}
		else
		{
			cout << "_ ";
			if (i == 25)
			{
				cout << "  ";
			}
		}
	}

	cout << "\n\t\t8   ";
	for (int i = 28; i < 32; i++)
	{
		if (seats[i] == 'X')
		{
			cout << "X ";
			if (i == 29)
			{
				cout << "  ";
			}
		}
		else
		{
			cout << "_ ";
			if (i == 29)
			{
				cout << "  ";
			}
		}
	}

	cout << "\n\t\t9   ";
	for (int i = 32; i < 36; i++)
	{
		if (seats[i] == 'X')
		{
			cout << "X ";
			if (i == 33)
			{
				cout << "  ";
			}
		}
		else
		{
			cout << "_ ";
			if (i == 33)
			{
				cout << "  ";
			}
		}
	}

	cout << "\n\t\t10  ";
	for (int i = 36; i < 40; i++)
	{
		if (seats[i] == 'X')
		{
			cout << "X ";
			if (i == 37)
			{
				cout << "  ";
			}
		}
		else
		{
			cout << "_ ";
			if (i == 37)
			{
				cout << "  ";
			}
		}
	}

	cout << "\n\t\t11  ";
	for (int i = 40; i < 44; i++)
	{
		if (seats[i] == 'X')
		{
			cout << "X ";
			if (i == 41)
			{
				cout << "  ";
			}
		}
		else
		{
			cout << "_ ";
			if (i == 41)
			{
				cout << "  ";
			}
		}
	}

	cout << "\n\t\t12  ";
	for (int i = 44; i < 48; i++)
	{
		if (seats[i] == 'X')
		{
			cout << "X ";
			if (i == 45)
			{
				cout << "  ";
			}
		}
		else
		{
			cout << "_ ";
			if (i == 45)
			{
				cout << "  ";
			}
		}
	}
	
	cout << "\n\t\t13  ";
	for (int i = 48; i < 52; i++)
	{
		if (seats[i] == 'X')
		{
			cout << "X ";
			if (i == 49)
			{
				cout << "  ";
			}
		}
		else
		{
			cout << "_ ";
			if (i == 49)
			{
				cout << "  ";
			}
		}
	}

	cout << "\n\t\t14  ";
	for (int i = 52; i < 56; i++)
	{
		if (seats[i] == 'X')
		{
			cout << "X ";
			if (i == 53)
			{
				cout << "  ";
			}
		}
		else
		{
			cout << "_ ";
			if (i == 53)
			{
				cout << "  ";
			}
		}
	}

	cout << "\n\t\t15  ";
	for (int i = 56; i < 60; i++)
	{
		if (seats[i] == 'X')
		{
			cout << "X ";
			if (i == 57)
			{
				cout << "  ";
			}
		}
		else
		{
			cout << "_ ";
			if (i == 57)
			{
				cout << "  ";
			}
		}
	}

	cout << "\n\t\t16  ";
	for (int i = 60; i < 64; i++)
	{
		if (seats[i] == 'X')
		{
			cout << "X ";
			if (i == 61)
			{
				cout << "  ";
			}
		}
		else
		{
			cout << "_ ";
			if (i == 61)
			{
				cout << "  ";
			}
		}
	}

	cout << "\n\t\t17  ";
	for (int i = 64; i < 68; i++)
	{
		if (seats[i] == 'X')
		{
			cout << "X ";
			if (i == 65)
			{
				cout << "  ";
			}
		}
		else
		{
			cout << "_ ";
			if (i == 65)
			{
				cout << "  ";
			}
		}
	}

	cout << "\n\t\t18  ";
	for (int i = 68; i < 72; i++)
	{
		if (seats[i] == 'X')
		{
			cout << "X ";
			if (i == 69)
			{
				cout << "  ";
			}
		}
		else
		{
			cout << "_ ";
			if (i == 69)
			{
				cout << "  ";
			}
		}
	}
	cout << endl;
}

double Flight::getprice()
{
	return price;
}

string Flight::getDepartureDate()
{
	string date = "";
	date += to_string(departureMonth);
	date += "/";
	date += to_string(departureDay);
	date += "/";
	date += to_string(departureYear);
	return date;
}

string Flight::getArrivalDate()
{
	string date = "";
	date += to_string(arrivalMonth);
	date += "/";
	date += to_string(arrivalDay);
	date += "/";
	date += to_string(arrivalYear);
	return date;
}

