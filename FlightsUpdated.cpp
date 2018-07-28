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
	
	// ========= Hardcoded admin accounts ===========
	Account admin1 = Account("admin1", "admin", "Danny Pham", "N/A", "N/A", "10802 Stanford Ave, Garden Grove, CA 92840", "dpham92@csu.fullerton.edu", "Sept 22, 1992", "N/A", "(949) 631 - 1166", "M");
	Account admin2 = Account("admin2", "admin", "Brian Trinh", "N/A", "N/A", "13221 Newhope St, Garden Grove, CA, 92843", "briantrinh@csu.fullerton.edu", "May 18, 1994", "N/A", "(714) 723 - 1637", "M");
	Account admin3 = Account("admin3", "admin", "Royce Nguyen", "N/A", "N/A", "N/A", "N/A", "N/A", "N/A", "N/A", "M");
	Account admin4 = Account("admin4", "admin", "Jayro Alvarez", "N/A", "N/A", "N/A", "N/A", "N/A", "N/A", "N/A", "M");
	
	vector<Account> accountList;
	accountList.push_back(admin1);
	accountList.push_back(admin2);
	accountList.push_back(admin3);
	accountList.push_back(admin4);
	// ===============================================
	
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
		
		
		// ==== Login ====
		if (selection.compare("1") == 0) {
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
		}

		// ==== Sign up ====
		else if (selection.compare("2") == 0) {
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
			getline(cin, _password);
			cin >> ws;

			cout << "Full Name: ";
			getline(cin, _accountHolderName);
			cin >> ws;

			cout << "Sex: ";
			getline(cin, _sex);
			cin >> ws;

			cout << "Credit Card Number: ";
			getline(cin, _creditCardNum);
			cin >> ws;

			cout << "Credit Card Expiration: ";
			getline(cin, _creditCardExpiration);
			cin >> ws;

			cout << "Address: ";
			getline(cin, _billingAddress);
			cin >> ws;

			cout << "Email: ";
			getline(cin, _email);
			cin >> ws;

			cout << "Date of Birth: ";
			getline(cin, _dateOfBirth);
			cin >> ws;

			cout << "Home Phone: ";
			getline(cin, _homePhone);
			cin >> ws;

			cout << "Cell Phone: ";
			getline(cin, _cellPhone);
			cin >> ws;

			Account newAccount = Account(_userName, _password, _accountHolderName, _creditCardNum, _creditCardExpiration, _billingAddress, _email, _dateOfBirth, _homePhone, _cellPhone, _sex);
			accountList.push_back(newAccount);

			accountListIter = accountList.size()-1;
			userFound = true;
			userValidated = true;
			username = _userName;	

			cin.get();
		}
		else {
			cout << "Invalid input. Please try again." << endl;
		}
	}
	if (username.compare("-1") == 0) {
		cout << "Exiting Northeast Airlines..." << endl;
	}
	if (userFound && userValidated) {
		
		cout << "Welcome " << accountList[accountListIter].getName() << "!\n";

		string selection = "";
		cin.get();
		while (selection.compare("4") != 0) {
			cout << "What would you like to do today?" << endl;
			cout << "\t1) Search flights" << endl;
			cout << "\t2) Book flights" << endl;
			cout << "\t3) Review booked flights" << endl;
			cout << "\t4) Sign out" << endl;
			
			getline(cin, selection);

			if (selection.compare("1") == 0) {
				cout << "Searching flights" << endl;
			}
			else if (selection.compare("2") == 0) {
				cout << "Booking flights" << endl;
			}
			else if (selection.compare("3") == 0) {
				cout << "Reviewing flights" << endl;
			}
			else if (selection.compare("4") == 0) {
				cout << "Thank you for using Northeast Airlines. Have a great day!" << endl;
			}
			else {
				cout << "Invalid selection." << endl;
			}
		}
	}
	
	// ===============================================
	//Flight testing
	//-----------------------------------------
	printHeader();
	flight1.print();
	flight1.displaySeats();
	//-----------------------------------------
	
	
	cout << endl;
	system("pause");
	return 0;
}
