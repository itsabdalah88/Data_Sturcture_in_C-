/*the main differences between the stack and the queue : -
1 - the stack work(LIFO) so the last element added is the first element removed.
2 - the queue work(FIFO) so so the first element added is the first element removed.
3 - stack have only one pointer(top) while the queue have two pointers(front and rear).*/

#include<iostream>
#include <string>
using namespace std;

const int maxSize = 50;
class Stack {
private:
	char arr[maxSize];
	int top;
public:
	Stack() {
		top = 0;
	}
	bool isEmpty() {
		return top == 0;
	}
	bool isFull() {
		return top == maxSize;
	}
	void push(char value) {
		if (!isFull()) {
			arr[top] = value;
			top++;
		}
		else {
			cout << "Stack Overflow" << endl;
		}
	}
	void interChars(string element) {
		for (int i = 0; i < element.length(); i++) {
			push(char(tolower(element[i])));
		}
	}
	void display() {
		for (int i = 0; i < top; i++) {
			cout << '{' << arr[i] << "}";
			if (i < top - 1) cout << " , ";
		}
		cout << '.' << endl;
	}
	bool ispalindrome() {
		int start = 0;
		int end = top -1;
		while (start < end) {
			if (arr[start] != arr[end]) {
				return false;
			}
			start++;
			end--;
		}
		return true;
	}
};

class Queue {
private:
	char arr[maxSize];
	int front;
	int rear;
public:
	Queue() { front = rear = 0; }
	bool isEmpty() { return front == rear; }
	bool isFull() { return rear == maxSize-1; }
	void enqueue(char value) {
		if (!isFull()) {
			arr[rear] = value;
			rear = (rear + 1)% maxSize;
		}
		else {
			cout << "Queue Overflow" << endl;
		}
	}
	void dequeue() {
		if (!isEmpty()) {
			front = (front + 1)% maxSize;
		}
		else {
			cout << "Queue Underflow" << endl;
		}
	}
	void display() {
		for (int i = front; i < rear; i = (i +1)%maxSize) {
			cout << '{' << arr[i] << "}";
			if (i < rear - 1) cout << " , ";
		}
		cout << '.' << endl;
	}
	void interChars(string element) {
		for (int i = front; i < element.length(); i = (i+1)%maxSize) {
			enqueue(char(tolower(element[i])));
		}
	}
	bool ispalindrome() {
		int start = front;
		int end = rear - 1;
		while (start < end) {
			if (arr[start] != arr[end]) {
				return false;
			}
			start = (start+1)%maxSize;
			end = (end-1)%maxSize;
		}
		return true;
	}
};

int main() {
	Stack mystack;
	Queue myqueue;
	string input;
	bool stackType = false;
	cout << "Enter something: ";
	getline(cin, input);
	cout << "Choose data structure (0 for Stack, 1 for Queue): ";
	cin >> stackType;
	if (stackType == 0) {
		mystack.interChars(input);
		mystack.display();
		if (mystack.ispalindrome()) {
			cout << "This input is a palindrome." << endl;
		}
		else {
			cout << "This input is not a palindrome." << endl;
		}
	}
	else {
		myqueue.interChars(input);
		myqueue.display();
		if (myqueue.ispalindrome()) {
			cout << "This input is a palindrome." << endl;
		}
		else {
			cout << "This input is not a palindrome." << endl;
		}
	}
	return 0;
}