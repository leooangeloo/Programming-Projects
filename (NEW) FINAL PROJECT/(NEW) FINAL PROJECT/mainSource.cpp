#include<iostream>
#include<fstream>
#include<string>
#include"newfunc.h"
using namespace std;


int main() {
	try {
		server2 arr[55];
		int enter, newenter, val, i = 50;
		string password = "Genota!";
		inFile.open("clientInfo.txt");
		outFile.open("outputClientInfo.txt");
		
			read(head, arr);
			if (passwordEntry(password) == true) {
				cout << "~~~~~~~~~~~~~~~~~~Welcome to the Database~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "Options:......................................................" << endl;
				cout << "If you would like to add a new client, enter 1................" << endl;
				cout << "If you would like to delete a client, enter 2................." << endl;
				cout << "If you would like to print the database, enter 3.............." << endl;
				cout << "If you would like to exit the database, enter 0..............." << endl;
				do {
					cout << "Selection: "; cin >> enter;

					if (enter == 1) {
						add(head, arr, i);
						cout << endl;
					}
					if (enter == 2) {
						cout << "Enter client SSN you are deleting: "; cin >> val;
						del(val, arr);
						cout << endl;
					}
					if (enter == 3) {
						print(head, arr);
						cout << "Check File." << endl;
						system("PAUSE");
						exit(EXIT_SUCCESS);
					}
					if (enter == 0) {
						cout << "Database is exiting." << endl;
						system("PAUSE");
						exit(EXIT_FAILURE);
					}
				}while (enter != 0);
			}
		
		system("PAUSE");
		return 0;
	}
	catch (int) {
		cout << "Invalid input into database. Program is exiting." << endl;
		system("PAUSE");
		exit(EXIT_FAILURE);
	}
}


