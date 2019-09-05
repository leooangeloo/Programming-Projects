#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<stdlib.h>
#include<ctime>
using namespace std;

ifstream inFile;
ofstream outFile;

struct server1 {
	string first;
	int SSN;
	char pass[6];
	server1 *link;
};
server1 * head = NULL;

struct server2 {
	string last;
	string DOB;
	char pass[6];
};

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
void read(server1 *& head1, server2 arr[]) {

	int i = 0, num;
	server1 *current = NULL, *tail = NULL;

	while (!inFile.eof()) {
		current = new server1;
		inFile >> current->first >> arr[i].last >> current->SSN >> arr[i].DOB;
		current->link = NULL;

		if (head == NULL) {
			head = current;
			tail = current;
		}
		else {
			tail->link = current;
			tail = current;
		}
		for (int j = 0; j < 7; j++) {
			num = rand() % 26;
			current->pass[j] = static_cast<char>(num + 65);
			arr[j].pass[j] = static_cast<char>(num + 65);
		}
		current->pass[6] = '\0';
		arr[i].pass[6] = '\0';
		i++;
	}
}
void add(server1 *& head, server2 arr[], int &i) {
	
	server1 * current = NULL, *tail = NULL;
	current = new server1;
	
	cout << "Enter personal information "
		<< "(First name Last Name SSN MM/DD/YYYY): " << endl;
	cin >> current->first >> arr[i].last >> current->SSN >> arr[i].DOB;

	current->link = NULL;
	tail = head;
	while (tail->link != NULL) {
		tail = tail->link;
	}
	tail->link = current;
	tail = current;
	i++;
}
void del(int val, server2 arr[])
{
	string lName, doB;
	server1 * current = NULL, *delt = NULL, *tail = NULL;

	tail = head;
	while (tail != NULL)
		tail = tail->link;

	if (head->SSN == val) {
		// point to the node to be deleted 
		delt = head;
		// update 
		head = delt->link;
		delete delt;
		return;
	}

	current = head;
	delt = head->link;

	// traverse the list and check the value of each node 
	while (delt != NULL) {
		if (delt->SSN == val) {
			// Update the list 
			current->link = delt->link;
			// If it is the last node, update the tail 
			if (delt == tail) {
				tail = current;
			}
			delt->first = "n/a";// Here only remove the first node with the given value 
			delt->SSN = 0;
			break; // break and return
		}
		current = delt;
		delt = delt->link;
	}
	cout << "For added security, enter last name of client AND date of birth (MM/DD/YYYY): " << endl;
	cin >> lName >> doB;
	for (int i = 0; i < 60; i++) {
		if (arr[i].last == lName && arr[i].DOB == doB) {
			arr[i].last = " ";
			arr[i].DOB = " ";
		}
	}
}
void print(server1 * head, server2 arr[]) {
	server1 * current = NULL;
	int i = 0;
	outFile << "Client Information (First Name Last Name, SSN, & DOB): \n" << endl;
	
	current = head;
	
	while (current != NULL) {
		if (current->first == " " || current->SSN == 0 || arr[i].last == " " || arr[i].DOB == " ")
		{
			outFile << " " << " " << arr[i].last << " " << " " << " " << arr[i].DOB << endl;
			i++;
		}
		else {
			outFile << current->first << " " << arr[i].last
				<< " " << current->SSN << " " << arr[i].DOB << endl;
			current = current->link;
			i++;
		}
	}
}