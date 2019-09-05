// Leo Genota
// COSC 214 
//Dr. Stone
//PROJECT 1
#include<iostream>
using namespace std;

struct node {
	int num;
	node * link;
};

void create(node*& first1, node*& last1, node*& first2, node*& last2);
void delLL(node*& first1, node*& last1, node*& first2, node*& last2);
void display(node* first1, node* last1, node* first2, node* last2);
void Union(node* first1, node* last1, node* first2, node* last2);
void Intersect(node* first1, node* last1, node* first2, node* last2);
void Difference(node* first1, node* last1, node* first2, node* last2);

int main() {
	node * first1 = NULL, *last1 = NULL, *first2 = NULL, *last2 = NULL;
	char input;
	try {

		cout << "Welcome User! Select one of the following choices"
			<< " by entering the corresponding letter. " << endl;
		cout << "P - display both sets/linked list" << endl;
		cout << "U - display the union of sets/linked list" << endl;
		cout << "I - display the intersection of sets/linked list" << endl;
		cout << "D - display the difference of sets/linked list" << endl;
		cout << "C - change #'s in the 2 sets/linked list" << endl;
		cout << "L - delete the sets/linked lists" << endl;
		cout << "Q - quit the program" << endl;
		do {
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "Selection: ";
			cin >> input;
			if ((input != 'P') && (input != 'U') && (input != 'I')
				&& (input != 'D') && (input != 'C') && (input != 'Q') && (input != 'L'))
				throw input;
			else if (input == 'P') {
				if (first1 == NULL)
					cout << "Empty List . . ." << endl;
				else
					display(first1, last1, first2, last2);
			}
			else if (input == 'U') {
				if (first1 == NULL)
					cout << "Empty List . . ." << endl;
				else
					Union(first1, last1, first2, last2);
			}
			else if (input == 'I') {
				if (first1 == NULL)
					cout << "Empty List . . ." << endl;
				else
					Intersect(first1, last1, first2, last2);
			}
			else if (input == 'D') {
				if (first1 == NULL)
					cout << "Empty List . . ." << endl;
				else
					Difference(first1, last1, first2, last2);
			}
			else if (input == 'C') {
				create(first1, last1, first2, last2);
			}
			else if (input == 'L') {
				if (first1 == NULL)
					cout << "Empty List . . ." << endl;
				else
					delLL(first1, last1, first2, last2);
			}
			else if (input == 'Q')
				cout << "Program is exiting . . ." << endl;

		} while (input != 'Q');
	}
	catch (char) {
		cout << "The character is invalid. Program closing . . ." << endl;
		system("PAUSE");
		exit(EXIT_FAILURE);
	}
	system("PAUSE");
	return 0;
}
void create(node*& first1, node*& last1, node*& first2, node*& last2) {
	int number;
	node * newNode = NULL;

	try {
		cout << "Enter # for set/linked list #1 (-999 to end): ";
		cin >> number;
		if (!cin)
			throw number;

		while (number != -999) {
			newNode = new node;
			newNode->num = number;
			newNode->link = NULL;

			if (first1 == NULL) {
				first1 = newNode;
				last1 = newNode;
			}
			else {
				last1->link = newNode;
				last1 = newNode;
			}
			cout << "Enter # for set/linked list #1 (-999 to end): ";
			cin >> number;
			if (!cin)
				throw number;
		}

		cout << "Enter # for set/linked list #2 (-999 to end): ";
		cin >> number;

		while (number != -999) {
			newNode = new node;
			newNode->num = number;
			newNode->link = NULL;

			if (first2 == NULL) {
				first2 = newNode;
				last2 = newNode;
			}
			else {
				last2->link = newNode;
				last2 = newNode;
			}
			cout << "Enter # for set/linked list #2 (-999 to end): ";
			cin >> number;
			if (!cin)
				throw number;
		}
	}
	catch (int) {
		cout << "INVALID INPUT: Program is closing . . ." << endl;
		system("PAUSE");
		exit(EXIT_FAILURE);
	}
}
void delLL(node*& first1, node*& last1, node*& first2, node*& last2) {
	node * temp1 = NULL, *temp2 = NULL;
	while (first1 != NULL) {
		temp1 = first1;
		first1 = first1->link;
		delete temp1;
	}
	while (first2 != NULL) {
		temp2 = first2;
		first2 = first2->link;
		delete temp2;
	}
	cout << "Linked Lists have been deleted . . ." << endl;
}
void display(node* first1, node* last1, node* first2, node* last2) {
	node* current = NULL;
	current = first1;
	cout << "Set/Linked List 1: {";
	while (current != NULL) {
		if (current->link == NULL) {
			cout << current->num;
			current = current->link;
		}
		else {
			cout << current->num << ", ";
			current = current->link;
		}
	}
	cout << "}" << endl;
	current = first2;
	cout << "Set/Linked List 2: {";
	while (current != NULL) {
		if (current->link == NULL) {
			cout << current->num;
			current = current->link;
		}
		else {
			cout << current->num << ", ";
			current = current->link;
		}
	}
	cout << "}" << endl;
}
void Union(node* first1, node* last1, node* first2, node* last2) {
	node* current = NULL;
	cout << "Union of Sets 1 and 2: {";
	current = first1;
	while (current != NULL) {
		cout << current->num << ", ";
		current = current->link;
	}
	current = first2;
	while (current != NULL) {
		if (current->link == NULL) {
			cout << current->num;
			current = current->link;
		}
		else {
			cout << current->num << ", ";
			current = current->link;
		}
	}
	cout << "}" << endl;
}
void Intersect(node* first1, node* last1, node* first2, node* last2) {
	node * current1 = NULL, *current2;
	node* newNode = NULL, *curr = NULL, *first = NULL, *last = NULL;

	current1 = first1;
	current2 = first2;

	while (current1 != NULL) {
		while (current2 != NULL) {
			if (current1->num == current2->num) {
				newNode = new node;
				newNode->num = current1->num;
				newNode->link = NULL;
				if (first == NULL) {
					first = newNode;
					last = newNode;
				}
				else {
					last->link = newNode;
					last = newNode;
				}
				current2 = current2->link;
			}
			else
				current2 = current2->link;
		}
		current2 = first2;
		current1 = current1->link;
	}

	if (first == NULL) {
		cout << "Sets 1 and 2 have no intersection." << endl;
	}
	else {
		curr = first;
		cout << "Intersection of Sets 1 and 2: {";
		while (curr != NULL) {
			if (curr->link == NULL) {
				cout << curr->num;
				curr = curr->link;
			}
			else {
				cout << curr->num << ", ";
				curr = curr->link;
			}
		}
		cout << "}" << endl;
	}
}
void Difference(node* first1, node* last1, node* first2, node* last2) {
	node * current1, *current2, *newNode;
	node* head = NULL, *tail = NULL;

	current1 = first1;
	current2 = first2;

	while (current1 != NULL) {
		while (current2 != NULL) {
			if (current1->num == current2->num)
				break;
			else
				current2 = current2->link;
		}
		if (current2 == NULL) {
			newNode = new node;
			newNode->num = current1->num;
			newNode->link = NULL;
			if (head == NULL) {
				head = newNode;
				tail = newNode;
			}
			else {
				tail->link = newNode;
				tail = newNode;
			}
		}
		current2 = first2;
		current1 = current1->link;
	}

	if (head == NULL) {
		cout << "Sets 1 and 2 have no Difference." << endl;
	}
	else {
		node * curr;
		curr = head;
		cout << "Difference of Sets 1 and 2: {";
		while (curr != NULL) {
			if (curr->link == NULL) {
				cout << curr->num;
				curr = curr->link;
			}
			else {
				cout << curr->num << ", ";
				curr = curr->link;
			}
		}
		cout << "}" << endl;
	}
}
