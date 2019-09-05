#include<iostream>
using namespace std;
#include"binaryTree.h"

int main() {
	binaryTreeType tree;
	int input, delVal, count = 0;
	int selection, searchItem;

		cout << "=================================" << endl;
		cout << "Binary Tree Operations Menu" << endl;
		cout << "=================================" << endl;
		cout << "1.Add a new item" << endl;
		cout << "2.Delete an item" << endl;
		cout << "3.Show minimum node" << endl;
		cout << "4.List current height of tree" << endl;
		cout << "5.Find a node and report its depth" << endl;
		cout << "6.Print all nodes" << endl;
		cout << "7.Quit" << endl;

		try {
			do {
				cout << endl;
				cout << "Enter your selection" << endl;
				cin >> selection;
				if (selection != 1 && selection != 2 && selection != 3 &&
					selection != 4 && selection != 5 && selection != 6 && selection != 7)
					throw selection;
				cout << endl;

				if (selection == 1) {
					cout << "Enter items (-999 to stop): " << endl;
					cin >> input;
					while (input != -999) {
						tree.insert(input);
						cin >> input;
					}
				}
				else if (selection == 2) {
					cout << "Enter the node to be deleted: " << endl;
					cin >> delVal;
					tree.delNode(delVal);
				}
				else if (selection == 3) {
					tree.minimum();
					cout << endl;
				}
				else if (selection == 4) {
					cout << "The current height of the tree is: " << tree.ht() << endl;
				}
				else if (selection == 5) {
					cout << "Enter the node to be searched: " << endl;
					cin >> searchItem;
					tree.searchRep(searchItem, count);
				}
				else if (selection == 6) {
					tree.inorderTrav();
					cout << endl;
				}
				else if (selection == 7) {
					cout << "Exiting Program . . ." << endl;
					system("PAUSE");
					exit(EXIT_SUCCESS);
				}
				cout << endl;
			} while (selection != 7);

			//system("PAUSE");
			return 0;
		}
		catch (int) {
			cout << "The number you entered is not a valid number. Please try again and choose from the desired values." << endl;
			system("PAUSE");
			return(0);
		}
}
