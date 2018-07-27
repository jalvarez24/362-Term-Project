#include <iostream>
#include <string>
#include <vector>
#include "Account.h"
#include "Booking.h"
#include "Flight.h"

using namespace std;

//print header for flights list
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
	char seating1[72] =
	{
		'X', 'X', 'X', 'X', 'X', 'O', 'X', 'X', 'X', 'O', 'X', 'X', 'X', 'O', 'X', 'O', 'O', 'O',
		'X', 'X', 'X', 'O', 'X', 'O', 'X', 'X', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O',
		'X', 'O', 'O', 'X', 'X', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O',
		'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'X', 'X', 'X', 'X', 'X',
	};
	char seating2[72] =
	{
		'O', 'X', 'O', 'X', 'O', 'O', 'O', 'O', 'X', 'O', 'X', 'X', 'X', 'O', 'X', 'O', 'O', 'X',
		'O', 'X', 'X', 'O', 'X', 'O', 'O', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'O', 'O', 'O', 'O',
		'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'X', 'X', 'X', 'O', 'X', 'O', 'O', 'X', 'O',
		'X', 'O', 'X', 'O', 'X', 'O', 'O', 'O', 'X', 'O', 'X', 'O', 'X', 'X', 'X', 'X', 'X', 'X',
	};
	char seating3[72] =
	{
		'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O', 'X', 'X', 'O', 'X', 'O', 'O', 'O', 'X',
		'O', 'X', 'X', 'O', 'X', 'X', 'O', 'X', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'X',
		'X', 'O', 'O', 'X', 'O', 'O', 'O', 'X', 'X', 'X', 'X', 'O', 'O', 'O', 'X', 'X', 'O', 'O',
		'X', 'O', 'X', 'O', 'O', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'X', 'X', 'O', 'X', 'O', 'X',
	};
	char seating4[72] =
	{
		'X', 'X', 'X', 'X', 'X', 'O', 'X', 'X', 'X', 'O', 'X', 'X', 'X', 'O', 'O', 'O', 'O', 'O',
		'X', 'X', 'X', 'O', 'X', 'O', 'X', 'X', 'X', 'O', 'X', 'O', 'X', 'O', 'O', 'O', 'X', 'O',
		'X', 'O', 'O', 'X', 'O', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'O', 'X', 'X', 'X', 'O', 'O',
		'X', 'O', 'X', 'O', 'O', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'O', 'X', 'X', 'X', 'X', 'X',
	};
	/*
	// ========= Hardcoded admin accounts ===========
	Account admin1 = Account("admin1", "admin", "Danny Pham", "N/A", "N/A", "10802 Stanford Ave, Garden Grove, CA 92840", "dpham92@csu.fullerton.edu", "Sept 22, 1992", "N/A", "(949) 631 - 1166", 'M');
	Account admin2 = Account("admin2", "admin", "Brian Trinh", "N/A", "N/A", "N/A", "N/A", "N/A", "N/A", "N/A", 'M');
	Account admin3 = Account("admin3", "admin", "Royce Nguyen", "N/A", "N/A", "N/A", "N/A", "N/A", "N/A", "N/A", 'M');
	Account admin4 = Account("admin4", "admin", "Jayro Alvarez", "N/A", "N/A", "N/A", "N/A", "N/A", "N/A", "N/A", 'M');
	
	vector<Account> accountList;
	accountList.push_back(admin1);
	accountList.push_back(admin2);
	accountList.push_back(admin3);
	accountList.push_back(admin4);
	// ===============================================
	*/
	// ============== Login Segment ==================
	/*
	cout << "Welcome to Northeast Airlines!\n";
	cout << "Please enter your username (-1 to exit): ";

	string username = "";
	cin >> username;
	bool userFound = false;

	int accountListIter = 0;
	while ((accountListIter < accountList.size()) && !userFound) {
		if (accountList[accountListIter].getUsername() == username) {
			userFound = true;
		}
		else {
		accountListIter++;
		}
	}

	if (!userFound) {
		cout << "Username not found. Try again.";
	}
	else {
		cout << "Please enter your password: ";
		string pw = "";
		cin >> pw;
		if (accountList[accountListIter].validatePassword(pw)) {
			cout << "Welcome, " << accountList[accountListIter].getName();
		}
	} */
	
	// ===============================================
	
	printHeader();

	//Creation of Unique Flights
	//-----------------------------------------
	Flight flight1 = Flight("NE123", "CLT", "BOS", 8, 1, 2018, 800, 8, 1, 2018, 1015, seating1);
	Flight flight2 = Flight("NE435", "BDL", "JFK", 8, 1, 2018, 1200, 8, 1, 2018, 1500, seating2);
	Flight flight3 = Flight("NE234", "LGA", "PHL", 8, 1, 2018, 1130, 8, 1, 2018, 1300, seating3);
	Flight flight4 = Flight("NE724", "PIT", "JFK", 8, 1, 2018, 400, 8, 1, 2018, 600, seating4);
	Flight flight5 = Flight("NE525", "BUF", "BDL", 8, 1, 2018, 1600, 8, 1, 2018, 1930, seating1);
	Flight flight6 = Flight("NE770", "BOS", "PIT", 8, 1, 2018, 1900, 8, 1, 2018, 2130, seating2);
	Flight flight7 = Flight("NE563", "JFK", "PHL", 8, 1, 2018, 2200, 8, 1, 2018, 2330, seating3);
	Flight flight8 = Flight("NE912", "LGA", "BOS", 8, 1, 2018, 700, 8, 1, 2018, 850, seating4);
	Flight flight9 = Flight("NE266", "CLT", "BUF", 8, 1, 2018, 1230, 8, 1, 2018, 1420, seating1);
	Flight flight10 = Flight("NE397", "PHL", "CLT", 8, 1, 2018, 1500, 8, 1, 2018, 1645, seating2);
	//-----------------------------------------

	//Flight testing
	//-----------------------------------------
	flight1.print();
	flight1.displaySeats();
	//-----------------------------------------
	
	cout << endl;
	//system("pause");
	return 0;
}
