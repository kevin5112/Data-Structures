#include <iostream>
#include <unordered_map>
using namespace std;

struct node
{
	int val;
	node* left;
	node* right;

	node(int x) : val(x), left(NULL), right(NULL) {}
};

class heap
{
public:
	heap() { root = NULL; lastNode = NULL; heapSize = 0; }

	int size() { return heapSize; }
	bool empty() { return size() == 0; }
	void insert(int x) {
		node* newNode = new node(x);
		if(empty()) {
			root = newNode;
			lastNode = root;
			++heapSize;
			return;
		}

		// find which node to insert from determining if theres
		// an even or odd amount of nodes in the heap currently
		if(size() % 2 == 1)
		{
			cout << "inserting " << x << " on left\n";
			// check to make sure node isn't already in hash table
			if(parentTracker.find(newNode) != parentTracker.end())
			{
				cout << "error\n";
				return;
			}
			// if odd, insert to left
			lastNode->left = newNode;
			parentTracker[newNode] = lastNode;
			++heapSize;
			bubbleUp(newNode); 
		}
		else
		{
			cout << "inserting " << x << " on right\n";
			// check to make sure node isn't already in hash table
			if(parentTracker.find(newNode) != parentTracker.end())
			{
				cout << "error\n";
				return;
			}
			// if even, insert to right
			lastNode->right = newNode;
			parentTracker[newNode] = lastNode;
			++heapSize;
			bubbleUp(newNode); 

			if(lastNode == root)
			{
				lastNode = root->left;
				return;
			}

			// means we finished making a perfect balanced tree
			if(lastNode == parentTracker[lastNode]->right)
			{
				// put last node on the left most node on the bottomest row
				lastNode = parentTracker[lastNode]->left->left;
			}
			else
			{
				lastNode = parentTracker[lastNode]->right;
			}
		}
	}

	// TODO: create bubble up function
	void bubbleUp(node* child)
	{
		node* parent = parentTracker[child];
		node* grandParent;

		if(size() > 3)
		{
			grandParent = parentTracker[parent];

			// checks to see which of the parents are lower, and then chooses a parent based off the answer
			parent = (grandParent->left->val < grandParent->right->val) ? grandParent->left : grandParent->right;
		}

		// if child is greater than parent OR if child is the root node
		if(child->val > parent->val || child == root)
		{
			return;
		}

		// check if current node value is less than parent
		if(child->val < parent->val)
		{
			swap(child->val, parent->val);
			bubbleUp(parent);
		}
	}

	void printPostOrder()
	{
		cout << "Printing PostOrder: ";
		printPostOrder(root);
		cout << endl;
	}

private:
	node* root;

	// get the pointer to parent and determine which child it is based on if total # of nodes is even or odd
	node* lastNode; 

	unordered_map<node*, node*> parentTracker;
	int heapSize;

	void printPostOrder(node* curr)
	{
		if(!curr)
			return;

		printPostOrder(curr->left);
		printPostOrder(curr->right);
		cout << curr->val << ' ';
	}
};



int main()
{
	heap myHeap;
	myHeap.insert(1);
	myHeap.printPostOrder();

	myHeap.insert(6);
	myHeap.printPostOrder();

	myHeap.insert(5);
	myHeap.printPostOrder();

	myHeap.insert(7);
	myHeap.printPostOrder();

	myHeap.insert(9);
	myHeap.printPostOrder();

	myHeap.insert(2);
	myHeap.printPostOrder();

	return 0;
}