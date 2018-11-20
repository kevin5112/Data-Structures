#ifndef LIST_H
#define LIST_H
#include <iostream>

class node
{
public:
	node(node* p, node* n, int d) : prev(p), next(n), data(d) {}
	node* Get_Prev() { return prev; }
	void Set_Prev(node* p) { prev = p; }
	node* Get_Next() { return next; }
	void Set_Next(node* n) { next = n; }
	int Get_Data() { return data; }
	void Set_Data(int d) { data = d; }

private:
	node* prev;
	node* next;
	int data;
};

class list
{
public:
	list() { head = nullptr; tail = nullptr; listSize = 0; }
	int size() { return listSize; }
	bool empty() { return size() == 0; }
	int front()
	{
		if(empty())
			return -1;
		return head->Get_Data();
	}

	int back()
	{
		if(empty() || size() == 1)
			return front();
		return tail->Get_Data();
	}

	void push_front(int d)
	{
		node* newNode = new node(nullptr, nullptr, d);
		if(empty())
		{
			head = newNode;
			tail = newNode;
			++listSize;
			return;
		}
		newNode->Set_Next(head);
		head->Set_Prev(newNode);
		head = newNode;
		++listSize;
		return;
	}

	void push_back(int d)
	{
		node* newNode = new node(nullptr, nullptr, d);
		if(empty())
		{
			push_front(d);
			return;
		}
		newNode->Set_Prev(tail);
		tail->Set_Next(newNode);
		tail = newNode;
		++listSize;
		return;
	}

	void display()
	{
		node* tracker = head;
		if(empty())
		{
			std::cout << "Empty\n";
			return;
		}
		for(; tracker != nullptr; tracker=tracker->Get_Next())
		{
			std::cout << tracker->Get_Data() << ' ';
			//tracker = tracker->Get_Next();
		}
		std::cout << std::endl;
		return;
	}

	void pop_front()
	{
		node* temp = head;
		if(empty())
			return;
		if(size() == 1)
		{
			head = tail = nullptr;
			delete temp; 
			--listSize;
			return;
		}
		head = head->Get_Next();
		head->Set_Prev(nullptr);
		delete temp;
		--listSize;
		return;
	}

	void pop_back()
	{
		node* temp = tail;
		if(empty() || size() == 1)
			pop_front();
		tail = tail->Get_Prev();
		tail->Set_Next(nullptr);
		delete temp;
		--listSize;
		return;
	}

	void clear()
	{
		std::cout << "Clearing list\n";
		while(!empty())
			pop_front();
		return;
	}

	// inserts at a 0 based index
	void insert(int d, int index)
	{
		node* newNode = new node(nullptr, nullptr, d);
		if(index > size() || index < 0)
		{
			std::cout << "Unable to insert\n";
			return;
		}
		if(index == size())
		{
			push_back(d);
			return;
		}
		if(index == 0)
		{
			push_front(d);
			return;
		}
		node* tracker = head;
		for(int i = 0; i < index; ++i)
		{
			tracker = tracker->Get_Next();
		}
		node* trailer = tracker->Get_Prev();
		trailer->Set_Next(newNode); // can do this because we already checked for if index is 0
		newNode->Set_Prev(trailer);
		newNode->Set_Next(tracker);
		tracker->Set_Prev(newNode);
		++listSize;
		return;
	}

	void remove(int index)
	{
		node* tracker = head;
		node* trailer = nullptr;
		if(index >= size() || index < 0)
		{
			std::cout << "Unable to remove\n";
			return;
		}
		if(index == 0)
		{
			pop_front();
			return;
		}
		if(index == size() - 1)
		{
			pop_back();
			return;
		}
		for(int i = 0; i != index; ++i)
		{
			trailer = tracker;
			tracker = tracker->Get_Next();
		}
		node* temp = tracker;
		tracker = tracker->Get_Next();
		trailer->Set_Next(tracker);
		tracker->Set_Prev(trailer);
		delete temp;
		--listSize;
		return;
	}

	void reverse()
	{
		node* trailer = nullptr;
		reverse_helper(head, nullptr);
	}

	~list()
	{
		std::cout << "Calling Destructor\n";
		clear();
	}


private:
	node* head;
	node* tail;
	int listSize;

	void reverse_helper(node* front, node* back)
	{
		if(front == nullptr)
		{
			head = back;
			back->Set_Prev(front);
			return;
		}
		//std::cout << "front: " << front->Get_Data() << std::endl;
		//std::cout << "back: " << back->Get_Data() << std::endl;
		reverse_helper(front->Get_Next(), front);
		front->Set_Next(back);
		if(back == nullptr)
		{
			tail = front;
			return;
		}
		back->Set_Prev(front);
	}
};



#endif