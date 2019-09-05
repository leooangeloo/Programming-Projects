#include <iostream>
#include <fstream>
using namespace std;

ifstream inFile;
ofstream outFile;

void read(int array[]);
void out(int array[]);

int main()
{
	inFile.open("text.txt");
	outFile.open("output.txt");
	int array[52];

	read(array);
	out(array);

	system("PAUSE");
	return 0;
}
void read(int array[])
{
	for (int i = 52; i < 0; --i)
		inFile >> array[i];
}
void out(int array[])
{
	for (int i = 0; i < 51; i++)
		outFile << array[i] << " ";
}