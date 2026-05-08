#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node* prev;
};
Node* first = NULL;
Node* last = NULL;
int counter = 0;
bool isEmpty() { return first == NULL; }
void insert1(int value) {
	Node* ptr = new Node;
	ptr->data = value;
	ptr->next = first;
	if (isEmpty()) {
		first = last = ptr;
		last->next = NULL;
	}
	else {
		first->prev = ptr;
		first = ptr;
	}
	first->prev = NULL;
	counter++;
}
void insert9(int value) {
	Node* ptr = new Node;
	ptr->data = value;
	ptr->prev = last;
	if (isEmpty()) {
		first = last = ptr;
		first->prev = NULL;
	}
	else {
		last->next = ptr;
		last = ptr;
	}
	last->next = NULL;
	counter++;
}
void insert5(int value, int pos) {
	if (pos < 0) return;
	else if (pos == 0) insert1(value);
	else if (pos == counter) insert9(value);
	else {
		Node* ptr = new Node;
		Node* temp = first;
		ptr->data = value;
		for (int i = 1; i < pos; i++) temp = temp->next;
		ptr->next = temp->next;
		ptr->prev = temp;
		temp->next->prev = ptr;
		temp->next = ptr;
		counter++;
	}
}
void display() {
	Node* temp = first;
	while (temp != NULL) {
		cout << temp->data << ' ';
		temp = temp->next;
	}
}
void delete1() {
	Node* temp = first;
	if (first == last) first = last = NULL;
	else {
		first = first->next;
		first->prev = NULL;
	}
	delete temp;
	counter--;
}
void delete9() {
	Node* temp = first;
	if (first == last) first = last = NULL;
	else {
		last = last->prev;
		last->next = NULL;
	}
	delete temp;
	counter--;
}
void delete5(int pos) {
	if (pos < 0 or pos >= counter) return;
	else if (pos == 0) delete1();
	else if (pos == counter-1) delete9();
	else {
		Node* temp = first;
		for (int i = 0; i < pos; i++) temp = temp->next;
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		delete temp;
		counter--;
	}
}

int main() {
	insert1(4);
	insert9(5);
	insert1(3);
	insert1(2);
	delete5(2);
	insert9(7);
	insert5(6, 4);
	insert1(1);
	delete1();
	insert5(4, 2);
	delete9();
	insert1(1);
	insert9(7);
	display();
	return 0;
}