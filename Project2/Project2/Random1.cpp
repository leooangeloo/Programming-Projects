/*Leo Genota
September 11, 2016
This program's purpose is to calculate the total price of a vehicle after the price, sales tax and the license fee are input.
*/


#include <iostream>

using namespace std;

int main()
{
	int price, licenseFee, totalPrice;
	double salesTax;

	cout << "Enter the price of the vehicle: " << endl;
	cin >> price;
	cout << "Enter the license fee for the vehicle." << endl;
	cin >> licenseFee;
	cout << "Enter the sales tax for the vehicle." << endl;
	cin >> salesTax;

	totalPrice = price + (price * salesTax) + licenseFee;

	cout << "The total price of the vehicle is: " << totalPrice << endl;

	system("PAUSE");
	return 0;
}