//Jeremiah Gathers, Leo Genota, Isaiah Gregory, Tyra Harrison
//COSC 208 - SET OPERATIONS PROJECT/PROGRAM
//DR. JI - DECEMBER 11, 2017
#include<iostream>
using namespace std;

void mainpulate(char setAarray[], char setBarray[], int, int, int&, int&);
void unionSet(char setAarray[], char setBarray[], int, int);
void diffSet(char setAarray[], char setBarray[], int, int);
void symmDiff(char setAarray[], char setBarray[], int, int);
void complement(char setAarray[], char setBarray[], int, int);  //function declarations 

int main() {  //main function where menu is displayed and input is taken
	int input, ctA = 0, ctB = 0;
	const int counta = 15, countb = 15;

	char setAarray[counta] = { " " }, setBarray[countb] = { " " }; //declaring the two set arrays
	try {
		cout << "Welcome User! Select one of the following choices"
			<< " by entering the corresponding letter. " << endl;
		cout << "(0) - change objects in the 2 sets" << endl;
		cout << "(1) - display the union of sets" << endl;
		cout << "(2) - display the difference of sets" << endl;
		cout << "(3) - diplay the symmetric difference of sets" << endl;
		cout << "(4) - display the complement of the sets" << endl;
		cout << "(-999) - quit the program" << endl;
		cout << endl;
		do {
			cout << "Selection:";
			cin >> input;
			cout << endl;
			if (input != 0 && input != 1 && input != 2 && input != 3 && input != 4 && input != -999)
				throw input;   //does not accept a menu choice that is not one of the given options
			if (input == 0)
				mainpulate(setAarray, setBarray, counta, countb, ctA, ctB);
			else if (input == 1)
				unionSet(setAarray, setBarray, ctA, ctB);
			else if (input == 2)
				diffSet(setAarray, setBarray, ctA, ctB);
			else if (input == 3)
				symmDiff(setAarray, setBarray, ctA, ctB);
			else if (input == 4)                          //if statements that take the user to their menu choice
				complement(setAarray, setBarray, ctA, ctB);
			else if (input == -999)
				cout << "PROGRAM CLOSING. . ." << endl;
		} while (input != -999); //continue to ask for a menu choice until user decides to quit
	}
	catch (int) {
		cout << "The input is invalid. Program closing . . ." << endl;
		system("PAUSE");
		exit(EXIT_FAILURE);
	}          //what the user sees when they input an invalid menu selection
	system("PAUSE");
	return 0;
}
void mainpulate(char setAarray[], char setBarray[], int counta, int countb, int & ctA, int & ctB) {
	char ch;
	cout << "Enter character elements for set A: (Enter # if done) " << endl;
	for (int i = 0; i < counta; i++) {
		cin >> ch;
		if (ch == '#')
			break;
		setAarray[i] = ch;
		ctA++;
	}              //user inputs their elements for set a; they enter "#" when they are done
	cout << endl;
	cout << "Enter character elements for set B: (Enter # if done) " << endl;
	for (int j = 0; j < countb; j++) {
		cin >> ch;
		if (ch == '#')
			break;
		setBarray[j] = ch;
		ctB++;
	}             //user inputs their elements for set b; they enter "#" when they are done
	cout << endl;
}
void unionSet(char setAarray[], char setBarray[], int ctA, int ctB) {
	const int num = 30;
	int num2 = 30;
	int i = 0;
	char tempArr[num] = { ' ' };   //temporary array used o hold what will be outputted to the user
	cout << "The union of set A and set B: U = { ";
	for (int j = 0; j < ctA; j++) {
		tempArr[i] = setAarray[j];
		i++;
	}
	for (int k = 0; k < ctB; k++) {
		tempArr[i] = setBarray[k];
		i++;
	}
	for (int i = 0; i < num2; ++i)
		for (int j = i + 1; j < num2;) {
			if (tempArr[i] == tempArr[j]) {
				for (int k = j; k < num2 - 1; ++k)
					tempArr[k] = tempArr[k + 1];
				--num2; // deletes a repeating element
			}
			else
				++j;
		}

	for (int i = 0; i < sizeof(tempArr) / sizeof(tempArr[0]); i++) {
		if (tempArr[i] != ' ' && tempArr[i] != '\0') {
			if (i == sizeof(tempArr) / sizeof(tempArr[0]) - 1)
				cout << tempArr[i];
			else
				cout << tempArr[i] << " ";
		}
	}
	cout << "}" << endl;
	cout << endl;
} //this function checks to see what elements the two sets have in common and then displays them from a new array; it will also check
  //to make sure the same element is not output twice in the union set
void diffSet(char setAarray[], char setBarray[], int ctA, int ctB) {
	bool found;
	int t = 0;
	const int num = 30;
	char tempArr[num] = { ' ' };
	int num2 = 30;
	cout << "The difference of set A and set B: D = { ";
	for (int i = 0; i < ctA; i++) {
		int count = 0;
		found = false;
		for (int j = 0; j < ctB; j++) {
			if (setAarray[i] == setBarray[j]) {
				found = true;
				count++;      //finds all elements that both sets have
			}
			if (found == true)
				break;        //does not take similar elements for the difference set
		}
		if (count == 0)
			tempArr[t] = setAarray[i];
		t++;           //adds an element that is only in one set to the new array for difference set
	}
	for (int i = 0; i < num; i++) {
		if (tempArr[i] != ' ' && tempArr[i] != '\0') {
			if (i == (num - 1))
				cout << tempArr[i];
			else
				cout << tempArr[i] << " ";    //displays the new array as the difference set
		}
	}
	cout << "}" << endl;
	cout << endl;
}
void symmDiff(char setAarray[], char setBarray[], int ctA, int ctB) {
	bool found;
	int t = 0;
	const int num = 30;
	char tempArr[num] = { ' ' };
	int num2 = 30;
	cout << "The symmetric difference of set A and set B: S = { ";
	for (int i = 0; i < ctA; i++) {
		int count = 0;
		found = false;
		for (int j = 0; j < ctB; j++) {
			if (setAarray[i] == setBarray[j]) {
				found = true;
				count++;
			}
			if (found == true)
				break;   //skips elements that the two sets have in common 
		}
		if (count == 0)
			tempArr[t] = setAarray[i];  //takes all elements from set a if there are no common ones
		t++;
	}
	for (int j = 0; j < ctB; j++) {
		int count = 0;
		found = false;
		for (int i = 0; i < ctA; i++) {
			if (setAarray[i] == setBarray[j]) {
				found = true;
				count++;
			}
			if (found == true)
				break;
		}
		if (count == 0)
			tempArr[t] = setBarray[j]; //takes all elements from set b if there are no common ones 
		t++;
	}
	for (int i = 0; i < num2; ++i)
		for (int j = i + 1; j < num2;) {
			if (tempArr[i] == tempArr[j]) {
				for (int k = j; k < num2 - 1; ++k)
					tempArr[k] = tempArr[k + 1];
				--num2; // deletes a repeating element
			}
			else
				++j;
		}
	for (int i = 0; i < num; i++) {
		if (tempArr[i] != ' ' && tempArr[i] != '\0') {
			if (i == (num - 1))
				cout << tempArr[i];
			else
				cout << tempArr[i] << " ";  //outputs the new set in the temporary array
		}
	}
	cout << "}" << endl;
	cout << endl;
}
void complement(char setAarray[], char setBarray[], int ctA, int ctB) {
	bool found;
	int t = 0;
	char set;
	const int num = 30;
	char tempArr[num] = { ' ' };
	int num2 = 30;
	try {
		cout << "Which set would you like to find the complement to"
			<< " (enter 'A' or 'B')?" << endl;
		cin >> set;
		if (!cin)
			throw set;                    //asks user to input which set they would like to find the complement for 
		if (set == 'A' || set == 'a') {
			cout << "The Complement of set A: C = { ";
			for (int j = 0; j < ctB; j++) {
				int count = 0;
				found = false;
				for (int i = 0; i < ctA; i++) {
					if (setAarray[i] == setBarray[j]) {
						found = true;
						count++;
					}
					if (found == true)
						break;
				}
				if (count == 0)
					tempArr[t] = setBarray[j];
				t++;
			}
			for (int i = 0; i < num2; ++i)
				for (int j = i + 1; j < num2;) {
					if (tempArr[i] == tempArr[j]) {
						for (int k = j; k < num2 - 1; ++k)
							tempArr[k] = tempArr[k + 1];
						--num2; // deletes a repeating element
					}
					else
						++j;
				}
			for (int i = 0; i < num; i++) {
				if (tempArr[i] != ' ' && tempArr[i] != '\0') {
					if (i == (num - 1))
						cout << tempArr[i];
					else
						cout << tempArr[i] << " ";
				}
			}
			cout << "}" << endl;
			cout << endl;
		}// end complement of Set A
		else if (set == 'B' || set == 'b') {
			cout << "The Complement of set B: C = { ";
			for (int i = 0; i < ctA; i++) {
				int count = 0;
				found = false;
				for (int j = 0; j < ctB; j++) {
					if (setAarray[i] == setBarray[j]) {
						found = true;
						count++;
					}
					if (found == true)
						break;
				}
				if (count == 0)
					tempArr[t] = setAarray[i];
				t++;
			}
			for (int i = 0; i < num2; ++i)
				for (int j = i + 1; j < num2;) {
					if (tempArr[i] == tempArr[j]) {
						for (int k = j; k < num2 - 1; ++k)
							tempArr[k] = tempArr[k + 1];
						--num2; // deletes a repeating element
					}
					else
						++j;
				}
			for (int i = 0; i < num; i++) {
				if (tempArr[i] != ' ' && tempArr[i] != '\0') {
					if (i == (num - 1))
						cout << tempArr[i];
					else
						cout << tempArr[i] << " ";
				}
			}
			cout << "}" << endl;
			cout << endl;
		}// end complement of Set B
	}
	catch (char) {
		cout << "The input is invalid. Program closing . . ." << endl;
		system("PAUSE");
		exit(EXIT_FAILURE);      //output user sees when they input an invalid selection of a set
	}
}