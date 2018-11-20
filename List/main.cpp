#include <iostream>
#include "list.h"


int main()
{
	list myList;

	// test push_back
	for(int i = 1; i <= 10; ++i)
		myList.push_back(i);
	std::cout << "myList.push_back(): ";

	// test display
	myList.display();

	// test empty
	std::cout << "empty: " << myList.empty() << std::endl;

	// test size
	std::cout << "size: " << myList.size() << std::endl;

	// test front
	std::cout << "front: " << myList.front() << std::endl;

	// test back
	std::cout << "back: " << myList.back() << std::endl;
	
	// test reverse
	myList.reverse();
	std::cout << "reverse: ";
	myList.display();

	// test pop_back
	myList.pop_back();
	std::cout << "myList.pop_back(): ";
	myList.display();

	//test pop_front
	myList.pop_front();
	std::cout << "myList.pop_front(): ";
	myList.display();

	// test clear
	myList.clear();

	// test push_front
	for(int i = 1; i <= 10; ++i)
		myList.push_front(i);
	std::cout << "myList.push_front(): ";
	myList.display();

	// test insert
	std::cout << "myList.insert(11): ";
	myList.insert(11, 4);
	myList.display();
	std::cout << "myList.insert(12): ";
	myList.insert(12, 6);
	myList.display();

	// test remove
	std::cout << "myList.remove(4): ";
	myList.remove(4);
	myList.display();
	std::cout << "myList.remove(5): ";
	myList.remove(5);
	myList.display();

	return 0;
}