#include <iostream>
#include <list>
using namespace std;


class queue
{
public:
	queue() { queueSize = 0; }
	int size() { return queueSize; }
	bool empty() { return size() == 0; }
	int front() { return list.front(); }
	int back() { return list.back(); }
	void push(int i) {
		list.push_back(i);
	}
	void pop() {
		list.pop_front();
	}

	void print(){
		for(auto it = list.begin(); it != list.end(); ++it)
		{
			cout << *it << " -> ";
		}
		cout << "end\n";
	}

private:
	list<int> list;
	int queueSize;
};


int main()
{
	queue myQueue;

	for(int i = 1; i < 11; ++i)
	{
		myQueue.push(i);
	}

	myQueue.print();
	myQueue.pop();
	myQueue.pop();
	myQueue.pop();
	myQueue.pop();
	myQueue.pop();
	myQueue.print();	


	return 0;
}