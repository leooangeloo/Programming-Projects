#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<stdlib.h>
using namespace std;

ifstream inFile;
ofstream outFile;

struct server1 {
	string first;
	int SSN;
	server1 *link1;
};
server1 * head1;

struct server2 {
	string last;
	string DOB;
	server2 * link2;
};
server2 * head2;

bool passwordEntry(string password) {
	string pass; bool statement;
	cout << "To access database, enter password: ";
	cin >> pass;

	if (pass != password) {
		statement = false;
		while (pass != password && statement == false) {
			cout << "Wrong password. Try Again:" << endl;
			cin >> pass;
			if (pass == password) {
				statement = true;
				return statement;
			}
		}
	}
	else {
		statement = true;
		return statement;
	}
}
void read(server1 *& head1, server2 *& head2) {
	server1 * current1 = NULL, *tail1 = NULL;
	server2 *current2 = NULL, *tail2 = NULL;
	string fName, lName, doB; int social;
	for (int i = 0; i < 50; i++) {
		inFile >> fName >> lName >> social >> doB;
		current1 = new server1;
		current2 = new server2;
		current1->first = fName;
		current2->last = lName;
		current1->SSN = social;
		current2->DOB = doB;
		current1->link1 = NULL;
		current2->link2 = NULL;
		if (head1 == NULL) { head1 = current1; tail1 = current1; }
		else {
			tail1->link1 = current1;
			tail1 = current1;
		}
		if (head2 == NULL) { head2 = current2; tail2 = current2; }
		else {
			tail2->link2 = current2;
			tail2 = current2;
		}
	}
}
void add(server1 *& head1, server2 *& head2) {
	try {
		string fName, lName, doB;
		int social; char done;
		cout << "You selected to add a client." << endl;
		cout << "To add, enter 1: ";
		cin >> done;
		if (done == '1') {
			while (done != '#') {
				server1 * current1 = NULL, *tail1 = NULL;
				server2 * current2 = NULL, *tail2 = NULL;
				cout << "First Name: ";
				cin >> fName; cout << endl;
				if (!cin) throw fName;
				cout << "Last Name: ";
				cin >> lName; cout << endl;
				if (!cin) throw lName;
				cout << "Social Security #: ";
				cin >> social; cout << endl;
				if (!cin) throw social;
				cout << "DOB (MM/DD/YYYY): ";
				cin >> doB; cout << endl;
				if (!cin) throw doB;
				current1 = new server1;
				current1->first = fName;
				current1->SSN = social;
				current1->link1 = NULL;
				if (head1 == NULL) { head1 = current1; }
				else {
					tail1 = head1;
					while (tail1->link1 != NULL)
						tail1 = tail1->link1;
					tail1->link1 = current1;
				}
				current2 = new server2;
				current2->last = lName;
				current2->DOB = doB;
				current2->link2 = NULL;
				if (head2 == NULL) { head2 = current2; }
				else {
					tail2 = head2;
					while (tail2->link2 != NULL)
						tail2 = tail2->link2;
					tail2->link2 = current2;
				}
				cout << "If done, enter #; if not enter 1: ";
				cin >> done;
			}
		}
		else throw done;
	}
	catch (char) {
		cout << "Invalid input into database. Program is exiting." << endl;
		system("PAUSE");
		exit(EXIT_FAILURE);
	}
	catch (int) {
		cout << "Invalid input into database. Program is exiting." << endl;
		system("PAUSE");
		exit(EXIT_FAILURE);
	}
	catch (string) {
		cout << "Invalid input into database. Program is exiting." << endl;
		system("PAUSE");
		exit(EXIT_FAILURE);
	}

}
void del(server1 *& head1, server2 *& head2) {
	server1 * current1; server2 * current2;
	string fName, lName;
	int loc;


	cout << "Enter first and last name you would like to delete: ";
	cin >> fName >> lName;

	
}
void print(server1 * head1, server2 * head2) {
	server1 * current1 = NULL;
	server2 * current2 = NULL; int i = 0;
	current1 = head1; current2 = head2;
	outFile << "Client Information (First Name Last Name, SSN, & DOB): \n" << endl;
	while (current1 != NULL && current2 != NULL) {
		outFile << current1->first << " " << current2->last << ", " << "Social Security #: " << current1->SSN << " DOB: " << current2->DOB << endl;
		current1 = current1->link1; current2 = current2->link2;
	}
}
