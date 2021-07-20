/*

This is a Circular Doubly Linked List program which add a Node at the end of the Linked Lists.
Since, it is a Ciruclar Doubly Linked List, both the forward and backward traversal is also possible.

*/

#include <iostream>

using namespace std;

/*

Node definition:
	1. Pointer to previous node.
	2. Integer Data
	3. Pointer to next node.

*/

class dcll_node {
public:
	dcll_node* prev;
	int data;
	dcll_node* next;
};

void createDCLL(dcll_node* &head) {

	dcll_node* temp = head;

	int choice;

	do {

		int data;

		cout << "Enter Data : ";
		cin >> data;

		dcll_node* newNode = new dcll_node();
		newNode->data = data;
		newNode->prev = NULL;
		newNode->next = NULL;

		if(head == NULL) {
			head = newNode;
			temp = head;
			head->next = head;
			head->prev = head;
		} else {
			newNode->next = head;
			head->prev = newNode;
			newNode->prev = temp;
			temp->next = newNode;
			head = newNode;
		}

		cout << "Do you want to continue? (1/0) : ";
		cin >> choice;

	} while(choice == 1);
}

void display(dcll_node* head) {

	dcll_node* temp = head;

	cout << "The elements are : ";
	do {
		cout << temp->data << " ";
		temp = temp->next;
	} while(temp != head);

	cout << endl;
}

int main() {

	dcll_node* head = NULL;

	createDCLL(head);
	display(head);

	return 0;
}