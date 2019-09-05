//LEO GENOTA
//COSC 214 - DR.STONE
//PROJECT 4 - takes in characters and converts 
//them into capital letters and counts vowels
#include<iostream>
#include<fstream>
#include "linkedQueue.h"
using namespace std;

ifstream infile;
ofstream outfile;

void convertAndDisplay(LinkedQueueType & queue);

int main() {
	LinkedQueueType queue;
	char ch;
	infile.open("input.txt");
	outfile.open("output.txt");

	while (!infile.eof()) {
		infile.get(ch);
		queue.addQueue(ch);
	}

	convertAndDisplay(queue);

	system("PAUSE");
	return 0;
}
void convertAndDisplay(LinkedQueueType & queue) {
	int A = 0, E = 0, I = 0, O = 0, U = 0;
	int newLine = 0;
	while (!queue.isEmptyQueue()) {
		outfile << static_cast<char>(toupper(queue.front())) << " ";
		newLine++;
		switch (static_cast<char>(toupper(queue.front()))) {
		case 'A': A++;
			break;
		case 'E': E++;
			break;
		case 'I': I++;
			break;
		case 'O': O++;
			break;
		case 'U': U++;
			break;
		}
		// THIS IF STATEMENT ALLOWS 10 CHARS PER LINE
		if (newLine == 10) {
			newLine = 0;
			outfile << endl;
		}
		queue.deleteQueue();
	}
	cout << "VOWEL COUNT: " << endl;
	cout << "A - " << A << endl;
	cout << "E - " << E << endl;
	cout << "I - " << I << endl;
	cout << "O - " << O << endl;
	cout << "U - " << U << endl;
	cout << "*** THE CAPITALIZED LETTERS ARE IN OUTPUT FILE *** " << endl;
}
