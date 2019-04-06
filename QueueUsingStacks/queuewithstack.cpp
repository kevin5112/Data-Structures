#include <iostream>
#include <stack>
using namespace std;

class queue {
public:
	queue() : queueSize(0), lastValInserted(-1) {}

	int size() { return queueSize; }

	bool empty() { return size() == 0; }

	void push(int d)
	{
		lastValInserted = d;
		enqueueStack.push(d);
		queueSize++;
	}

	void pop()
	{
		if(!checkDequeueStatus())
		{
			cout << "Failed to insert\n";
			return;
		}
		dequeueStack.pop();
		--queueSize;
	}

	int front() 
	{ 
		if(!checkDequeueStatus())
		{
			cout << "Unable to get front\n";
			return -1;
		}
		return dequeueStack.top();
	}

	int back()
	{
		if(!checkDequeueStatus())
		{
			cout << "Unable to get back\n";
			return -1;
		}
		return lastValInserted;
	}

	void clear()
	{
		while(!empty())
		{
			pop();
		}
	}

	void print()
	{
		stack<int> en(enqueueStack);
		stack<int> de(dequeueStack);

		cout << "queue: ";
		while(!de.empty())
		{
			cout << de.top() << ' ';
			de.pop();
		}

		while(!en.empty())
		{
			de.push(en.top());
			en.pop();
		}

		while(!de.empty())
		{
			cout << de.top() << ' ';
			de.pop();
		}
		cout << endl;
	}

	~queue() { clear(); }


private:
	stack<int> enqueueStack;
	stack<int> dequeueStack;
	int queueSize;
	int lastValInserted;

	bool populateDequeueStack()
	{
		if(enqueueStack.empty())
		{
			return false;
		}

		while(!enqueueStack.empty())
		{
			dequeueStack.push(enqueueStack.top());
			enqueueStack.pop();
		}
		return true;
	}

	bool checkDequeueStatus()
	{
		if(dequeueStack.empty())
		{
			if(!populateDequeueStack())
			{
				return false;
			}
		}
		return true;
	}
};


int main()
{
	queue myQueue;

	// push 10 values from 0-9 into queue
	for(int i = 0; i < 10; i++)
	{
		myQueue.push(i);
	}

	// display front of queue, pop 1, then display value again
	cout << myQueue.front() << endl;
	myQueue.pop();
	cout << myQueue.front() << endl;

	// displaying back of queue
	cout << myQueue.back() << endl;

	// push 99 to back of queue and then display it
	myQueue.push(99);
	cout << myQueue.back() << endl;

	myQueue.print();

	myQueue.clear();
	cout << myQueue.front() << endl;



	return 0;
}





