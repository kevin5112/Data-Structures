#include <iostream>
using namespace std;


class Vector {
public:
	Vector() : vec(nullptr), vSize(0), vMaxSize(0) {}
	Vector(int n, int val) { 
		vSize = n; 
		vec = new int[n]; 
		vMaxSize = n;
		for(auto i = 0; i < n; ++i) 
		{ 
			vec[i] = val; 
		}
	}

	int size() { return vSize; }
	bool empty() { return size() == 0; }
	int maxSize() { return vMaxSize; }
	void push_back(const int& val) {
		if(vMaxSize == 0)
		{
			vec = new int[10];
			vMaxSize = 10;
		}
		if(size() == vMaxSize) {
			reallocateVec();
		}
		vec[vSize] = val;
		++vSize;
	}

	void reallocateVec() {
		int * nVec = new int[vMaxSize * 2];
		for(int i = 0; i < vMaxSize; ++i)
		{
			nVec[i] = vec[i];
		}
		delete vec;
		vec = nVec;
		vMaxSize *= 2;
	}

	void print() {
		cout << "Vector: [";
		for(int i = 0; i < size(); ++i)
		{
			cout << vec[i] << ((i == size() - 1) ? "" : " ");
		}
		cout << "]\n";
	}

	void debug() { 
		cout << "max size: " << maxSize() << " / size: " << size() << endl;

	}

	int back() {
		if(empty()) {
			cout << "empty...\n";
			return -999;
		}
		return vec[size() - 1];
	}

	int front() {
		if(empty())
			return back();
		return vec[0];
	}

	void pop_back() {
		if(empty())
			return;
		--vSize;
	}



private:
	int *vec;
	int vSize;
	int vMaxSize;
};


int main()
{
	Vector v;

	for(int i = 0; i < 10; ++i)
	{
		v.push_back(i);
	}
	v.print();
	cout << "back: " << v.back() << endl;
	v.pop_back();
	v.push_back(1);
	v.print();
	cout << "front: " << v.front() << endl;

	return 0;
}