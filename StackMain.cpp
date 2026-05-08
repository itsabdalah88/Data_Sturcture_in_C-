#include<iostream>
#include <cmath>
using namespace std;

const int maxsize = 20;
class stack {
private:
	int arr[maxsize];
	int stackTop;
public:
	stack() { stackTop = 0; }
	bool isEmpty() { return(stackTop == 0); }
	bool isFull() { return(stackTop == maxsize); }
	void push(int a) {
		if (isFull()) cout << "Erorr" << endl;
		else {
			arr[stackTop] = a;
			stackTop++;
		}
	}
	void pop() {
		if (isEmpty()) cout << "Erorr" << endl;
		else stackTop--;
	}
	void display() {
		if (!isEmpty()) {
			for (int i = stackTop - 1; i != -1; i--) {
				cout << arr[i] << endl;
			}
		}
		else cout << "Erorr" << endl;
	}
	int top() {
		return arr[stackTop - 1];
	}
	void initialise() {
		stackTop = 0;
	}
	void sort(char s) {
		switch (s) {
		case 'D':
			for (int i = 1; i < stackTop; i++) {
				for (int j = 0; j < (stackTop + 1); j++) {
					if (arr[j] > arr[i]) {
						swap(arr[i], arr[j]);
					}
				}
			}
			break;
		case 'A':
			for (int i = 1; i < stackTop; i++) {
				for (int j = 0; j < (stackTop + 1); j++) {
					if (arr[j] < arr[i]) {
						swap(arr[i], arr[j]);
					}
				}
			}
			break;
		default:
			break;
		}
	}
	void insert(int pos, int value) {
		if (!isFull()) {
			for (int i = stackTop-1; i >= pos; i--) {
				arr[i + 1] = arr[i];
			}
			arr[pos] = value;
			stackTop++;
		}
		else cout << "Erorr" << endl;
	}
	void remove(int pos) {
		if (!isEmpty()) {
			for (int i = pos; i <= stackTop-1; i++) {
				arr[i] = arr[i + 1];
			}
			stackTop--;
		}
	}
	int retrieve(int pos) {
		if (!isEmpty()) {
			return arr[pos];
		}
	}
};
int main() {
	stack obj;
	for (int i = 1; i <= 10; i++)
	{
		obj.push(i);
	}
	cout << obj.retrieve(4) << endl;
	obj.display();
	return 0;
}