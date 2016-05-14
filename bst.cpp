#include "BST.h"
#include <iostream>
#include <iomanip>

using namespace std;

BST::BST(int capacity) :
	items(new item[capacity]), size(0), capacity(capacity)
{
}

BST::~BST()
{
	if (items)
	{
		delete items;
	}
}

// insert a new item into the BST
void BST::insert (const data& aData)
{
	int j = 0;
	bool done = false;
	if (size == 0)
	{
		items[0].input = aData;
		items[0].empty = false;
		size++;
	}
	else if (strcmp(aData.getName(), items[j].input.getName()) < 0) // new item is smaller, insert to left
	{
		while (!done)
		{
			if (((2*j)+1) <  capacity)
			{
				if (items[(2*j)+1].empty == true) // if left is empty, add
				{
					items[(2*j)+1].input = aData;
					items[(2*j)+1].empty = false;
					size++;
					done = true;
				}
				else
				{
					j++;
				}
			}
			else // array too small, make larger array
			{
				item *temp = new item[2*capacity];
				int i = 0;
				for (i = 0; i < capacity; i++)
				{
					temp[i].input = items[i].input;
					temp[i].empty = items[i].empty;
				}
				capacity = 2*capacity;
				items = temp;
			}
		}
	}			
	else // new item is larger, insert to right
	{
		while (!done)
		{
			if (((2*j)+2) <  capacity)
			{
				if (items[(2*j)+2].empty == true) // if right is empty, add
				{
					items[(2*j)+2].input = aData;
					items[(2*j)+2].empty = false;
					size++;
					done = true;
				}
				else
				{
					j++;
				}
			}
			else // array too small, make larger array
			{
				item *temp = new item[2*capacity];
				int i = 0;
				for (i = 0; i < capacity; i++)
				{
					temp[i].input = items[i].input;
					temp[i].empty = items[i].empty;
				}
				capacity = 2*capacity;
				items = temp;
			}
		}
	}
}

// retrieve item associated with key
// returns true if it finds key, false if it can't

bool BST::retrieve(const char *key, data& aData) const
{
	int j = 0;
	if (size == 0)
	{
		return false;
	}
	else
	{
		while(j < capacity)
		{
			if (items[j].empty == false)
			{
				if (items[j].input.getName() == key) // if match
				{
					aData = items[j].input;
					return (true);
				}
				else
				{
					j++;
				}
			}
			else
			{
				j++;
			}
		}
	}
	return (false);		
}

// remove item associated with key from BST
bool BST::remove(const char* key)
{
	int j = 0;
	while (j < capacity)
	{
		if (items[j].empty == false)
		{
			if (items[j].input.getName() == key)
			{
				items[j].empty = true;
				size--;
				return (true);
			}
			else 
			{
				j++;
			}
		}
		else
		{
			j++;
		}
	}
	return (false);
}

// display items in the tree by traversing the array from beginning to end
void BST::displayArrayOrder (ostream& out) const
{
	int j = 0;
	while (j < capacity)
	{
		if (items[j].empty == false)
		{
			out << items[j].input << endl;
		}
		j++;
	}
}

// display items in the tree in preorder
void BST::displayPreOrder (ostream& out) const
{
	int j = 0;
	while (j > capacity)
	{
		out << items[j].input << endl;
		j = (2*j)+1;
		displayPreOrder(out);
		j = (2*j)+2;
		displayPreOrder(out);
	}
}

// display items in the tree in inorder
void BST::displayInOrder (ostream& out) const
{
	int j = 0;
	while (j > capacity)
	{
		j = (2*j)+1;
		displayPreOrder(out);
		out << items[j].input << endl;
		j = (2*j)+2;
		displayPreOrder(out);
	}
}

// display items in the tree in postorder
void BST::displayPostOrder (ostream& out) const
{
	int j = 0;
	while (j > capacity)
	{
		j = (2*j)+1;
		displayPreOrder(out);
		j = (2*j)+2;
		displayPreOrder(out);
		out << items[j].input << endl;
	}
}

// return number of data items contained in the BST
int BST::getSize (void) const
{
	return size;
}
