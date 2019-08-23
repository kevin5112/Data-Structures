#include <iostream>
#include <list>
using namespace std;

class hashNode
{
public:
	hashNode(int key, int value)
	{
		this->key = key;
		this->value = value;
		next = nullptr;
	}

	int getkey() { return key; }
	void setkey(int key) { this->key = key; }
	int getvalue() { return value; }
	void setvalue(int value) { this->value = value; }
	hashNode* getnext() { return next; }
	void setnext(hashNode* next) { this->next = next; }

private:
	int key;
	int value;
	hashNode* next;
};

class map
{
public:
	map(int buckets)
	{
		this->buckets = buckets;
		mapSize = 0;
		table = new list<hashNode>[buckets];
	}

	int size() { return mapSize; }
	bool empty() { return size() == 0; }
	int hash(int key) { return key * key * key / 15; }
	bool insert(int key, int value)
	{
		hashNode* newNode = new hashNode(key, value);
		int hashIndex = hash(key) % buckets;

		if(find(key))
		{
			return false;
		}
		table[hashIndex].push_back(*newNode);
		++mapSize;
		return true;
	}

	bool find(int key)
	{
		int i = hash(key) % buckets;
		for(auto it = table[i].begin(); it != table[i].end(); ++it)
		{
			if(it->getkey() == key)
			{
				return true;
			}
		}
		return false;
	}

	bool remove(int key)
	{
		if(!find(key))
		{
			cout << "Key does not exist\n";
			return false;
		}
		int i = hash(key) % buckets;
		auto it = table[i].begin();
		auto trailer = it;
		while(it != table[i].end())
		{
			if(it->getkey() == key)
			{
				break;
			}
			trailer = it;
			++it;
		}
		trailer->setnext(it->getnext());
		table[i].erase(it);
		--mapSize;
		return true;
	}



	void print()
	{
		for(int i = 0; i < buckets; ++i)
		{
			for(auto it = table[i].begin(); it != table[i].end(); ++it)
			{
				cout << it->getvalue() << " -> ";
			}
			cout << "null" << endl;
		}
	}

private:
	list<hashNode> *table;
	int mapSize;
	int buckets;
};


int main()
{
	map myMap(10);
	cout << "Empty: " << myMap.empty() << endl;
	cout << "Size: " << myMap.size() << endl;
	cout << "------------------------------\n";
	for(int i = 1; i < 11; ++i)
	{
		if(!(myMap.insert(i, i)))
		{
			cout << "Could not insert " << i << endl;
		}
	}
	myMap.print();
	cout << "------------------------------\n";

	for(int num = 9; num < 13; ++num)
	{
		if(myMap.find(num))
		{
			cout << "Found: " << num << endl;
		}
		else
		{
			cout << "Could not find " << num << endl;
		}
	}
	
	cout << "Empty: " << myMap.empty() << endl;
	cout << "Size: " << myMap.size() << endl;

	int num = 5;
	if(myMap.insert(num,num))
	{
		cout << num << " inserted\n";
	}
	else
	{
		cout << num << " is a duplicate\n";
	}

	cout << "removing 5\n";
	myMap.remove(5);
	cout << "removing 6\n";
	myMap.remove(6);
	cout << "removing 2\n";
	myMap.remove(2);
	cout << "Size: " << myMap.size() << endl;
	cout << "------------------------------\n";

	myMap.print();
	
	return 0;
}