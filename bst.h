// do not change this file except within the private section

#ifndef BST_H
#define BST_H

#include "data.h"

class BST								// a Binary Search Tree (BST)
{
public:
	BST(int capacity = 5);				// constructor (default if no arg supplied)
	BST(const BST& aTable);				// copy constructor
	~BST();								// destructor

	void insert(const data& aData);		
	bool remove(const char *key);
	bool retrieve(const char *key, data& aData) const;
	void displayArrayOrder(ostream& out) const;		
	void displayPreOrder(ostream& out) const;
	void displayInOrder(ostream& out) const;
	void displayPostOrder(ostream& out) const;
	int getSize(void) const;

private:
	struct item
	{
		bool empty;
		data input;
	};
	item *items;
	int capacity;
	int size;

	
};


#endif // BST_H