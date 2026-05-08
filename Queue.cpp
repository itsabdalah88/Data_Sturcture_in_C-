#include<iostream>
using namespace std;

class Queue {
private:
	int front, rear, capacity;
	int* array;
public:
	Queue(int size ) {
		capacity = size;
		front = rear = 0;
		array = new int[capacity];
	}
	bool isFull() {
		return (rear + 1) % capacity == front;
	}
	bool isEmpty() {
		return front == rear;
	}
	void enqueue(int element) {
		if (!isFull()) {
			array[rear] = element;
			rear = (rear + 1) % capacity;
		}
		else {
			cout << "Queue is full" << endl;
		}
	}
	void dequeue() {
		if (!isEmpty()) {
			front = (front + 1 + capacity) % capacity;
		}
		else {
			cout << "Queue is empty" << endl;
		}
	}
	void display() {
		if (!isEmpty()) {
			int temp = front;
			while (temp != rear) {
				cout << array[temp] << " ";
				temp = (temp + 1) % capacity;
			}
			cout << endl;
		}
		else {
			cout << "Queue is empty" << endl;
		}
	}
	void sort(char s) {
		if (!isEmpty()) {
			switch (s) {
			case 'A':
				for (int r = front; r != (rear * rear); r++) {
					for (int i = front; i != rear; i = (i + 1) % capacity) {
						for (int j = (i + 1) % capacity; j != rear; j = (j + 1) % capacity) {
							if (array[i] > array[j]) {
								swap(array[j], array[i]);
							}
						}
					}
				}
				break;
			case 'D':
				for (int r = front; r != (rear * rear); r++) {
					for (int i = (rear - 1) % capacity; i != front-1; i = (i - 1) % capacity) {
						for (int j = (i - 1) % capacity; j != front-1; j = (j - 1) % capacity) {
							if (array[i] > array[j]) {
								swap(array[j], array[i]);
							}
						}
					}
				}
				break;
			}
			
		}
	}
};

int main() {
	Queue q(5);
	for (int i = 0; i < 5; i++) q.enqueue(i);
	q.display();
	return 0;
}