// Name: Royce Nguyen
// Course: CPSC 362
// Purpose: Finding current flights, selecting seats

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Flight
{
	public:
		Flight();
		//~Flight();
		Flight(string, string, string, int, int, int, int, int, int, int, int);
		void getFlightNumber();
		void getDepartureTime();
		void getArrivalTime();
		void getDepartureLocation();
		void getArrivalLocation();
		void print();
		void displaySeats();
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
		char seats[20][6];
};

void printHeader()
{
	cout << "FLIGHT NUMBER\tTO\tFROM\tDEPARTURE DATE\tARRIVAL DATE\tAVAILABLESEATS\n";
	cout << "--------------------------------------------------------------------------------------\n";
}

void Flight::print()
{
	cout << flightNumber << "\t";
	cout << toLocation << "\t";
	cout << fromLocation << "\t";
	cout << departureMonth << "/" << departureDay << "/" << departureYear << "/" << " ";
	
	if (departureTime < 1000)
	{
		cout << "0" << departureTime << "\t";
	}
	else
	{
		cout << departureTime << "\t";
	}

	cout << arrivalMonth << "/" << arrivalDay << "/" << arrivalYear << "/" << " ";
	if (arrivalTime < 1000)
	{
		cout << "0" << arrivalTime << "\t";
	}
	else
	{
		cout << arrivalTime << "\t";
	}
}

int main()
{
	char seating[20][6] = { 'X', 'X', 'O', 'X', 'O', 'X',
		'X', 'O', 'O', 'O', 'X', 'O',
		'O', 'O', 'O', 'O', 'O', 'O',
		'O', 'O', 'O', 'O', 'O', 'O',
		'X', 'X', 'O', 'O', 'X', 'X',
		'O', 'X', 'O', 'X', 'X', 'X',
		'X', 'X', 'X', 'O', 'X', 'O',
		'O', 'X', 'O', 'O', 'X', 'X',
		'X', 'X', 'O', 'O', 'X', 'X',
		'X', 'X', 'O', 'O', 'X', 'X',
		'X', 'X', 'O', 'X', 'O', 'X',
		'X', 'O', 'O', 'O', 'X', 'O',
		'O', 'O', 'O', 'O', 'O', 'O',
		'O', 'O', 'O', 'O', 'O', 'O',
		'X', 'X', 'O', 'O', 'X', 'X',
		'O', 'X', 'O', 'X', 'X', 'X',
		'X', 'X', 'X', 'O', 'X', 'O',
		'O', 'X', 'O', 'O', 'X', 'X',
		'X', 'X', 'O', 'O', 'X', 'X',
		'X', 'X', 'O', 'O', 'X', 'X'
	};

	printHeader();

	Flight flight1 = Flight("NE123", "CLT", "BOS", 7, 24, 2018, 800, 7, 24, 2018, 1015);
	flight1.print();

	cout << endl;
	system("pause");
	return 0;
}