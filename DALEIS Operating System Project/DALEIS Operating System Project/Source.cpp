/*
* Name: DALEIS Operating System
* Filename: Source.cpp
* @author Leo  Genota
* @author Daniel Francois III
* @author Isaiah Gregory
* This project might require changed settings:
* (1) Project -> Project Properties -> C/C++ -> General
* -> Common Language RunTime Support -> CLRTS (/clr)
* (2) Project -> Project Properties -> C/C++ -> All Options
* -> Conformance Mode -> No
* (3) Project -> Project Properties -> C/C++ -> General
* -> C++ Language Standard -> the latest version
*/
#include "processes.h"
#include <queue>
#include <string>
#define ever ;;

void menu();
void exec(int x);

queue<int> jobList;

int main() {
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~ Welcome to DALEIS Operating System ~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "This is a simple operating system that alllows for proc-" << endl;
	cout << "esses and memory management. This system allows for only" << endl;
	cout << "one process to run and terminates a RUNNING process when" << endl;
	cout << "another process is called by the user to run. There are " << endl;
	cout << "10 READY processes that, when selected, will run. For the" << endl;
	cout << "memory management, the system utilizes a queue and a " << endl;
	cout << "struct that act as the memory and process control blocks" << endl;
	cout << "for the system." << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << endl;

	//Function to initialize the PCB of the processes
	initializeProcesses();

	//Function to start the menu
	menu();

	return 0;
}

void menu() {

	try {

		int value;

		for (ever) {
			cout << "Select from the following applications: " << endl;
			cout << "1. Google Chrome" << endl;
			cout << "2. Microsoft Word" << endl;
			cout << "3. Microsoft Excel" << endl;
			cout << "4. Wireshark" << endl;
			cout << "5. Microsoft PowerPoint" << endl;
			cout << "6. Notepad++" << endl;
			cout << "7. Notepad" << endl;
			cout << "8. Adobe Reader" << endl;
			cout << "9. Microsoft Paint" << endl;
			cout << "10. Windows Media Player" << endl;
			cout << "11. Processes Information" << endl;
			cout << "12. User Manual for the OS" << endl;
			cout << "Enter 0 to exit the OS" << endl;
			cout << endl;

			cout << "Please choose a program to execute: ";
			cin >> value;
			cout << endl;

			if (value < -10 && value < 12)
				throw(value);



			if (jobList.empty()) {
				if (value > 0 && value != 11 && value != 12) {
					cout << "MEMORY BEING ALLOCATED FOR THE PROCESS . . ." << endl;
					jobList.push(value);
					exec(jobList.front());

					if (value <= -1)
						cout << "CURRENTLY NO PROCESS RUNNING . . ." << endl;
					else {
						cout << "CURRENTLY " << jobList.size() << "(MAX) PROCESS RUNNING . . ." << endl;
						prcs[value - 1].state = "running";
						cout << "Process PID: " << prcs[value - 1].PID << " Process State: " << prcs[value - 1].state << endl;
					}
					cout << endl;
				}
				else if (value == 11) {
					displayProcesses();
				}
				else if (value == 12) {
					manual();
				}
				else if (value == 0) {
					exec(value);
				}
				else { //For negative
					cout << "MEMORY BEING ALLOCATED FOR THE PROCESS . . ." << endl;
					exec(jobList.front() * -1);
					jobList.pop();
					exec(value);

					if (value <= -1)
						cout << "CURRENTLY NO PROCESS RUNNING . . ." << endl;
					else {
						cout << "CURRENTLY " << jobList.size() << "(MAX) PROCESS RUNNING . . ." << endl;
						prcs[value - 1].state = "running";
						cout << "Process PID: " << prcs[value - 1].PID << " Process State: " << prcs[value - 1].state << endl;
					}
					cout << endl;
				}
			}
			else {
				if (value > 0 && value != 11 && value != 12) {
					cout << "MEMORY BEING ALLOCATED FOR THE PROCESS . . ." << endl;
					exec(jobList.front() * -1);
					jobList.pop();
					jobList.push(value);
					exec(jobList.front());

					if (value <= -1)
						cout << "CURRENTLY NO PROCESS RUNNING . . ." << endl;
					else {
						cout << "CURRENTLY " << jobList.size() << "(MAX) PROCESS RUNNING . . ." << endl;
						prcs[value - 1].state = "running";
						cout << "Process PID: " << prcs[value - 1].PID << " Process State: " << prcs[value - 1].state << endl;
					}
					cout << endl;

				}
				else if (value == 11) {
					displayProcesses();
				}
				else if (value == 12) {
					manual();
				}
				else if (value == 0) {
					exec(value);
				}
				else { //For negative
					cout << "MEMORY BEING ALLOCATED FOR THE PROCESS . . ." << endl;
					exec(jobList.front() * -1);
					jobList.pop();
					exec(value);

					if (value <= -1)
						cout << "CURRENTLY NO PROCESS RUNNING . . ." << endl;
					else {
						cout << "CURRENTLY " << jobList.size() << "(MAX) PROCESS RUNNING . . ." << endl;
						prcs[value - 1].state = "running";
						cout << "Process PID: " << prcs[value - 1].PID << " Process State: " << prcs[value - 1].state << endl;
					}
					cout << endl;
				}
			}
		}
	}
	catch (int) {
		cout << "You have entered an erroneous input. Closing . . ." << endl;
	}
}

void exec(int x) {

	if (x == 1)
		processOne();
	if (x == -1)
		killOne();
	if (x == 2)
		processTwo();
	if (x == -2)
		killTwo();
	if (x == 3)
		processThree();
	if (x == -3)
		killThree();
	if (x == 4)
		processFour();
	if (x == -4)
		killFour();
	if (x == 5)
		processFive();
	if (x == -5)
		killFive();
	if (x == 6)
		processSix();
	if (x == -6)
		killSix();
	if (x == 7)
		processSeven();
	if (x == -7)
		killSeven();
	if (x == 8)
		processEight();
	if (x == -8)
		killEight();
	if (x == 9)
		processNine();
	if (x == -9)
		killNine();
	if (x == 10)
		processTen();
	if (x == -10)
		killTen();
	if (x == 0) {
		killAll();
		system("PAUSE");
		exit(1);
	}
}
