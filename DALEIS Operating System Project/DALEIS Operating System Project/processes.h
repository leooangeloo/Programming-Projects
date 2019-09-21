#include <iostream>
#include <string>
#include <windows.h>
#include <process.h>
#include <Tlhelp32.h>
#include <winbase.h>
#using <System.dll>

using namespace System;
using namespace System::Diagnostics;
using namespace System::ComponentModel;
using namespace std;

struct PCB {
	int PID = 0;
	string state;
}prcs[10];

void initializeProcesses() {
	for (int i = 0; i < 10; i++) {
		prcs[i].PID = 41125919 + i;
		prcs[i].state = "ready";
	}
}

void manual() {
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~MANUAL~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << endl;
	cout << "+ This operating system can only run one process at a time." << endl;
	cout << endl;
	cout << "+ In order to run a process, you must enter in a selection" << endl;
	cout << "  from one of the given menu options." << endl;
	cout << endl;
	cout << "+ In order to stop a process, you could enter the negative" << endl;
	cout << "  of the given number (ex. enter 1 to run, -1 to stop)" << endl;
	cout << endl;
	cout << "+ If the user runs another process, the previous one will" << endl;
	cout << "  stop and the newly entered proces will run." << endl;
	cout << endl;
	cout << "+ If an erroneous input is given, an error message will appear" << endl;
	cout << "  and immediately terminate the system. " << endl;
	cout << endl;
	cout << "+ When '0' is entered, the system will shut down." << endl;
	cout << endl;
	cout << "+ Option 11 will display information about the 10 processes" << endl;
	cout << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << endl;
}

void displayProcesses() {
	for (int i = 0; i < 10; i++) {
		cout << i + 1 << ") Process PID: " << prcs[i].PID << " Process State: " << prcs[i].state << endl;
	}
	cout << endl;
}

void processOne() {
	Process::Start("chrome.exe");
}

void killOne() {
	system("taskkill /F /IM chrome.exe >nul 2>&1");
	prcs[0].state = "ready";
}

void processTwo() {
	Process::Start("winword.exe");
}

void killTwo() {
	system("taskkill /F /IM winword.exe >nul 2>&1");
	prcs[1].state = "ready";
}

void processThree()
{
	Process::Start("excel.exe");
}

void killThree() {
	system("taskkill /F /IM excel.exe >nul 2>&1");
	prcs[2].state = "ready";
}

void processFour() {
	Process::Start("wireshark.exe");
}

void killFour() {
	system("taskkill /F /IM wireshark.exe >nul 2>&1");
	prcs[3].state = "ready";
}

void processFive() {
	Process::Start("powerpnt.exe");
}

void killFive() {
	system("taskkill /F /IM powerpnt.exe >nul 2>&1");
	prcs[4].state = "ready";
}

void processSix() {
	Process::Start("notepad++.exe");
}

void killSix() {
	system("taskkill /F /IM notepad++.exe >nul 2>&1");
	prcs[5].state = "ready";
}

void processSeven() {
	Process::Start("notepad.exe");
}

void killSeven() {
	system("taskkill /F /IM notepad.exe >nul 2>&1");
	prcs[6].state = "ready";
}

void processEight() {
	Process::Start("AcroRd32.exe");
}

void killEight() {
	system("taskkill /F /IM AcroRd32.exe >nul 2>&1");
	prcs[7].state = "ready";
}

void processNine() {
	Process::Start("mspaint.exe");
}

void killNine() {
	system("taskkill /F /IM mspaint.exe >nul 2>&1");
	prcs[8].state = "ready";
}

void processTen() {
	Process::Start("wmplayer.exe");
}

void killTen() {
	system("taskkill /F /IM wmplayer.exe >nul 2>&1");
	prcs[9].state = "ready";
}

void killAll() {
	killOne();
	killTwo();
	killThree();
	killFour();
	killFive();
	killSix();
	killSeven();
	killEight();
	killNine();
	killTen();
}
