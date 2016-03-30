#ifndef _LLIST_
#define _LLIST_

#include "Node.h"

//A template for Linked Lists that hold refrences 

template <class T>
class LinkedList
{

	Node<T> *header;
	Node<T> *tail;
	int size;
	const int maxSize = 1024;
public:
	//Constructor with no parameters
	LinkedList();


	//Adds an item with data T
	bool addItem(T&);

	//Returns the header of the list
	Node<T>* first();

	//Returns the tail of the last
	Node<T>* last() const;

	//Removes the item whose index is given
	bool removeItem(int);

	//Gets the size of the list
	int getCount() const;

	//Sets the size of the list
	void setSize(int);

	//Clears the list of all the nodes
	void clear();

	//Overload operator[] for const objects
	const Node<T> operator[](int) const;

	//Overload operator[] for non-const objects
	Node<T> operator[](int);

	//Overload operator= for non-const objects
	LinkedList<T>& operator=(const LinkedList&);


	//Prints the list contents
	void printList() const;

	//Linked list destructor
	~LinkedList();

};
template <class T>
LinkedList<T>::LinkedList() : header(NULL), tail(NULL), size(0)
{

}


template <class T>
bool LinkedList<T>::addItem(T& newData)
{
	//Creates a new node from the given data
	Node<T>* newNode = new Node<T>(newData);

	//If allocation fails
	if (newNode == NULL)
	{
		cout << "Allocation failed\n";
		return false;
	}

	//if the list is empty create first element of the list
	if (getCount() == 0)
	{

		//start and end pointer are same becuase there is only one object in list 
		header = newNode;
		tail = newNode;
		header->setNext(NULL);
		header->setPrev(NULL);
		tail->setNext(NULL);
		tail->setPrev(NULL);
	}
	else //if node(s) exist in list insert additional object before the first
	{
		//second object in the list
		if (getCount() == 1)
		{
			newNode->setPrev(header);
			newNode->setNext(NULL);
			tail = newNode;
			header->setNext(newNode);

		}

		//If the list is not full
		else if (getCount() != maxSize)
		{
			newNode->setPrev(tail);
			newNode->setNext(NULL);
			tail->setNext(newNode);
			tail = newNode;
		}

		//The list is full
		else
		{
			cout << "The list has reached its capacity\n";
			return false;
		}

	}

	//Increment size by 1
	setSize(getCount() + 1);
	return true;
}

template <class T>
bool LinkedList<T>::removeItem(int i)
{
	//cout << "Deleting item " << i << " of the list\n";

	//Index out of range
	if (getCount() < i || i <= 0)
	{
		cout << "Index out of range\n";
		return false;
	}

	Node<T>*  tmp = header;

	//Only one item in the list
	if (i == 1 && getCount() == 1)
	{
		delete header;
		header->setPrev(NULL);
		header->setNext(NULL);
		tail->setPrev(NULL);
		tail->setNext(NULL);
	}

	//remove first element when the list has more than 1 element
	else if (i == 1 && getCount() > 1)
	{
		tmp = tmp->getNext();
		tmp->setPrev(NULL);
		delete header;
		header = tmp;

	}
	//remove the last element
	else if (i == getCount())
	{
		tmp = tail;
		tmp = tmp->getPrev();
		tmp->setNext(NULL);
		delete tail;
		tail = tmp;
	}

	//Remove item in the middle of the list
	else
	{
		tmp = header;
		int counter = 1;

		//At the end of the loop tmp will be the index i that is needed to be removed
		while (tmp != NULL && i != counter)
		{
			tmp = tmp->getNext();
			counter++;

		}

		tmp->getPrev()->setNext(tmp->getNext());
		tmp->getNext()->setPrev(tmp->getPrev());
		delete tmp;
	}

	//Decrease size by 1
	setSize(getCount() - 1);
	//cout << "Element " << i << "was removed!\n";
	return true;

}
template <class T>
const Node<T>  LinkedList<T>::operator[](int i) const
{
	if (getCount() < i || i <= 0)
	{
		cout << "Index out of range\n";
		exit(1);
	}
	int counter = 1;

	//Gets the wanted index
	while (tmp != NULL && i != counter)
	{
		tmp = tmp->get(next);
		counter++;

	}
	return tmp;
}


template <class T>
Node<T>  LinkedList<T>::operator[](int i)
{

	if (getCount() < i || i < 0)
	{
		cout << "Index out of range\n";
		exit(1);
	}
	int counter = 1;
	Node<T>* tmp = header;
	if (i == 0)
	{
		return *tmp;
	}
	//Gets the wanted index
	while (tmp != NULL && i >= counter)
	{
		tmp = tmp->getNext();
		counter++;

	}
	return *tmp;
}

template <class T>
LinkedList<T>&  LinkedList<T>::operator=(const LinkedList& other)
{
	//Clears the list 
	this->clear();
	Node<T>* tmp = other.header;

	//Sets counter to the size of other list
	int counter = other.getCount();

	//Adds the elements of other list
	for (int i = 1; i <= counter; i++)
	{
		this->addItem(tmp->getData());
		tmp = tmp->getNext();
	}
	return *this;
}



template <class T>
Node<T>* LinkedList<T>::first()
{
	return header;
}

template <class T>
Node<T>* LinkedList<T>::last() const
{
	return tail;
}
template <class T>
void LinkedList<T>::setSize(int s)
{
	size = s;
}

template <class T>
int LinkedList<T>::getCount() const
{
	return size;
}

template <class T>
void LinkedList<T>::clear()
{
	//cout << "Clearing the list of all the nodes...\n";
	while (getCount()> 0)
	{
		removeItem(getCount());
	}
}

//Shows the contents of the list
template <class T>
void LinkedList<T>::printList() const
{
	Node<T>* tmp;
	tmp = header;
	if (getCount() == 0)
	{
		//cout << "The list is Empty\n";
		return;
	}

	int counter = getCount();
	//cout << "Printing the items of the list...\n";
	for (int i = 1; i <= counter; i++)
	{
		tmp->printData();
		tmp = tmp->getNext();


	}

}



//Linked List destructor
template <class T>
LinkedList<T>::~LinkedList()
{
	//cout << "Linked List destructor is called here\n";
	clear();

}
#endif
