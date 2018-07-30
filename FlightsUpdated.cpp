#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
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

//takes int seat value and returns in plane format (i.e: B16, D4, etc.)
string seatconverter(int x)
{
	int xplusone = x + 1;
	string seatnum = to_string(xplusone);
	string seat = "";
	if(x < 18)
	{
		seat += "A";
		seat += seatnum;
	}
	else if (x >= 18 && x < 36)
	{
		seat += "B";
		seat += seatnum;
	}
	else if (x >= 36 && x < 54)
	{
		seat += "C";
		seat += seatnum;
	}
	else
	{
		seat += "D";
		seat += seatnum;
	}
	return seat;
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
	
	// ========= Hardcoded admin accounts ===========
	Account admin1 = Account("admin1", "admin", "Danny Pham", "N/A", "N/A", "10802 Stanford Ave, Garden Grove, CA 92840", "dpham92@csu.fullerton.edu", "Sept 22, 1992", "N/A", "(949) 631 - 1166", "M");
	Account admin2 = Account("admin2", "admin", "Brian Trinh", "N/A", "N/A", "13221 Newhope St, Garden Grove, CA, 92843", "briantrinh@csu.fullerton.edu", "May 18, 1994", "N/A", "(714) 723 - 1637", "M");
	Account admin3 = Account("admin3", "admin", "Royce Nguyen", "N/A", "N/A", "N/A", "N/A", "N/A", "N/A", "N/A", "M");
	Account admin4 = Account("admin4", "admin", "Jayro Alvarez", "N/A", "N/A", "16064 Mount Lister Ct, Fountain Valley, CA 92708", "jayroalvarez@csu.fullerton.edu", "March 28, 1997", "N/A", "(949) 345 - 9831", "M");
	
	vector<Account> accountList;
	accountList.push_back(admin1);
	accountList.push_back(admin2);
	accountList.push_back(admin3);
	accountList.push_back(admin4);
	// ===============================================
	
	//Creation of Unique Flights
	//-----------------------------------------
	Flight flight1 = Flight("NE123", "CLT", "BOS", 8, 1, 2018, 800, 8, 1, 2018, 1015, seating1, 449.99);
	Flight flight2 = Flight("NE435", "BDL", "JFK", 8, 1, 2018, 1200, 8, 1, 2018, 1500, seating2, 365.99);
	Flight flight3 = Flight("NE234", "LGA", "PHL", 8, 1, 2018, 1130, 8, 1, 2018, 1300, seating3, 299.99);
	Flight flight4 = Flight("NE724", "PIT", "JFK", 8, 1, 2018, 400, 8, 1, 2018, 600, seating4, 440.99);
	Flight flight5 = Flight("NE525", "BUF", "BDL", 8, 1, 2018, 1600, 8, 1, 2018, 1930, seating1, 349.50);
	Flight flight6 = Flight("NE770", "BOS", "PIT", 8, 1, 2018, 1900, 8, 1, 2018, 2130, seating2, 289.99);
	Flight flight7 = Flight("NE563", "JFK", "PHL", 8, 1, 2018, 2200, 8, 1, 2018, 2330, seating3, 449.50);
	Flight flight8 = Flight("NE912", "LGA", "BOS", 8, 1, 2018, 700, 8, 1, 2018, 850, seating4, 375.99);
	Flight flight9 = Flight("NE266", "CLT", "BUF", 8, 1, 2018, 1230, 8, 1, 2018, 1420, seating1, 450.00);
	Flight flight10 = Flight("NE397", "PHL", "CLT", 8, 1, 2018, 1500, 8, 1, 2018, 1645, seating2, 379.50);
	
	vector<Flight> flightList;
	flightList.push_back(flight1);
	flightList.push_back(flight2);
	flightList.push_back(flight3);
	flightList.push_back(flight4);
	flightList.push_back(flight5);
	flightList.push_back(flight6);
	flightList.push_back(flight7);
	flightList.push_back(flight8);
	flightList.push_back(flight9);
	flightList.push_back(flight10);
	//-----------------------------------------
	
	// ============== Login Segment ==================
	// Danny Pham 07/28/18
	cout << "Welcome to Northeast Airlines!\n";
	
	string username = "";
	bool userFound = false;
	bool userValidated = false;
	int accountListIter = 0;
	while ((username.compare("-1") != 0) && !userFound) {

		// ==== Login select ====
		string selection = "";
		cout << "Please select an option" << endl;
		cout << "\t1) Login" << endl;
		cout << "\t2) Sign up" << endl;
		cin >> selection;
		system("CLS");
		
		// ==== Login ====
		if (selection.compare("1") == 0) {
			cout << "\t\t\tUSER LOGIN" << endl;
			cout << "Please enter your username (-1 to exit): ";
			cin >> username;

			
			while ((accountListIter < accountList.size()) && !userFound) {
				if (accountList[accountListIter].getUsername() == username) {
					userFound = true;
				}
				else {
					accountListIter++;
				}
			}

			if (!userFound) {
				cout << "Username not found. Try again.\n";
			}
			else {
				cout << "Please enter your password: ";
				string pw = "";
				cin >> pw;
				if (accountList[accountListIter].validatePassword(pw)) {
					userValidated = true;
				}
				else {
					cout << "Incorrect Password!" << endl;
				}
			}
			system("CLS");
			cout << flush;
		}

		// ==== Sign up ====
		else if (selection.compare("2") == 0) {
			cout << "\t\t\tUSER SIGN UP" << endl;
			string _userName;
			string _password;
			string _accountHolderName;
			string _creditCardNum;
			string _creditCardExpiration;
			string _billingAddress;
			string _email;
			string _dateOfBirth;
			string _homePhone;
			string _cellPhone;
			string _sex;

			cout << "Enter -1 at any time to exit." << endl;
			cout << "Enter N/A to skip any fields." << endl;
			cout << "Enter all inputs 1 line at a time." << endl;

			cout << "Username: ";
			cin >> _userName;

			cout << "Password: ";
			cin >> _password;
			

			cout << "Full Name: ";
			cin >> ws;
			getline(cin, _accountHolderName);

			cout << "Sex: ";
			cin >> ws;
			getline(cin, _sex);

			cout << "Credit Card Number: ";
			cin >> ws;
			getline(cin, _creditCardNum);

			cout << "Credit Card Expiration: ";
			cin >> ws;
			getline(cin, _creditCardExpiration);

			cout << "Address: ";
			cin >> ws;
			getline(cin, _billingAddress);

			cout << "Email: ";
			cin >> ws;
			getline(cin, _email);

			cout << "Date of Birth: ";
			cin >> ws;
			getline(cin, _dateOfBirth);

			cout << "Home Phone: ";
			cin >> ws;
			getline(cin, _homePhone);

			cout << "Cell Phone: ";
			cin >> ws;
			getline(cin, _cellPhone);

			Account newAccount = Account(_userName, _password, _accountHolderName, _creditCardNum, _creditCardExpiration, _billingAddress, _email, _dateOfBirth, _homePhone, _cellPhone, _sex);
			accountList.push_back(newAccount);

			accountListIter = accountList.size()-1;
			userFound = true;
			userValidated = true;
			username = _userName;	

		}
		else {
			cout << "Invalid input. Please try again." << endl;
		}
	}
	if (username.compare("-1") == 0) {
		cout << "Exiting Northeast Airlines..." << endl;
	}
	if (userFound && userValidated) {
		
		cout << "\t\tWELCOME" << endl;
		//accountList[accountListIter].getName() << "!\n";
		//accountList[accountListIter].print();

		string selection = "";
		while (selection.compare("4") != 0) 
		{
			cout << "What would you like to do today?" << endl;
			cout << "\t1) Search flights" << endl;
			cout << "\t2) Book flights" << endl;
			cout << "\t3) Review booked flights" << endl;
			cout << "\t4) Sign out" << endl;
			cin >> ws;
			getline(cin, selection);
			system("CLS");
			cout << flush;

			if (selection.compare("1") == 0)
			{
				int choice;
				//cout << "Searching flights" << endl;
				cout << "How would you like to search flights? " << endl;
				cout << "\t1) Flight number" << endl;
				cout << "\t2) Departure location" << endl;
				cout << "\t3) Arrival location" << endl;
				cout << "\t4) View all flights" << endl;

				cin >> choice;
				system("CLS");
				cout << flush;
				string searchString;
				string flightChoice;
				string seatChoice;
				if (choice == 1) // By flight #
				{
					cout << "\t\t\tSEARCH BY FLIGHT NUMBER" << endl;
					cout << "Enter flight number: ";
					cin >> searchString;
					system("CLS");
					cout << flush;

					cout << "\t\t\t\tSEARCH RESULTS" << endl << endl;
					printHeader();
					for (int i = 0; i < flightList.size(); i++)
					{
						if (searchString == flightList[i].getFlightNumber())
						{
							flightList[i].print();
						}
					}
					cout << endl << endl;
					cout << "Select flight (Enter flight number): ";
					cin >> flightChoice;

					system("CLS");
					cout << flush;
					for (int i = 0; i < flightList.size(); i++)
					{
						if (flightChoice == flightList[i].getFlightNumber())
						{
							flightList[i].displaySeats();
						}
					}
					cout << "\nSelect seat(s): ";
					cin >> seatChoice;
				}

				else if (choice == 2) // By departure location
				{
					string depLoc;
					cout << "\t\t\tSEARCH BY DEPARTURE LOCATION" << endl;
					cout << "Enter departure airport: ";
					cin >> searchString;
					system("CLS");
					cout << flush;

					cout << "\t\t\t\tSEARCH RESULTS" << endl << endl;
					printHeader();
					for (int i = 0; i < flightList.size(); i++)
					{
						if (searchString == flightList[i].getDepartureLocation())
						{
							flightList[i].print();
						}
					}
					cout << endl << endl;
					cout << "Select flight (Enter flight number): ";
					cin >> flightChoice;

					system("CLS");
					cout << flush;
					for (int i = 0; i < flightList.size(); i++)
					{
						if (flightChoice == flightList[i].getFlightNumber())
						{
							flightList[i].displaySeats();
						}
					}
					cout << "\nSelect seat(s): ";
					cin >> seatChoice;
				}

				else if (choice == 3) // By arrival location
				{
					string arrLoc;
					cout << "\t\t\tSEARCH BY ARRIVAL LOCATION" << endl;
					cout << "Enter arrival airport: ";
					cin >> searchString;
					system("CLS");
					cout << flush;


					cout << "\t\t\t\tSEARCH RESULTS" << endl << endl;
					printHeader();
					for (int i = 0; i < flightList.size(); i++)
					{
						if (searchString == flightList[i].getArrivalLocation())
						{
							flightList[i].print();
						}
					}
					cout << endl << endl;
					cout << "Select flight (Enter flight number): ";
					cin >> flightChoice;

					system("CLS");
					cout << flush;
					for (int i = 0; i < flightList.size(); i++)
					{
						if (flightChoice == flightList[i].getFlightNumber())
						{
							flightList[i].displaySeats();
						}
					}
					cout << "\nSelect seat(s): ";
					cin >> seatChoice;
				}

				else if (choice == 4) // View all flights
				{
					cout << "\t\t\t\tALL AVAILABLE FLIGHTS" << endl << endl;
					printHeader();
					for (int i = 0; i < flightList.size(); i++)
					{
						flightList[i].print();
					}
					cout << endl << endl;
					cout << "Select flight (Enter flight number): ";
					cin >> flightChoice;

					system("CLS");
					cout << flush;
					for (int i = 0; i < flightList.size(); i++)
					{
						if (flightChoice == flightList[i].getFlightNumber())
						{
							flightList[i].displaySeats();
						}
					}
					cout << "\nSelect seat(s): ";
					cin >> seatChoice;
				}

				
				/*for (int i = 0; i < flightList.size(); i++)
				{
					flightList[i].print();
				}*/
				/*cout << "Select a flight: ";
				cin >> selection;

				for (int i = 0; i < flightList.size(); i++)
				{
					if (flightList[i].getFlightNumber() == selection)
					{
						flightList[i].print();
					}
				}*/
			}
			else if (selection.compare("2") == 0) 
			{
				cout << "Booking flights" << endl;
			}
			else if (selection.compare("3") == 0) 
			{
				cout << "Reviewing flights" << endl;
			}
			else if (selection.compare("4") == 0) 
			{
				cout << "Thank you for using Northeast Airlines. Have a great day!" << endl;
			}
			else 
			{
				cout << "Invalid selection." << endl;
			}
		}
	}
	
	// ===============================================
	//Flight testing
	//-----------------------------------------
	//printHeader();
	//flight1.print();
	//flight1.displaySeats();
	//-----------------------------------------
	
	
	cout << endl;
	system("pause");
	return 0;
}
