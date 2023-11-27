#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node() {}
	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};

class LinkedList {
public:
	Node* front;
	Node* rear;

	LinkedList() {
		front = NULL;
		rear = NULL;
	}

	void addBack(int data) {
		Node* newNode = new Node(data);
		if (front == NULL) {
			front = rear = newNode;
		}
		else {
			rear->next = newNode;
			rear = newNode;
		}
	}

	int removeFront() {
		Node* oldNode = front;
		int data = oldNode->data;

		front = front->next;
		delete oldNode;

		return data;

	}

	int rear_() {
		if (front == NULL)
			return -1;
		else
			return rear->data;
	}

	int front_() {
		if (front == NULL)
			return -1;
		else
			return front->data;
	}
};

class Queue {
public:
	int n = 0;
	Queue() {}

	LinkedList* Q = new LinkedList();

	void enqueue(int data) {
		Q->addBack(data);
		n++;
	}

	void dequeue() {
		if (isEmpty()) {
			cout << "-1\n";
		}
		else {
			Q->removeFront();
			n--;
		}
	}

	bool isEmpty() {
		return n == 0;
	}

	int front() {
		return Q->front_();
	}

	int rear() {
		return Q->rear_();
	}


	
};

int main() {
	int number;
	int number2;
	vector<int>v;

	cin >> number;
	cin >> number2;

	Queue q;

	for (int i = 0; i < number; i++) {
		q.enqueue(i + 1);
	}

	while (q.n!=1) {
		for (int i = 0; i < number2-1; i++) {
			q.enqueue(q.front());
			q.dequeue();
		}
		
			v.push_back(q.front());
			q.dequeue();
	
	}
	v.push_back(q.front());
	q.dequeue();

	cout << "<" << v[0];
	for (int i = 0; i < number-1; i++) {
		cout << ", " << v[i + 1];
	}
	cout << ">";




}