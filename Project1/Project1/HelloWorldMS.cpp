
#include <iostream>

using namespace std;

int main()
{
	//declaration section

	int num = 35;

	//input section

	cout << "Guess a number between 1 and 100." << endl;
	cin >> num;

	//computation section

	if (num == 35)
	{
		cout << "Correct!" << endl;
	}
	else
	{
		cout << "Incorrect. Guess again." << endl;
	}

	//output section

	system("Pause");
		return 0;
}
