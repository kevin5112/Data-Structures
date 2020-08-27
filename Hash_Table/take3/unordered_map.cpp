#include <iostream>
#include <vector>
using namespace std;

class node
{
public:
	node(int k, int v, node* n=NULL, node* p=NULL) : key(k), value(v), next(n), prev(p) {}

	int getKey() { return key; }
	void setKey(int k) { key = k; }
	int getValue() { return value; }
	void setValue(int v) { value = v; }
	node* getNext() { return next; }
	void setNext(node* n) { next = n; }
	node* getPrev() { return prev; }
	void setPrev(node* p) { prev = p; }
	

private:
	int key;
	int value;
	node* next;
	node* prev;
};

class list {
public:
	list() { head = NULL; tail = NULL; listSize = 0; }
	int size() { return listSize; }
	bool empty() { return size() == 0; }
	void push_back(int k, int v) {
		node* newNode = new node(k, v);
		node* temp = tail;
		if(empty()) {
			head = newNode;
			tail = newNode;
			++listSize;
			return;
		}
		tail->setNext(newNode);
		tail = tail->getNext();
		tail->setPrev(temp);
		++listSize;
	}

	void pop_back() {
		node* temp = tail;

		if(empty()) {
			cout << "list is empty\n";
			return;
		}		
		else if(size() == 1)
		{
			head = tail = nullptr;
			delete temp;
			--listSize;
			return;
		}
		else
		{
			tail = tail->getPrev();
			tail->setNext(nullptr);
			delete temp;
			--listSize;
			return;
		}
	}

	int front() { 
		if(size() > 0)
			return head->getValue();
		return -998;
	}

	int back() {
		if(size() > 0)
			return tail->getValue();
		return -999;
	}

	bool deleteNode(int k) {
		if(empty())
			return true;
		else if(size() == 1) {
			pop_back();
			return true;
		}
		else {
			node* temp = findNode(k);
			if(temp == nullptr)
				return false;
			// TODO: finish delete function
			node* prevNode = temp->getPrev();
			node* nextNode = temp->getNext();

			prevNode->setNext(nextNode);
			nextNode->setPrev(prevNode);
			delete temp;
			--listSize;
			return true;
		}
	}

	void print()
	{
		cout << "Printing list: ";
		for(node* it = head; it != NULL; it=it->getNext())
		{
			cout << it->getValue() << " -> ";
		}
		cout << "null\n";
	}

	void printReverseRecursively()
	{
		cout << "Printing list in reverse recursively: ";
		printReverseRecursively(head);
		cout << " null\n";
	}

	void printReverse()
	{
		cout << "Printing reverse: ";
		for(node* it = tail; it != NULL; it = it->getPrev())
		{
			cout << it->getValue() << " -> ";
		}
		cout << " null\n";
	}

	void printTail()
	{
		cout << tail->getValue() << endl;
	}

private:
	node* head;
	node* tail;
	int listSize;

	void printReverseRecursively(node* lead)
	{
		if(lead == NULL)
		{
			return;
		}

		printReverseRecursively(lead->getNext());
		cout << lead->getValue() << " -> ";
	}

// =====================================================================
// findNode(int k)
//
// Description: finds node for key = k and returns node position @ k
// Input: int k (key)
// Output: node* (pointer to node with containing k)
// =====================================================================
	node* findNode(int k) {
		if(empty())
			return nullptr;
		for(node* it = head; it != nullptr; it = it->getNext())
		{
			if(it->getKey() == k)
				return it;
		}
		return nullptr;
	}
};



class unordered_map
{
public:
	unordered_map() { mapSize = 0; loadFactor = 0; }
	int size() { return mapSize; }
	bool empty() { return size() == 0; }
	int max_size() { return myMap.max_size(); }
	int bucket_count() { return myMap.size(); }
	int hash_function(int key) { 
		
	}


private:
	vector<node*> myMap;
	int mapSize;
	double loadFactor;
};



int main()
{
	list myList;

	for(int i = 0; i < 10; ++i)
	{
		myList.push_back(i, i);
	}
	cout << "size: " << myList.size() << endl;
	myList.print();
	myList.printReverseRecursively();
	myList.printReverse();
	
	cout << "------------------------------------\n";

	for(int i = 0; i < 5; ++i)
	{
		myList.pop_back();
	}
	cout << "size: " << myList.size() << endl;
	myList.print();

	myList.deleteNode(3);
	myList.print();


	return 0;
}











