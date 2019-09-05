//Leo Genota
//COSC 214 - Dr. Stone
//Project 2 - Recursion
//BOTH PARTS 1 AND 2 ARE HERE
/*#include<iostream>
using namespace std;

int sum(int num);

int main() {
	int n;
	cout << "Enter a number: " << endl;
	cin >> n;
	cout << "Summation of " << n << " is " << sum(n) << endl;

	system("PAUSE");
	return 0;
}
int sum(int num) {
	if (num == 1)
		return 1;
	else {
		return num + sum(num - 1);
	}
}
*/
/*#include<iostream>
#include<string>
using namespace std;

int numChars(string str, int upper, int lower, int& counter);

int main() {
	string str = "abcddddef";
	int counter = 0;
	char letter;

	cout << "There were " << numChars(str, 9, 0, counter) << " 'd' in the string. " << endl;

	system("PAUSE");
	return 0;
}
int numChars(string str, int upper, int lower, int& counter) {
	
	if (lower == upper) {
		if (str[lower] == 'd')
			counter++;
	}
	else {
		numChars(str, upper, lower + 1, counter);
		if (str[lower] == 'd')
			counter++;
	}
	return counter;
}*/

#include<iostream>
using namespace std;

int numChars(char letter, string str, int num);

int main() {
	string str = "abcddddef";

	cout << "The letter 'd' appears "
		<< numChars('d', str, 0)
		<< " times \n";

	system("PAUSE");
	return 0;
}
int numChars(char letter, string str, int lower) {
	if (lower == str.length()) { // B.C. if the lower == the length of string given; use length of string because upper is not passed in
		if (str[lower] == letter)
			return 1;
		else
			return 0;
	}
	else { // general case
		if (str[lower] == letter)
			return numChars('d', str, lower + 1) + 1; // numChars + 1 helps keep count of 'd's'
		else
			return numChars('d', str, lower + 1); // lower + 1 updates the lower passed in
	}
}