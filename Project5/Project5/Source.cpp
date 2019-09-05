#include  <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream inFile;
ofstream outFile;

int main() 
{
	inFile.open("students.txt");
	outFile.open("maleDeansList.txt");

	double gpa;
	char gender;
	string fname, lname;

	inFile >> fname >> lname >> gender >> gpa;

	while (!inFile.eof())
	{
		if ((gender == 'm') && (gpa >= 3.00))
		{
			outFile << fname << " " << lname << endl;
		}
		inFile >> fname >> lname >> gender >> gpa;
	}
	inFile.close();
	outFile.close();

	system("PAUSE");
	return 0;

}