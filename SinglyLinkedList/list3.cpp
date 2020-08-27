#include <iostream>
using namespace std;

class node {
public:
	// constructors
	node(int v) : val(v), next(NULL) {}

	// returns the value of the node
	int getVal() { return val; }
	// sets the node value
	void setVal(int v) { val = v; }
	// returns the pointer to the next node
	node* getNext() { return next; }
	// sets the next pointer
	void setNext(node* n) { next = n; }
private:
	int val;
	node* next;
};

class list {
public:
	// constructors
	list() : head(NULL), listSize(0) {}

	// Capacity
	// returns true or false depending on if list is empty
	bool empty() { return size() == 0; }
	// returns the size of the list
	int size() { return listSize; }

	// Modifiers
	// pop_front pops off the front node.  If list is already empty then returns
	void pop_front() {
		if(empty())
			return;
		node* temp = head;
		head = head->getNext();
		delete temp;
		listSize--;
		return;
	}

	// clear - clears the whole list back to 0
	void clear() {
		while(!empty())
			pop_front();
	}

	// push_front - pushes nodes to the front of the list
	void push_front(int val) {
		node* temp = new node(val);
		// if list is empty, assign head to node and return
		if(empty()) {
			head = temp;
			listSize++; 
			return;
		}
		// assuming list is not empty
		temp->setNext(head);
		head = temp;
		listSize++;
		return;
	}

	// print list - prints out all the contents of the list
	void print() {
		for(node* it = head; it != NULL; it=it->getNext()) {
			cout << it->getVal() << (it->getNext() == NULL ? "\n" : " -> ");
		}
	}

private:
	node* head;
	int listSize;
};

int main() {
	list* myList = new list();
	cout << "empty? " << (myList->empty() ? "true" : "false") << endl;
	cout << "size: " << myList->size() << endl;
	for(int i = 0; i < 10; ++i) {
		myList->push_front(i);
	}
	myList->print();
	for(int i = 0; i < 3; ++i) {
		myList->pop_front();
	}
	myList->print();
	myList->clear();
	myList->print();
	cout << "empty? " << (myList->empty() ? "yes\n" : "no\n");
	return 0;
}