
#include <iostream>
#include <string>
#include<fstream>
using namespace std;

ifstream inFile;
ofstream outFile;


int main()
{

	//declaration

	inFile.open("Balance.txt");
	outFile.open("Receipt.txt");
	double balance, wdraw, fbalance, Fbalance, service1, service2, Service;
	int answer;

	//input
	inFile >> balance;

	cout << "Hi there! How much money would you like to withdraw today?" << endl;
	cin >> wdraw;

	//calculation
	fbalance = balance - wdraw;
	service1 = 25;
	service2 = (0.04*(wdraw - 300));
	Service = service1 + service2;

	if (wdraw > 500)
	{
		cout << "Sorry you are only permitted to withdraw $500 at a time. Have a nice day." << endl;
	}
	if (balance <= 0)
	{
		cout << "Sorry there is no available money in your account and you aren't permitted to make a withdrawal. Have a nice day:)" << endl;
		{ Fbalance = balance;
		outFile << "Original Balance...........$" << balance << endl;
		outFile << "Amount Withdrawn...........$0" << endl;
		outFile << "Final Balance..............$" << Fbalance << endl;
		}
	}
	else if (balance > 0 && balance < wdraw)
	{
		cout << "You have insufficient funds. However, you can withdraw this amount for a service fee of $25. Would you like to withdraw $" << wdraw << "? Enter 1 for Yes and 2 for No." << endl;
		cin >> answer;
		if (answer == 1 && wdraw <= 300)
		{
			Fbalance = fbalance - service1;
			outFile << "Original Balance..........." << balance << endl;
			outFile << "Amount Withdrawn..........." << wdraw << endl;
			outFile << "Service Fee................$25" << endl;
			outFile << "Final Balance................" << Fbalance << endl;
			cout << "Please grab your receipt." << endl;
		}
		else if (answer == 1 && wdraw >= 301)
		{
			cout << "There is an additional service charge of 4% for everything withdrawn over $300." << endl;
			Fbalance = fbalance - Service;
			outFile << "Original Balance...........$" << balance << endl;
			outFile << "Amount Withdrawn...........$" << wdraw << endl;
			outFile << "Service Fee................$" << Service << endl;
			outFile << "Final Balance..............$" << Fbalance << endl;
			cout << "Please grab your receipt." << endl;
		}
		else 
		{
				Fbalance = balance;
				cout << "Have a nice day. Your balance is $" << Fbalance << endl;
		}
	}
	else
		if (wdraw > 300 && wdraw < 500)
		{
			Fbalance = fbalance - (0.04*(wdraw - 300));
			cout << "There is a service charge of 4% for everything withdrawn over $300. Please grab your receipt." << endl;
			outFile << "Original Balance...........$" << balance << endl;
			outFile << "Amount Withdrawn...........$" << wdraw << endl;
			outFile << "Service Fee................$" << service2 << endl;
			outFile << "Final Balance..............$" << Fbalance << endl;
		}

	inFile.close();
	outFile.close();

	system("PAUSE");
	return 0;
	

}
