#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<ctime>
#include"funct.h"
using namespace std;

int main() {
	try {
		bankClientInfo starter;
		string pass = "Genota!"; int i = 0, enter = 1;
		fout.open("receipt.txt");

		while (enter != 0) {
			starter.passwordEntry(pass);
			starter.accountInput(first, last, i);
			i++;
			starter.print(first);
			cout << "To exit, enter 0; to continue, enter any number: ";
			cin >> enter;
			if (!enter) throw enter;
		}
		system("PAUSE");
		return 0;
	}
	catch (int) {
		cout << "Database is closing" << endl;
		system("PAUSE");
		exit(EXIT_FAILURE);
	}
}
