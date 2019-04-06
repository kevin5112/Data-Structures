#include <iostream>
using namespace std;

class node
{
public:
	node(int d, node* n) : data(d), next(n) {}
	int getdata() { return data; }
	void setdata(int data) { this->data = data; }
	node* getnext() { return next; }
	void setnext(node* next) { this->next = next; }

private:
	int data;
	node* next;
};


class list
{
public:
	list() { head = nullptr; listSize = 0; }

	int size() { return listSize; }
	bool empty() { return size() == 0; }
	void push_front(int data)
	{
		node* newNode = new node(data, nullptr);
		newNode->setnext(head);
		head = newNode;
		++listSize;
	}

	void pop_front()
	{
		if(empty())
		{
			cout << "Cannot pop from empty list\n";
			return;
		}
		node* temp = head;
		head = head->getnext();
		delete temp;
		--listSize;
	}

	void push_back(int data)
	{
		node* newNode = new node(data, nullptr);
		if(empty())
		{
			push_front(data);
			return;
		}

		node* it = head;
		while(it->getnext() != nullptr)
		{
			it = it->getnext();
		}

		it->setnext(newNode);
		++listSize;
	}

	void pop_back()
	{
		if(size() <= 1)
		{
			pop_front();
			return;
		}

		node* it = head;
		node* trailer = nullptr;

		while(it->getnext() != nullptr)
		{
			trailer = it;
			it = it->getnext();
		}
		trailer->setnext(nullptr);
		delete it;
		--listSize;
	}

	void print()
	{
		node* it = head;
		while(it != nullptr)
		{
			cout << it->getdata() << " -> ";
			it = it->getnext();
		}
		cout << "null\n";
	}

	void reverseList()
	{
		reverseListHelper(head, nullptr);
	}

	void clear()
	{
		while(!empty())
		{
			pop_front();
		}
	}

	~list()
	{
		clear();
	}


	

private:
	node* head;
	int listSize;

	void reverseListHelper(node* lead, node* tail)
	{
		if(lead == nullptr)
		{
			head = tail;
			return;
		}

		reverseListHelper(lead->getnext(), lead);

		lead->setnext(tail);

	}

};



int main()
{
	list myList;

	cout << "Size: " << myList.size() << endl;
	cout << "Empty: " << myList.empty() << endl;
	cout << "------------------------------\n";

	for(int i = 1; i < 11; ++i)
	{
		myList.push_front(i);
	}

	myList.print();
	cout << "Size: " << myList.size() << endl;
	cout << "Empty: " << myList.empty() << endl;

	cout << "Popping front\n";
	myList.pop_front();
	cout << "Popping front\n";
	myList.pop_front();
	cout << "Popping front\n";
	myList.pop_front();

	cout << "Popping back\n";
	myList.pop_back();
	cout << "Popping back\n";
	myList.pop_back();
	cout << "Popping back\n";
	myList.pop_back();

	cout << "------------------------------\n";
	myList.print();
	cout << "Size: " << myList.size() << endl;
	cout << "Empty: " << myList.empty() << endl;
	cout << "------------------------------\n";

	for(int i = 0; i < 6; ++i)
	{
		myList.push_back(i);
	}

	myList.print();
	cout << "Size: " << myList.size() << endl;
	cout << "Empty: " << myList.empty() << endl;
	cout << "------------------------------\n";


	cout << "Popping front\n";
	myList.pop_front();
	cout << "Popping front\n";
	myList.pop_front();
	cout << "Popping front\n";
	myList.pop_front();
	cout << "Popping front\n";
	myList.pop_front();
	cout << "------------------------------\n";

	myList.print();
	cout << "Size: " << myList.size() << endl;
	cout << "Empty: " << myList.empty() << endl;
	myList.clear();

	cout << "------------------------------\n";
	for(int i = 1; i < 11; ++i)
	{
		myList.push_front(i);
	}
	myList.print();
	cout << "Calling reverseList...\n";
	myList.reverseList();
	myList.print();


	return 0;
}




