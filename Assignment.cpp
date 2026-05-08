#include<iostream>
using namespace std;

struct Node {
	char data;
	Node* link;
};

Node* stackTop = NULL; 
Node* vowelPtr = NULL;

bool isEmpty() { return stackTop == NULL; }

void pig_latin_creat(string value) {
	for (int i = (value.length()-1); i >= 0; i--) {
		Node* ptr = new Node;
		ptr->data = value[i];
		ptr->link = stackTop;
		stackTop = ptr;
	}
};

void pig_latin_display() {
	Node* ptr = stackTop;
	while (ptr != NULL) {
		cout << ptr->data << ' ';
		ptr = ptr->link;
	}
	cout << endl;
}

bool vowel_detect() {
	char vowels[] = { 'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'};
	Node* ptr = stackTop;
	while (ptr != NULL) {
		for (int i = 0; i < 12; i++) {
			if (ptr->data == vowels[i]) {
				vowelPtr= ptr;
				return true;
			}
		}
		ptr = ptr->link;
	}
}

int vowel_postion() {
	int postion = 1;
	Node* ptr = stackTop;
	while(ptr!= vowelPtr) {
		postion++;
		ptr = ptr->link;
		}
	return postion;
}

void rotate() {
	Node* ptr = stackTop;
	if (vowel_detect()) {
		for (int i = 1; i < vowel_postion(); i++) {
			ptr = ptr->link;
		}
		while (ptr != NULL) {
			cout << ptr->data;
			ptr = ptr->link;
		}
		cout << "-";
		ptr = stackTop;
		while (ptr != vowelPtr) {
			cout << ptr->data;
			ptr = ptr->link;
		}
	}
	else {
		ptr = stackTop;
		while (ptr != NULL) {
			cout << ptr->data;
			ptr = ptr->link;
		}
		cout << "-";
	}
}



void pig_latin_form() {
	if (vowel_detect()) {
		if (vowel_postion() == 1) {
			rotate();
			cout << "way" << endl;
		}
		else {
			rotate();
			cout << "ay" << endl;
		}
	}
	else {
		rotate();
		cout << "way" << endl;
	}
}

int main() {
	string word;
	cout << "Enter a word: ";
	cin >> word;
	pig_latin_creat(word);
	pig_latin_display();
	pig_latin_form();
	return 0;
}