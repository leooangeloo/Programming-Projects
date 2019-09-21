/*
Bowling Game Exercise (Anthem Engineering) - bowlingGameExercise.cpp
This program calculates the total score of one game of bowling for one player.
Sample test cases: X-X-X-X-X-X-X-X-X-X-XX | 45-54-36-27-09-63-81-18-90-72 
5/-5/-5/-5/-5/-5/-5/-5/-5/-5/-5 | 45-54-36-27-09-63-81-18-90-7/-5
@Author: Leo Angelo Genota
Date: September 20, 2019
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int totalScore(string); //Calculates the total score of one game of bowling
string convertString(string oldString); //Takes the tacks out of the string

int main() {
	try {

		string input;

		cout << "Enter the string of the score for one game of bowling: ";
		cin >> input;
		if(!cin)
			throw(input);

		cout << "Score: " << totalScore(convertString(input)) << endl;

	}
	catch (string) { // This catch is for invalid inputs for cin

		cout << "The input is invalid. Exiting the program. " << endl;
		cout << "Thank you for using the Bowling Game Calculator" << endl;

	}
	return 0;
}

int totalScore(string in) {
	int score = 0, con = 0;

	for (int i = 0; i < in.size(); i++) {
	
		if (i < 2 && in.at(i) == 'X') { // This condition is for if the first few throws are strikes

			score += 10;
			if (i == 1 && in.at(i - 1) == 'X')
				score += 10;

		}
		else if (in.at(i) == '/') { // The earliest there can be a spare

			score += 10;

		}
		else if (in.at(i) == ' ')
			continue;
		else if (i >= 2 && in.at(i) == 'X') { // This condition is for if ater the first few throws, any other strikes

			score += 10;

			if (in.at(i + 1) == 'X' && in.at(i + 3) == ' ') {

				score += 50;
				break;

			}

			if (in.at(i - 2) == 'X')
				score += 10;

			if (in.at(i - 1) == 'X')
				score += 10;

		}
		// Next two if-else's are for if i >= 2 and i-2 or i-1 was an X and i itself is not an X
		else if (i >= 2 && in.at(i - 2) == 'X' && in.at(i) != 'X' && in.at(i) != ' ') {

			score += 10;
			con = in.at(i) - '0'; // converts char to int 
			score += con;

		}
		else if (i >= 2 && in.at(i - 1) == 'X' && in.at(i) != 'X' && in.at(i) != ' ') {

			score += 10;
			con = in.at(i) - '0'; // converts char to int 
			score += con;

		}
		else {

			if (in.at(i + 1) == '/' && in.at(i + 3) == ' ') { 

				con = in.at(i + 2) - '0';
				score += con + 10;
				break;

			}
			else {

				con = in.at(i) - '0'; // converts char to int 
				score += con;

			}

		}
	}
	return score;
}

string convertString(string oldString) {
	string newString = oldString;

	// This for-loop erases '-' dashes and takes valid characters and puts it into a new string
	for (int i = 0; i < oldString.length(); i++) {

		if (oldString.at(i) >= 47 && oldString.at(i) <= 57 || oldString[i] == 88) {

			newString.at(i) = oldString.at(i);
			oldString.erase(remove(oldString.begin(), oldString.end(), '-'), oldString.end());

		}

	}

	// This for-loop replaces the remaining elements with spaces 
	for (int i = oldString.length(); i < newString.length(); i++)
		newString.at(i) = ' ';

	return newString;
}