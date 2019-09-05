//LEO GENOTA
//COSC 214 - DR. STONE
//PROJECT 3 - BINARY TO DECIMAL CONVERSION
//THRU USE OF ARRAY IMPLEMENTAION OF STACKS
//AND RECURSION
#include<iostream>
#include<cmath>
using namespace std;

#include"arrayStackType.h"

void display(stackType stack);
//void flipBinary(stackType stack, stackType& stack2);
int convert(stackType stack, int counter);

int main() {
	stackType stack, stack2;
	int num, counter = -1;

	try {
		cout << "Enter the binary digits from right to left, one at a time: " << endl;
		cin >> num;
		if (num != 1 && num !=0 && num != -999)
			throw num;
		while (num != -999) {
			if (num != -999) {
				stack.push(num);
				counter++;
			}
			else break;

			cin >> num;
			if (num != 1 && num != 0 && num != -999)
				throw num;
		}
	}
	catch (int) {
		cout << "Invalid Input" << endl;
		system("PAUSE");
		exit(EXIT_FAILURE);
	}
	
	display(stack);
	//flipBinary(stack, stack2);
	cout << "Decimal of Binary Entered: " << convert(stack, counter) << endl;
	system("PAUSE");
	return 0;
}
void display(stackType stack) {
	cout << "The Binary Input: ";
	while (!stack.isEmptyStack()) {
		cout << stack.top();
		stack.pop();
	}
	cout << endl;
}
/*void flipBinary(stackType stack, stackType& stack2) {
	int num;

	while (!stack.isEmptyStack()) {
		num = stack.top();
		stack2.push(num);
		stack.pop();
	}
}*/
int convert(stackType stack, int counter) {
	if (counter == 0) {
		if (stack.top() == 1)
			return 1;
	}
	else {
		if (stack.top() == 1) {
			stack.pop();
			return pow(2, counter) + convert(stack, counter - 1);
		}
		stack.pop();
		convert(stack, counter - 1);
	}
}
 