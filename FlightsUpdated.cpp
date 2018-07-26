#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Flight
{
public:
	Flight() {};
	~Flight() {};
	Flight(string, string, string, int, int, int, int, int, int, int, int, char[]);
	string getFlightNumber();
	int getDepartureTime();
	int getArrivalTime();
	string getDepartureLocation();
	string getArrivalLocation();
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
	char seats[72];
};

Flight::Flight(string flightNum, string toLoc, string fromLoc, int depMonth, int depDay, int depYear, int depTime, int arrMonth, int arrDay, int arrYear, int arrTime, char seating[]) 
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
	for (int x = 0; x <= 72; x++)
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

void printHeader()
{
	cout << "FLIGHT NUMBER\tTO\tFROM\tDEPARTURE DATE\tARRIVAL DATE\tAVAILABLE SEATS\n";
	cout << "-------------------------------------------------------------------------------\n";
}


int main()
{
	//# of Rows: 18
	//# of Seats per Row: 4
	//Total Seats= 72
	char seating[72] =
	{
		'X', 'X', 'X', 'X', 'X', 'O', 'X', 'X', 'X', 'O', 'X', 'X', 'X', 'O', 'X', 'O', 'O', 'O',
		'X', 'X', 'X', 'O', 'X', 'O', 'X', 'X', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O',
		'X', 'O', 'O', 'X', 'X', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O',
		'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'X', 'X', 'X', 'X', 'X',
	};

	printHeader();

	Flight flight1 = Flight("NE123", "CLT", "BOS", 7, 24, 2018, 800, 7, 24, 2018, 1015, seating);
	flight1.print();
	flight1.displaySeats();
	cout << endl;
	system("pause");
	return 0;
}
