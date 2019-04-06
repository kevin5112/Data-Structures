#include <iostream>

class node
{
public:
	node(node* n, int d) : next(n), data(d) {}
	node* Get_Next() { return next; }
	void Set_Next(node* n) { next = n; }
	int Get_Data() { return data; }
	void Set_Data(int d) { data = d; }

private:
	node* next;
	int data;
};

class stack
{
public:
	stack() { head = nullptr; stackSize = 0; }
	int size() { return stackSize; }
	bool empty() { return size() == 0; }
	int top() 
	{ 
		if(empty())
		{
			return -1;
		}
		return head->Get_Data();
	}

	void push(int d)
	{
		node* newNode = new node(nullptr, d);

		if(empty())
		{
			head = newNode;
			++stackSize;
			return;
		}

		newNode->Set_Next(head);
		head = newNode;
		++stackSize;
		return;
	}

	void pop()
	{
		node* temp = head;

		if(empty())
		{
			return;
		}

		head = head->Get_Next();
		delete temp;
		--stackSize;
		return;
	}

	void displayStack()
	{
		if(empty())
		{
			return;
		}

		node* it = head;
		while(it != nullptr)
		{
			std::cout << it->Get_Data() << " -> ";
			it = it->Get_Next();
		}
		std::cout << "null" << std::endl;
	}

private:
	node* head;
	int stackSize;
};


int main()
{
	stack myStack;
	for(int i = 1; i < 11; ++i)
	{
		myStack.push(i);
	}
	myStack.displayStack();

	int top = myStack.top();
	std::cout << top << std::endl;
	myStack.pop();
	myStack.pop();
	myStack.pop();
	myStack.pop();

	top = myStack.top();
	std::cout << top << std::endl;
	myStack.displayStack();

	myStack.top() -= 5;

	return 0;
}


