#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

ofstream fout;

struct client {
	string fName, lName;
	int acctNum[16], acctMoney;
	client * prev;
	client * next;
};
client * first = NULL;
client * last = NULL;

class bankClientInfo {
private:
	string password;
	int num;
public:
	bool passwordEntry(string);
	void accountInput(client *& first, client *& last, int &i);
	void print(client* first);
};

bool bankClientInfo::passwordEntry(string password) {

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
void bankClientInfo::accountInput(client *& first, client *& last, int &i) {

	client * newNode = NULL;
	newNode = new client;

	cout << "------------------------------------------------" << endl;
	cout << "               Client Information               " << endl;
	cout << "Enter First Name:..............................." << endl;
	cin >> newNode->fName;
	cout << "Enter Last Name:................................" << endl;
	cin >> newNode->lName;
	cout << "Account Number:................................." << endl;
	for (int i = 0; i < 16; i++) {
		newNode->acctNum[i] = rand() % 26;
	}
	for (int i = 0; i < 16; i++) {
		cout << newNode->acctNum[i];
	}
	cout << endl;
	newNode->acctMoney = 0;
	if (first == NULL) {
		first = newNode;
		last = newNode;
	}
	else {
		newNode->prev = last;
		last->prev = newNode;
		last = newNode;
	}
}
void bankClientInfo::print(client * first) {
	client * current = NULL;
	int i = 0;
	current = first;

	while (current != NULL) {
		fout << current->fName << current->lName // Throws a Read-Access violation 
			<< " Acct. Num: " << current->acctNum[i]
			<< " Amount of Money: " << current->acctMoney << endl;
		i++;
		current = current->next;
	}

}