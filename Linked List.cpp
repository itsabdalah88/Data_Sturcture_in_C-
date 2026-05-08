#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};
Node* start = NULL;
void ReverseOrder()
{
	Node* current = start;
	if (current != NULL)
	{
		ReverseOrder(current->next);
		cout << current->data << " ";
	}
}
void Insert(int item)
{
	Node* nweNode = new Node;
	nweNode->data = item;
	if (start == NULL)
	{
		nweNode->next = NULL;
		start = nweNode;
	}
	else
	{
		Node* temp = start;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = nweNode;
		nweNode->next = NULL;
	}
}
//struct Node
//{
//	int data;
//	Node* link;
//};
//Node* stackTop = NULL;
//bool isEmpty() { return(stackTop == NULL); }
//
//int count(){
//	Node* ptr = stackTop;
//	int i = 0;
//	while (ptr != NULL) {
//		i++;
//		ptr = ptr->link;
//	}
//	return i;
//}
//
//void push(int element) {
//	Node* ptr = new Node();
//	ptr->data = element;
//	ptr->link = stackTop;
//	stackTop = ptr;
//}
//
//void pop() {
//	if (!isEmpty()) {
//		Node* ptr = stackTop;
//		stackTop = stackTop->link;
//		delete ptr;
//	}
//	else {
//		cout << "erorr" << endl;
//	}
//}
//
//void display() {
//	Node* ptr = stackTop;
//	while (ptr != NULL) {
//		cout << ptr->data << " ";
//		ptr = ptr->link;
//	}
//	cout << endl;
//}
//
//void top() {
//	cout << stackTop->data << endl;
//}
//
//void search(int a) {
//	bool isExiste = 0;
//	int counter = 1;
//	Node* ptr = stackTop;
//	while (ptr != NULL) {
//		if (a != ptr->data) {
//			counter++;
//			ptr = ptr->link;
//		}
//		else {
//			isExiste = 1;
//			break;
//		}
//	}
//	if (isExiste) {
//		cout << "it is existe at Node: " << (count()+1) - counter << endl;
//	}
//	else {
//		cout << "its not existe" << endl;
//	}
//}
//void addEnd(int element) {
//	Node* ptr = new Node();
//	ptr->data = element;
//	ptr->link = NULL;
//	if (!isEmpty()) {
//		Node* current = stackTop;
//		while (current->link != NULL) {
//			current = current->link;
//		}
//		current->link = ptr;
//	}
//}
//void delEnd() {
//	Node* temp, * current = stackTop;
//	while (current->link->link != NULL) current = current->link;
//	temp = current->link;
//	current->link = NULL;
//	delete temp;
//}
//Node* find(int element) {
//	Node* ptr = stackTop;
//	while (ptr != NULL and ptr->data != element) ptr = ptr->link;
//	return ptr;
//}
//Node* findpre(int element) {
//	Node* ptr = stackTop;
//	while (ptr != NULL and ptr->link->data != element) ptr = ptr->link;
//	return ptr;
//}
//Node* findAfter(int element) {
//	Node *ptr = stackTop;
//	while (ptr != NULL and ptr->data != element) ptr = ptr->link;
//	return ptr->link;
//}
//void insert(int item, int after) {
//	Node* current = find(after);
//	Node* ptr = new Node();
//	ptr->data = item;
//	if (!isEmpty()) {
//		ptr->link = current->link;
//		current->link = ptr;
//	}
//	else ptr->link = NULL;
//}
//void deletee(int element) {
//	Node* current = findpre(element);
//	Node* temp = current->link;
//	current->link = temp->link;
//	delete temp;
//}

int main() {
	/*int task, input,find;
	bool flag = true;
	
	while (flag) {
		cout << "1.push    2.pop" << endl << "3.display    4.search" << endl << "5.top    6.count" << endl;
		cin >> task;
		switch (task) {
		case 1:
			cout << "inset the value: ";
			cin >> input;
			push(input);
			break;
		case 2:
			pop();
			break;
		case 3:
			display(); break;
		case 4:
			cout << "inset the value: ";
			cin >> find;
			search(find);
			break;
		case 5: top(); break;
		case 6: cout << count() << endl; break;
		}
		cout << "do you want to continue?";
		cin >> flag;
			 
	}*/
	for (int i = 1; i <= 5; i++) Insert(i);
	ReverseOrder();
	return 0;
}