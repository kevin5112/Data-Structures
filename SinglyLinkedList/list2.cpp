#include <iostream>
using namespace std;

class node
{
public:
	node() : next(nullptr), val(-1) {}
	node(int v, node* n) : next(n), val(v) {}
	node(int v) : next(nullptr), val(v) {}
private:
	node* next;
	int val;
};

class list
{
public:

private:
	node* head;
	int size;
};

int main()
{
	
	return 0;
}