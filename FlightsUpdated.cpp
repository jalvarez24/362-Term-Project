// Authors: Royce Nguyen, Jayro Alvarez, Brian Trinh, Danny Pham
// Course: CPSC 362
// Filename: FlightsUpdated.cpp
// Purpose: main
// Last updated: 7/31/2018

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

//takes in seat# as int in seating array, returns seat# as string version
//(i.e: input 0 => returns "A1")
//(i.e: input 71 => returns "D18")
//(i.e: input 4 => "A2"
string seatIntToStr(int x)
{
	string seatstring = "";
	int seatnum = x + 1;
	
	if(x == 0 || x == 4 || x == 8 || x == 12 || x == 16 ||  x == 20 ||  x == 24 ||
	 x == 28 || x == 32 ||  x == 36 ||  x == 40 ||  x == 44 ||  x == 48 ||  x == 52 ||
	  x == 56 ||  x == 60 ||  x == 64 ||  x == 68 )
	{
		seatstring += "A";
		if(x >= 4)
			seatnum = (seatnum/4) + 1;
		seatstring += to_string(seatnum);
	}
	else if(x == 1 || x == 5 || x == 9 || x == 13 || x == 17 ||  x == 21 ||  x == 25 ||
	 x == 29 || x == 33 ||  x == 37 ||  x == 41 ||  x == 45 ||  x == 49 ||  x == 53 ||
	  x == 57 ||  x == 61 ||  x == 65 ||  x == 69 )
	{
		seatstring += "B";
		if(x >= 5)
		{
			seatnum = (seatnum/4) + 1;
			seatstring += to_string(seatnum);
		}
		else
		seatstring += to_string(seatnum-1);
	}
	else if(x == 2 || x == 6 || x == 10 || x == 14 || x == 18 ||  x == 22 ||  x == 26 ||
	 x == 30 || x == 34 ||  x == 38 ||  x == 42 ||  x == 46 ||  x == 50 ||  x == 54 ||
	  x == 58 ||  x == 62 ||  x == 66 ||  x == 70 )
	{
		seatstring += "C";
		if(x >= 6)
		{
			seatnum = (seatnum/4) + 1;
			seatstring += to_string(seatnum);
		}
		else
		seatstring += to_string(seatnum-2);
	}
	else
	{
		seatstring += "D";
		if(x >= 7)
		{
			seatnum = (x/4) + 1;
			seatstring += to_string(seatnum);
		}
		else
		seatstring += to_string(seatnum-3);
	}
	return seatstring;
}

//takes in seat# as string, returns seat# as int index in seating array
//(i.e: input "A1" => returns 0)
//			B1 => 1
//			D1 => 3
//			A2 => 4
//(i.e: unput "D18" => returns 71)
int seatStrToInt(string x)
{
	string rowNumAsString = "";
	rowNumAsString += x[1];
	if(x.length() > 2)
	{
		rowNumAsString += x[2];
	}
	//rowNumAsString now contains the one or two digit row (1-18),
	//here converted into int.
	int rowNumAsInt = stoi(rowNumAsString);
	//decrement by one to get as value from 0-17
	rowNumAsInt--;
	if (x[0] == 'A')
	{
		int arrayseatval = 0;
		for(int x = 0; x < rowNumAsInt; x++){
			arrayseatval += 4;
		}
		return arrayseatval;
	}
	else if (x[0] == 'B')
	{
		int arrayseatval = 1;
		for(int x = 0; x < rowNumAsInt; x++){
			arrayseatval += 4;
		}
		return arrayseatval;
	}
	else if (x[0] == 'C')
	{
		int arrayseatval = 2;
		for(int x = 0; x < rowNumAsInt; x++){
			arrayseatval += 4;
		}
		return arrayseatval;
	}
	else
	{
		int arrayseatval = 3;
		for(int x = 0; x < rowNumAsInt; x++){
			arrayseatval += 4;
		}
		return arrayseatval;
	}
}

int main()
{
	//# of Rows: 18
	//# of Seats per Row: 4
	//Total Seats= 72
	char seating1[72] = 
	{
		'X', 'O', 'X', 'X',
		'O', 'O', 'X', 'X',
		'X', 'O', 'X', 'X',
		'O', 'X', 'O', 'X',
		'X', 'X', 'X', 'X',
		'O', 'O', 'O', 'O',
		'X', 'X', 'O', 'X',
		'X', 'O', 'X', 'X',
		'X', 'X', 'X', 'X',
		'X', 'O', 'X', 'O',
		'X', 'X', 'O', 'X',
		'O', 'X', 'X', 'X',
		'X', 'O', 'X', 'X',
		'O', 'X', 'X', 'X',
		'O', 'X', 'O', 'O',
		'X', 'X', 'X', 'X',
		'X', 'X', 'X', 'O',
		'O', 'O', 'X', 'X'
	};
	char seating2[72] =
	{
		'O', 'O', 'X', 'X',
		'O', 'O', 'X', 'X',
		'X', 'O', 'X', 'X',
		'O', 'O', 'O', 'X',
		'X', 'X', 'X', 'O',
		'O', 'O', 'O', 'O',
		'X', 'X', 'O', 'X',
		'O', 'O', 'X', 'X',
		'X', 'O', 'X', 'X',
		'O', 'O', 'O', 'O',
		'X', 'X', 'O', 'X',
		'O', 'X', 'O', 'X',
		'X', 'O', 'X', 'O',
		'O', 'X', 'O', 'X',
		'X', 'O', 'O', 'O',
		'X', 'X', 'X', 'X',
		'X', 'X', 'X', 'O',
		'O', 'O', 'O', 'X'
	};
	char seating3[72] =
		{
		'O', 'O', 'X', 'O',
		'O', 'O', 'X', 'X',
		'X', 'O', 'X', 'X',
		'O', 'X', 'O', 'O',
		'X', 'X', 'O', 'X',
		'O', 'O', 'O', 'O',
		'X', 'X', 'O', 'O',
		'X', 'O', 'X', 'O',
		'O', 'X', 'X', 'X',
		'O', 'O', 'X', 'O',
		'X', 'X', 'O', 'X',
		'O', 'X', 'X', 'X',
		'X', 'O', 'X', 'X',
		'O', 'X', 'X', 'X',
		'O', 'X', 'O', 'O',
		'O', 'X', 'X', 'X',
		'X', 'X', 'O', 'O',
		'O', 'O', 'O', 'X'
	};
	char seating4[72] =
	{
		'X', 'O', 'X', 'O',
		'O', 'O', 'O', 'X',
		'X', 'O', 'X', 'X',
		'O', 'X', 'O', 'X',
		'X', 'X', 'X', 'X',
		'O', 'O', 'O', 'O',
		'X', 'X', 'O', 'X',
		'O', 'O', 'X', 'X',
		'X', 'X', 'X', 'O',
		'X', 'O', 'X', 'O',
		'O', 'X', 'O', 'X',
		'O', 'X', 'X', 'X',
		'X', 'O', 'X', 'X',
		'O', 'X', 'X', 'X',
		'O', 'X', 'O', 'O',
		'X', 'X', 'X', 'X',
		'X', 'X', 'X', 'O',
		'O', 'O', 'O', 'X'
	};

	
	// ================================================= Hardcoded admin accounts =========================================================
	Account admin1 = Account("admin1", "admin", "Danny Pham", "N/A", "N/A", "10802 Stanford Ave, Garden Grove, CA 92840", "dpham92@csu.fullerton.edu", "Sept 22, 1992", "N/A", "(949) 631 - 1166", "M");
	Account admin2 = Account("admin2", "admin", "Brian Trinh", "N/A", "N/A", "13221 Newhope St, Garden Grove, CA, 92843", "briantrinh@csu.fullerton.edu", "May 18, 1994", "N/A", "(714) 723 - 1637", "M");
	Account admin3 = Account("admin3", "admin", "Royce Nguyen", "N/A", "N/A", "N/A", "N/A", "N/A", "N/A", "N/A", "M");
	Account admin4 = Account("admin4", "admin", "Jayro Alvarez", "N/A", "N/A", "16064 Mount Lister Ct, Fountain Valley, CA 92708", "jayroalvarez@csu.fullerton.edu", "March 28, 1997", "N/A", "(949) 345 - 9831", "M");
	
	vector<Account> accountList;
	accountList.push_back(admin1);
	accountList.push_back(admin2);
	accountList.push_back(admin3);
	accountList.push_back(admin4);
	// ===========================================================================================================================================
	
	//=============================== Creation of Unique Flights =========================================
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
	//---------------------------------------------------------------------------------------------------------------
	
	// ================================ Login Segment =================================
	// Danny Pham 07/28/18
	cout << "Welcome to Northeast Airlines!\n";
	
	string username = "";
	bool userFound = false;
	bool userValidated = false;
	int accountListIter = 0;
	while ((username.compare("-1") != 0) && !userFound) {

		// ============== Login select =================
		string selection = "";
		cout << "Please select an option" << endl;
		cout << "\t1) Login" << endl;
		cout << "\t2) Sign up" << endl;
		cin >> selection;
		system("CLS");
		
		// ========================= Login ===========================
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
		while (selection.compare("3") != 0) 
		{
			cout << "What would you like to do today?" << endl;
			cout << "\t1) Search flights" << endl;
			cout << "\t2) Review booked flights" << endl;
			cout << "\t3) Sign out" << endl;
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
				int flightsFound = 0;
				int counter = 0;
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
							flightsFound++;
						}
					}
					
					cout << endl << endl;
					cout << "Select flight to view available seats (Enter flight number): ";
					cin >> flightChoice;
					int selectedFlight;	//assigned flight, initialized in loop below.

					system("CLS");
					cout << flush;
					for (int i = 0; i < flightList.size(); i++)
					{
						if (flightChoice == flightList[i].getFlightNumber())
						{
							selectedFlight = i;
							flightList[i].displaySeats();
						}
					}
					cout << "\nSelect open seat (input as LETTER followed by ROW#): ";
					cin >> seatChoice;
					while (flightList[selectedFlight].seats[seatStrToInt(seatChoice)] == 'X'){
						system("CLS");
						cout << flush;
						flightList[selectedFlight].displaySeats();
						cout << "\nINVALID, seat " << seatChoice<< " is taken, try again." << endl;
						cout << "Select open seat (input as LETTER followed by ROW#): ";
						cin >> seatChoice;
					}
					system("CLS");
					cout << flush;
					cout << "Seat, " << seatChoice << ", has been selected." << endl;
					cout << "Would you like to:" << endl;
					cout << "\t1) Pay for flight and add to bookings" << endl;
					cout << "\t2) Return to Main Menu and lose progress" << endl;
					cin >> choice;
					
					while (choice != 1 && choice != 2)
					{
						system("CLS");
						cout << flush;
						cout << "INVALID menu choice. Try again." << endl;
						cout << "Seat, " << seatChoice << ", has been selected." << endl;
						cout << "Would you like to:" << endl;
						cout << "\t1) Pay for flight and add to bookings" << endl;
						cout << "\t2) Return to Main Menu and lose progress" << endl;
						cin >> choice;
					}	
						//pay for flight
						if (choice == 1)
						{
							system("CLS");
							cout << flush;
							cout << "\t\tPAY FOR FLIGHT" << endl;
							cout << "\t\t==============" << endl;
							cout << "Flight Summary:  " << endl;
							cout << "Flight#: " << right << setw(41) << flightList[selectedFlight].getFlightNumber() << endl;
							cout << "Departing: " << right << setw(22) << flightList[selectedFlight].getDepartureLocation()
							<< "- " << flightList[selectedFlight].getDepartureDate() <<  " @ " << right << setw(4) << 
							flightList[selectedFlight].getDepartureTime() << endl;
							cout << "Arriving: " << right << setw(23) << flightList[selectedFlight].getArrivalLocation()
							<< "- " << flightList[selectedFlight].getArrivalDate() << " @ " << right << setw(4) <<
							flightList[selectedFlight].getArrivalTime() << endl;
							cout << "==================================================" << endl;
							cout << "Price (tax included): " << right << setw(28) << fixed << setprecision(2) << flightList[selectedFlight].getprice() << endl;
							cout << "==================================================" << endl;
							cout << "1. Pay for flight with CC on account" << endl;
							cout << "2. Cancel and return to main menu" << endl;
							cin >> choice;
							if (choice == 1)
							{
								if(accountList[accountListIter].checkCC() == false)
								{
									system("CLS");
									string ccNum, ccExp;
									cout << "\tERROR, NO CREDIT CARD ON ACCOUNT." << endl;
									cout << "Please enter following credit card information: " << endl;
									cout << "Enter 16 digit Credit Card: ";
									cin >> ccNum;
									accountList[accountListIter].setCreditCardNum(ccNum);
									cout << "Enter expiration date in format MM/YYYY: ";
									cin >> ccExp;
									accountList[accountListIter].setCreditCardExpiration(ccExp);
									system("CLS");
									cout << "Credit card: " << accountList[accountListIter].getCreditCardNum() << " has been saved." << endl;
									cout << "==================================================" << endl;
									cout << "Continue with charge of: " << flightList[selectedFlight].getprice() << "?" << endl;
									cout << "1. Yes" << endl;
									cout << "2. Cancel and return to main menu" << endl;
									cin >> choice;
									if (choice == 1)
									{
										system("CLS");
										//update seating array for specified flight
										flightList[selectedFlight].seats[seatStrToInt(seatChoice)] = 'X';
										//add booking to account
										accountList[accountListIter].addBooking(flightList[selectedFlight].getFlightNumber(), accountList[accountListIter].getID(), seatStrToInt(seatChoice));
										cout << "\t\tSUCCESS!" << endl;
										cout << "\tBOOKING ADDED TO ACCOUNT." << endl;
										cout << "*(Review flights from main menu to edit booking(s)*" << endl;
										cout << "==================================================" << endl;
									}
									else if (choice == 2)
									{
										//do nothing, return to main menu
										system("CLS");
									}
								}
								else
								{
									system("CLS");
									//update seating array for specified flight
									flightList[selectedFlight].seats[seatStrToInt(seatChoice)] = 'X';
									//add booking to account
									accountList[accountListIter].addBooking(flightList[selectedFlight].getFlightNumber(), accountList[accountListIter].getID(), seatStrToInt(seatChoice));
									cout << "\t\tSUCCESS!" << endl;
									cout << "\tBOOKING ADDED TO ACCOUNT." << endl;
									cout << "Card Used: " << accountList[accountListIter].getCreditCardNum() << endl;
									cout << "*(Review flights from main menu to edit booking(s)*" << endl;
									cout << "==================================================" << endl;
								}
							}
							else if(choice == 2)
							{
								//do nothing, return to main menu
								system("CLS");
							}
						}
						//return to main menu
						else if (choice == 2)
						{
							//do nothing, goes to main menu
							system("CLS");
							cout << flush;
						}				
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
					cout << "Select flight to view available seats (Enter flight number): ";
					cin >> flightChoice;
					int selectedFlight;	//assigned flight, initialized in loop below.

					system("CLS");
					cout << flush;
					for (int i = 0; i < flightList.size(); i++)
					{
						if (flightChoice == flightList[i].getFlightNumber())
						{
							selectedFlight = i;
							flightList[i].displaySeats();
						}
					}
					cout << "\nSelect open seat (input as LETTER followed by ROW#): ";
					cin >> seatChoice;
					while (flightList[selectedFlight].seats[seatStrToInt(seatChoice)] == 'X'){
						system("CLS");
						cout << flush;
						flightList[selectedFlight].displaySeats();
						cout << "\nINVALID, seat " << seatChoice<< " is taken, try again." << endl;
						cout << "Select open seat (input as LETTER followed by ROW#): ";
						cin >> seatChoice;
					}
					system("CLS");
					cout << flush;
					cout << "Seat, " << seatChoice << ", has been selected." << endl;
					cout << "Would you like to:" << endl;
					cout << "\t1) Pay for flight and add to bookings" << endl;
					cout << "\t2) Return to Main Menu and lose progress" << endl;
					cin >> choice;
					while (choice != 1 && choice != 2){
						system("CLS");
						cout << flush;
						cout << "INVALID menu choice. Try again." << endl;
						cout << "Seat, " << seatChoice << ", has been selected." << endl;
						cout << "Would you like to:" << endl;
						cout << "\t1) Pay for flight and add to bookings" << endl;
						cout << "\t2) Return to Main Menu and lose progress" << endl;
						cin >> choice;
					}	
						//pay for flight
						if (choice == 1)
						{
							system("CLS");
							cout << flush;
							cout << "\t\tPAY FOR FLIGHT" << endl;
							cout << "\t\t==============" << endl;
							cout << "Flight Summary:  " << endl;
							cout << "Flight#: " << right << setw(41) << flightList[selectedFlight].getFlightNumber() << endl;
							cout << "Departing: " << right << setw(22) << flightList[selectedFlight].getDepartureLocation()
							<< "- " << flightList[selectedFlight].getDepartureDate() <<  " @ " << right << setw(4) << 
							flightList[selectedFlight].getDepartureTime() << endl;
							cout << "Arriving: " << right << setw(23) << flightList[selectedFlight].getArrivalLocation()
							<< "- " << flightList[selectedFlight].getArrivalDate() << " @ " << right << setw(4) <<
							flightList[selectedFlight].getArrivalTime() << endl;
							cout << "==================================================" << endl;
							cout << "Price (tax included): " << right << setw(28) << fixed << setprecision(2) << flightList[selectedFlight].getprice() << endl;
							cout << "==================================================" << endl;
							cout << "1. Pay for flight with CC on account" << endl;
							cout << "2. Cancel and return to main menu" << endl;
							cin >> choice;
							if (choice == 1)
							{
								if (accountList[accountListIter].checkCC() == false)
								{
									system("CLS");
									string ccNum, ccExp;
									cout << "\tERROR, NO CREDIT CARD ON ACCOUNT." << endl;
									cout << "Please enter following credit card information: " << endl;
									cout << "Enter 16 digit Credit Card: ";
									cin >> ccNum;
									accountList[accountListIter].setCreditCardNum(ccNum);
									cout << "Enter expiration date in format MM/YYYY: ";
									cin >> ccExp;
									accountList[accountListIter].setCreditCardExpiration(ccExp);
									system("CLS");
									cout << "Credit card: " << accountList[accountListIter].getCreditCardNum() << " has been saved." << endl;
									cout << "==================================================" << endl;
									cout << "Continue with charge of: " << flightList[selectedFlight].getprice() << "?" << endl;
									cout << "1. Yes" << endl;
									cout << "2. Cancel and return to main menu" << endl;
									cin >> choice;
									if (choice == 1)
									{
										system("CLS");
										//update seating array for specified flight
										flightList[selectedFlight].seats[seatStrToInt(seatChoice)] = 'X';
										//add booking to account
										accountList[accountListIter].addBooking(flightList[selectedFlight].getFlightNumber(), accountList[accountListIter].getID(), seatStrToInt(seatChoice));
										cout << "\t\tSUCCESS!" << endl;
										cout << "\tBOOKING ADDED TO ACCOUNT." << endl;
										cout << "*(Review flights from main menu to edit booking(s)*" << endl;
										cout << "==================================================" << endl;
									}
									else if (choice == 2)
									{
										//do nothing, return to main menu
										system("CLS");
									}
								}
								else
								{
									system("CLS");
									//update seating array for specified flight
									flightList[selectedFlight].seats[seatStrToInt(seatChoice)] = 'X';
									//add booking to account
									accountList[accountListIter].addBooking(flightList[selectedFlight].getFlightNumber(), accountList[accountListIter].getID(), seatStrToInt(seatChoice));
									cout << "\t\tSUCCESS!" << endl;
									cout << "\tBOOKING ADDED TO ACCOUNT." << endl;
									cout << "Card Used: " << accountList[accountListIter].getCreditCardNum() << endl;
									cout << "*(Review flights from main menu to edit booking(s)*" << endl;
									cout << "==================================================" << endl;
								}
							}
							else if (choice == 2)
							{
								//do nothing, return to main menu
								system("CLS");
							}
						}
						//return to main menu
						else if (choice == 2)
						{
							//do nothing, goes to main menu
							system("CLS");
							cout << flush;
						}	
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
					cout << "Select flight to view available seats (Enter flight number): ";
					cin >> flightChoice;
					int selectedFlight;	//assigned flight, initialized in loop below.

					system("CLS");
					cout << flush;
					for (int i = 0; i < flightList.size(); i++)
					{
						if (flightChoice == flightList[i].getFlightNumber())
						{
							selectedFlight = i;
							flightList[i].displaySeats();
						}
					}
					cout << "\nSelect open seat (input as LETTER followed by ROW#): ";
					cin >> seatChoice;
					while (flightList[selectedFlight].seats[seatStrToInt(seatChoice)] == 'X'){
						system("CLS");
						cout << flush;
						flightList[selectedFlight].displaySeats();
						cout << "\nINVALID, seat " << seatChoice<< " is taken, try again." << endl;
						cout << "Select open seat (input as LETTER followed by ROW#): ";
						cin >> seatChoice;
					}
					system("CLS");
					cout << flush;
					cout << "Seat, " << seatChoice << ", has been selected." << endl;
					cout << "Would you like to:" << endl;
					cout << "\t1) Pay for flight and add to bookings" << endl;
					cout << "\t2) Return to Main Menu and lose progress" << endl;
					cin >> choice;
					while (choice != 1 && choice != 2){
						system("CLS");
						cout << flush;
						cout << "INVALID menu choice. Try again." << endl;
						cout << "Seat, " << seatChoice << ", has been selected." << endl;
						cout << "Would you like to:" << endl;
						cout << "\t1) Pay for flight and add to bookings" << endl;
						cout << "\t2) Return to Main Menu and lose progress" << endl;
						cin >> choice;
					}	
						//pay for flight
						if (choice == 1)
						{
							system("CLS");
							cout << flush;
							cout << "\t\tPAY FOR FLIGHT" << endl;
							cout << "\t\t==============" << endl;
							cout << "Flight Summary:  " << endl;
							cout << "Flight#: " << right << setw(41) << flightList[selectedFlight].getFlightNumber() << endl;
							cout << "Departing: " << right << setw(22) << flightList[selectedFlight].getDepartureLocation()
							<< "- " << flightList[selectedFlight].getDepartureDate() <<  " @ " << right << setw(4) << 
							flightList[selectedFlight].getDepartureTime() << endl;
							cout << "Arriving: " << right << setw(23) << flightList[selectedFlight].getArrivalLocation()
							<< "- " << flightList[selectedFlight].getArrivalDate() << " @ " << right << setw(4) <<
							flightList[selectedFlight].getArrivalTime() << endl;
							cout << "==================================================" << endl;
							cout << "Price (tax included): " << right << setw(28) << fixed << setprecision(2) << flightList[selectedFlight].getprice() << endl;
							cout << "==================================================" << endl;
							cout << "1. Pay for flight with CC on account" << endl;
							cout << "2. Cancel and return to main menu" << endl;
							cin >> choice;
							if (choice == 1)
							{
								if (accountList[accountListIter].checkCC() == false)
								{
									system("CLS");
									string ccNum, ccExp;
									cout << "\tERROR, NO CREDIT CARD ON ACCOUNT." << endl;
									cout << "Please enter following credit card information: " << endl;
									cout << "Enter 16 digit Credit Card: ";
									cin >> ccNum;
									accountList[accountListIter].setCreditCardNum(ccNum);
									cout << "Enter expiration date in format MM/YYYY: ";
									cin >> ccExp;
									accountList[accountListIter].setCreditCardExpiration(ccExp);
									system("CLS");
									cout << "Credit card: " << accountList[accountListIter].getCreditCardNum() << " has been saved." << endl;
									cout << "==================================================" << endl;
									cout << "Continue with charge of: " << flightList[selectedFlight].getprice() << "?" << endl;
									cout << "1. Yes" << endl;
									cout << "2. Cancel and return to main menu" << endl;
									cin >> choice;
									if (choice == 1)
									{
										system("CLS");
										//update seating array for specified flight
										flightList[selectedFlight].seats[seatStrToInt(seatChoice)] = 'X';
										//add booking to account
										accountList[accountListIter].addBooking(flightList[selectedFlight].getFlightNumber(), accountList[accountListIter].getID(), seatStrToInt(seatChoice));
										cout << "\t\tSUCCESS!" << endl;
										cout << "\tBOOKING ADDED TO ACCOUNT." << endl;
										cout << "*(Review flights from main menu to edit booking(s)*" << endl;
										cout << "==================================================" << endl;
									}
									else if (choice == 2)
									{
										//do nothing, return to main menu
										system("CLS");
									}
								}
								else
								{
									system("CLS");
									//update seating array for specified flight
									flightList[selectedFlight].seats[seatStrToInt(seatChoice)] = 'X';
									//add booking to account
									accountList[accountListIter].addBooking(flightList[selectedFlight].getFlightNumber(), accountList[accountListIter].getID(), seatStrToInt(seatChoice));
									cout << "\t\tSUCCESS!" << endl;
									cout << "\tBOOKING ADDED TO ACCOUNT." << endl;
									cout << "Card Used: " << accountList[accountListIter].getCreditCardNum() << endl;
									cout << "*(Review flights from main menu to edit booking(s)*" << endl;
									cout << "==================================================" << endl;
								}
							}
							else if (choice == 2)
							{
								//do nothing, return to main menu
								system("CLS");
							}
						}
						//return to main menu
						else if (choice == 2)
						{
							//do nothing, goes to main menu
							system("CLS");
							cout << flush;
						}	
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
					cout << "Select flight to view available seats (Enter flight number): ";
					cin >> flightChoice;
					int selectedFlight;	//assigned flight, initialized in loop below.

					system("CLS");
					cout << flush;
					for (int i = 0; i < flightList.size(); i++)
					{
						if (flightChoice == flightList[i].getFlightNumber())
						{
							selectedFlight = i;
							flightList[i].displaySeats();
						}
					}
					cout << "\nSelect open seat (input as LETTER followed by ROW#): ";
					cin >> seatChoice;
					while (flightList[selectedFlight].seats[seatStrToInt(seatChoice)] == 'X'){
						system("CLS");
						cout << flush;
						flightList[selectedFlight].displaySeats();
						cout << "\nINVALID, seat " << seatChoice<< " is taken, try again." << endl;
						cout << "Select open seat (input as LETTER followed by ROW#): ";
						cin >> seatChoice;
					}
					system("CLS");
					cout << flush;
					cout << "Seat, " << seatChoice << ", has been selected." << endl;
					cout << "Would you like to:" << endl;
					cout << "\t1) Pay for flight and add to bookings" << endl;
					cout << "\t2) Return to Main Menu and lose progress" << endl;
					cin >> choice;
					while (choice != 1 && choice != 2){
						system("CLS");
						cout << flush;
						cout << "INVALID menu choice. Try again." << endl;
						cout << "Seat, " << seatChoice << ", has been selected." << endl;
						cout << "Would you like to:" << endl;
						cout << "\t1) Pay for flight and add to bookings" << endl;
						cout << "\t2) Return to Main Menu and lose progress" << endl;
						cin >> choice;
					}	
						//pay for flight
						if (choice == 1)
						{
							system("CLS");
							cout << flush;
							cout << "\t\tPAY FOR FLIGHT" << endl;
							cout << "\t\t==============" << endl;
							cout << "Flight Summary:  " << endl;
							cout << "Flight#: " << right << setw(41) << flightList[selectedFlight].getFlightNumber() << endl;
							cout << "Departing: " << right << setw(22) << flightList[selectedFlight].getDepartureLocation()
							<< "- " << flightList[selectedFlight].getDepartureDate() <<  " @ " << right << setw(4) << 
							flightList[selectedFlight].getDepartureTime() << endl;
							cout << "Arriving: " << right << setw(23) << flightList[selectedFlight].getArrivalLocation()
							<< "- " << flightList[selectedFlight].getArrivalDate() << " @ " << right << setw(4) <<
							flightList[selectedFlight].getArrivalTime() << endl;
							cout << "==================================================" << endl;
							cout << "Price (tax included): " << right << setw(28) << fixed << setprecision(2) << flightList[selectedFlight].getprice() << endl;
							cout << "==================================================" << endl;
							cout << "1. Pay for flight with CC on account" << endl;
							cout << "2. Cancel and return to main menu" << endl;
							cin >> choice;
							if (choice == 1)
							{
								if (accountList[accountListIter].checkCC() == false)
								{
									system("CLS");
									string ccNum, ccExp;
									cout << "\tERROR, NO CREDIT CARD ON ACCOUNT." << endl;
									cout << "Please enter following credit card information: " << endl;
									cout << "Enter 16 digit Credit Card: ";
									cin >> ccNum;
									accountList[accountListIter].setCreditCardNum(ccNum);
									cout << "Enter expiration date in format MM/YYYY: ";
									cin >> ccExp;
									accountList[accountListIter].setCreditCardExpiration(ccExp);
									system("CLS");
									cout << "Credit card: " << accountList[accountListIter].getCreditCardNum() << " has been saved." << endl;
									cout << "==================================================" << endl;
									cout << "Continue with charge of: " << flightList[selectedFlight].getprice() << "?" << endl;
									cout << "1. Yes" << endl;
									cout << "2. Cancel and return to main menu" << endl;
									cin >> choice;
									if (choice == 1)
									{
										system("CLS");
										//update seating array for specified flight
										flightList[selectedFlight].seats[seatStrToInt(seatChoice)] = 'X';
										//add booking to account
										accountList[accountListIter].addBooking(flightList[selectedFlight].getFlightNumber(), accountList[accountListIter].getID(), seatStrToInt(seatChoice));
										cout << "\t\tSUCCESS!" << endl;
										cout << "\tBOOKING ADDED TO ACCOUNT." << endl;
										cout << "*(Review flights from main menu to edit booking(s)*" << endl;
										cout << "==================================================" << endl;
									}
									else if (choice == 2)
									{
										//do nothing, return to main menu
										system("CLS");
									}
								}
								else
								{
									system("CLS");
									//update seating array for specified flight
									flightList[selectedFlight].seats[seatStrToInt(seatChoice)] = 'X';
									//add booking to account
									accountList[accountListIter].addBooking(flightList[selectedFlight].getFlightNumber(), accountList[accountListIter].getID(), seatStrToInt(seatChoice));
									cout << "\t\tSUCCESS!" << endl;
									cout << "\tBOOKING ADDED TO ACCOUNT." << endl;
									cout << "Card Used: " << accountList[accountListIter].getCreditCardNum() << endl;
									cout << "*(Review flights from main menu to edit booking(s)*" << endl;
									cout << "==================================================" << endl;
								}
							}
							else if (choice == 2)
							{
								//do nothing, return to main menu
								system("CLS");
							}
						}
						//return to main menu
						else if (choice == 2)
						{
							//do nothing, goes to main menu
							system("CLS");
							cout << flush;
						}	
				}
			}
			else if (selection.compare("2") == 0)
			{
				if (accountList[accountListIter].isBookingsEmpty() == true)
				{
					cout << "No bookings were found on account. " << endl;
					cout << "Returning to main menu." << endl;
				}
				else
				{
					string reviewMenuSelect;
					accountList[accountListIter].reviewBookings();
					cout << "Enter flight you want to modify, book, or print flight info for: " << endl;
					cout << "(Enter 0 to go back to main menu)" << endl;
					cout << "Flight #: ";
					cin >> reviewMenuSelect;
					if (reviewMenuSelect != "0")
					{
						system("CLS");
						cout << "\tFlight Chosen: " << reviewMenuSelect << endl;
						cout << "Choose option below: " << endl;
						cout << "\t1. Modify Flight " << endl;
						cout << "\t2. Cancel Booking " << endl;
						cout << "\t3. Print Flight Information " << endl;
						cout << "\t4. Return to main menu " << endl;
						cin >> reviewMenuSelect;
						
						// ================================ MODIFY BOOKING =====================================

						if (reviewMenuSelect == "1")
						{
							{
								int bookingIndex = 0;
								int bookingSeat = 0;

								string seatChoice = "";

								// Match user input to reservation from booking vector
								for (int i = 0; i < accountList[accountListIter].bookingslist.size(); i++)
								{
									if (flightNum == accountList[accountListIter].bookingslist[i].getFlightNumber())
									{
										bookingSeat = accountList[accountListIter].bookingslist[i].getAssignedSeat();
										bookingIndex = i;
									}
								}

								for (int j = 0; j < flightList.size(); j++)
								{
									if (flightNum == flightList[j].getFlightNumber())
									{
										system("CLS");

										cout << "Current Seating Chart:\n";
										flightList[j].displaySeats();

										cout << "\nSelect an open seat you would like to switch to (input as LETTER followed by ROW#): ";
										cin >> seatChoice;

										// Loop to ensure user changes to an empty seat
										while (flightList[j].seats[seatStrToInt(seatChoice)] == 'X')
										{
											system("CLS");
											cout << flush;
											flightList[j].displaySeats();
											cout << "\nINVALID, seat " << seatChoice << " is taken, try again." << endl;
											cout << "Select open seat (input as LETTER followed by ROW#): ";
											cin >> seatChoice;
										}

										// Remove previous booking, update seating chart, and create new booking with new seat.
										accountList[accountListIter].bookingslist.erase(accountList[accountListIter].bookingslist.begin() + bookingIndex);

										flightList[j].seats[bookingSeat] = '_';
										flightList[j].seats[seatStrToInt(seatChoice)] = 'X';

										accountList[accountListIter].addBooking(flightList[j].getFlightNumber(), accountList[accountListIter].getID(), seatStrToInt(seatChoice));
										system("CLS");
										cout << "Booking has been updated.\n\n";
									}
								}
							}
						}

						// ================================ CANCEL BOOKING =====================================

						else if (reviewMenuSelect == "2")
						{
							accountList[accountListIter].cancelBooking(flightNum, flightList);
						}

						// ================================ PRINT BOOKING ======================================

						else if (reviewMenuSelect == "3")
						{
							accountList[accountListIter].printBooking(flightNum, flightList);
						}
						else if (reviewMenuSelect == "4")
						{
							//do nothing
							//clear screen and go back to main menu
							system("CLS");
						}
					}
					else
					{
						//do nothing
						//clear screen and go back to main menu
						system("CLS");
					}

				}
			}
			else if (selection.compare("3") == 0) 
			{
				cout << "Thank you for using Northeast Airlines. Have a great day!" << endl;
			}
			else 
			{
				cout << "Invalid selection." << endl;
			}
		}
	}
	cout << endl;
	system("pause");
	return 0;
}
