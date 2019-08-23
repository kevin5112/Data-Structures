#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// class node {
// public:
// 	node(int d) : data(d), left(nullptr), right(nullptr) {}
// 	node(int d, node* l, node* r) : data(d), left(l), right(r) {}
// 	void setData(int d) { data = d; }
// 	int getData() { return data; }
// 	void setLeft(node* l) { left = l; }
// 	node* getLeft() { return left; }
// 	void setRight(node* r) { right = r; }
// 	node* getRight() { return right; }

// private:
// 	int data;
// 	node* left;
// 	node* right;
// };


// class heap {
// public:
// 	heap(vector<int> v) { 
// 		for(int i : v){
// 			root.push_back
// 		}
// 	}
// 	int size() { return heapSize; }
// 	bool empty() { return size() == 0; }
// 	void makeheap(vector<int>& v); 
// 	void printHeap() {
// 		for(int i = 0; i < heapSize; ++i) {
// 			cout << root[i] << ' ';
// 		}
// 		cout << endl;
// 	}

// private:
// 	vector<int> root;
// 	int heapSize;

// 	void max_heapify(vector<int>& v, int index);
// };


// void heap::makeheap(vector<int> v) {
// 	bool isRight = false;
// 	heapSize = v.size();
// 	if(v.size() % 2) {
// 		isRight = true;
// 	}

// 	for(int i = v.size() / 2 - 1; i >= 0; --i) {
// 		// make new node at each node
// 		node* curr = new node(v[i]);
// 		// connect left and right childs(if right child exists)

// 		// if there is a node that can be connected to the right side
// 		if(isRight) { // adding 2 to deal with 0 based indexes.. and checking bounds
// 			// create node and add it to current node as right child
// 			node* rightNode = new node(v[(i * 2) + 1]);
// 			curr->setRight(rightNode);
// 		}


// 		// do max_heapify to secure that at i, tree is maxheap
// 		max_heapify(v, i);

// 		// set isRight to true since after first node, there will always be a right node
// 		isRight = true;
// 	}

// }

void max_heapify(vector<int>& v, int index) {
	if(index > v.size() / 2 - 1)
	{
		return;
	}

	int rIndex = index * 2 + 2;
	int lIndex = index * 2 + 1;
	if(rIndex < v.size()) {
		// check which child is greater and see if it is greater than current index
		int biggerIndex;
		if(v[rIndex] > v[lIndex])
		{
			biggerIndex = rIndex;
		}
		else
		{
			biggerIndex = lIndex;
		}

		// check if v[index] is greater than v[biggerindex]
		if(v[biggerIndex] > v[index]) {
			swap(v[index], v[biggerIndex]);
			max_heapify(v, biggerIndex);
		}
	}
	else
	{
		if(v[index] < v[lIndex]) {
			swap(v[index], v[lIndex]);
		}
	}
	return;
}


void makeheap(vector<int>& v) {
	for(int i = v.size() / 2 - 1; i >= 0; --i) {
		max_heapify(v, i);
	}
}



int main()
{
	vector<int> v = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};

	for(int i : v) {
		cout << i << ' ';
	}
	cout << endl;

	makeheap(v);

	for(int i : v) {
		cout << i << ' ';
	}
	cout << endl;



	return 0;
}