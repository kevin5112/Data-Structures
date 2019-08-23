#include <iostream>


class node
{
public:
	node(int d, node* l, node* r) : data(d), left(l), right(r) {}

	node* getleft() { return left; }
	void setleft(node* l) { left = l; }
	node* getright() { return right; }
	void setright(node* r) { right = r; }
	int getdata() { return data; }
	void setdata(int d) { data = d; }

private:
	node* left;
	node* right;
	int data;
};

class tree
{
public:
	tree() { root = nullptr; treeSize = 0; }
	int size() { return treeSize; }
	bool empty() { return size() == 0; }

	void insert(int value)
	{
		insert(value, root);
	}

	void insert(int value, node* currentNode)
	{
		if(empty())
		{
			root = new node(value, nullptr, nullptr);
			++treeSize;
			return;
		}

		if(value == currentNode->getdata())
		{
			std::cout << "Error: can't insert duplicates\n";
		}
		else if(value < currentNode->getdata())
		{
			if(currentNode->getleft() == nullptr)
			{
				node* newNode = new node(value, nullptr, nullptr);
				currentNode->setleft(newNode);
				++treeSize;
			}
			else
			{
				insert(value, currentNode->getleft());
			}
		}
		else
		{
			if(currentNode->getright() == nullptr)
			{
				node* newNode = new node(value, nullptr, nullptr);
				currentNode->setright(newNode);
				++treeSize;
			}
			else
			{
				insert(value, currentNode->getright());
			}
		}
		std::cout << "Inserted: " << value << std::endl;
	}

	bool contains(int value)
	{
		return contains(value, root);
	}

	bool contains(int value, node* currentNode)
	{
		if(value == currentNode->getdata())
		{
			return true;
		}
		else if(value < currentNode->getdata())
		{
			if(currentNode->getleft() == nullptr)
			{
				return false;
			}
			else
			{
				return contains(value, currentNode->getleft());
			}
		}
		else
		{
			if(currentNode->getright() == nullptr)
			{
				return false;
			}
			else
			{
				return contains(value, currentNode->getright());
			}
		}
	}

	void printInOrder()
	{
		printInOrder(root);
	}

	void printInOrder(node* currentNode)
	{
		if(currentNode->getleft() != nullptr)
		{
			printInOrder(currentNode->getleft());
		}
		std::cout << currentNode->getdata() << ' ';
		if(currentNode->getright() != nullptr)
		{
			printInOrder(currentNode->getright());
		}
	}

	void printPreOrder()
	{
		printPreOrder(root);
	}

	void printPreOrder(node *currentNode)
	{
		std::cout << currentNode->getdata() << std::endl;
		if(currentNode->getleft() != nullptr)
		{
			std::cout << " / \n";
			printPreOrder(currentNode->getleft());
		}
		else
			std::cout << "null\n";
		if(currentNode->getright() != nullptr)
		{
			std::cout << " \\ \n";
			printPreOrder(currentNode->getright());
		}
		else
			std::cout << "null\n";
		std::cout << std::endl;
	}

	void mirrortree()
	{
		mirrortreehelper(root);
	}

	void swap(node* atNode)
	{
		node* temp = atNode->getleft();
		atNode->setleft(atNode->getright());
		atNode->setright(temp);
	}

	void inOrderTrav()
	{
		std::cout << "p inorder: ";
		inOrderTravHelp(root);
		std::cout << std::endl;
	}

	void inOrderTravHelp(node* currentNode)
	{
		if(!currentNode)
		{
			return;
		}

		inOrderTravHelp(currentNode->getleft());
		std::cout << currentNode->getdata() << ' ';
		inOrderTravHelp(currentNode->getright());
	}

private:
	node* root;
	int treeSize;

	void mirrortreehelper(node* currentNode)
	{
		if(currentNode == nullptr)
		{
			return;
		}

		swap(currentNode);
		mirrortreehelper(currentNode->getleft());
		mirrortreehelper(currentNode->getright());

	}
};

int main()
{
	tree myTree;

	myTree.insert(5);
	myTree.printInOrder();

	myTree.insert(6);
	myTree.printInOrder();

	myTree.insert(4);
	myTree.printInOrder();

	for(int i = 1; i < 11; ++i)
	{
		myTree.insert(i);
	}

	std::cout << "tree in order: ";
	myTree.printInOrder();
	std::cout << std::endl;

	//myTree.printPreOrder();
	std::cout << "Mirroring tree...\n";
	myTree.mirrortree();
	std::cout << "tree in order: ";
	myTree.printInOrder();
	std::cout << std::endl;

	myTree.inOrderTrav();

	return 0;
}






