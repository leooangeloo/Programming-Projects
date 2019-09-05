#include <iostream>

using namespace std;

int main()
{
	int num = 3;
	{
		switch (num)
		{
		case 1: cout << " : Monday"; break;
		case 2: cout << " : Tuesday"; break;
		case 3: cout << " : Wednesday"; break;
		case 4: cout << " : Thursday"; break;
		case 5: cout << " : Friday"; break;

		default: cout << " : Weekend day"; 

		}
	}
	system("PAUSE");
	return 0;

}