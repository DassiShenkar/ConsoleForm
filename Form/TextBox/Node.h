#ifndef _NODE_
#define _NODE_
#include <iostream>

template <class T>
class Node
{
	Node *prev;
	Node *next;
	T& data;
public:

	//Constructor with no parameters
	Node();

	//Constructor with the data as parameter
	Node(T&);

	//Node destructor
	~Node();

	//Sets the data
	void setData(T&);

	//Returns the data as reference
	T& getData() const;

	//Sets the previous Node
	void setPrev(Node *);

	//Gets the previous Node 
	Node* getPrev() const;

	//Sets the next Node
	void setNext(Node *);

	//Gets the next Node
	Node* getNext() const;



	//Prints the node's data
	void printData() const;



};
template <class T>
Node<T>::Node() : prev(NULL), next(NULL), data(NULL)
{

}


template <class T>
Node<T>::Node(T& _data) : prev(NULL), next(NULL), data(_data)
{

}



template <class T>
void Node<T>::setData(T& t)
{
	this->data = t;
}
template <class T>
T& Node<T>::getData() const
{

	return data;
}

template <class T>
void Node<T>::setPrev(Node *p)
{
	prev = p;
}

template <class T>
Node<T>* Node<T>::getPrev() const
{
	return prev;
}

template <class T>
void Node<T>::setNext(Node *n)
{
	next = n;
}

template <class T>
Node<T>* Node<T>::getNext() const
{
	return next;
}

//Shows the data
template <class T>
void Node<T>::printData() const
{
	//Assuming operator << is defined at the data class
	cout << this->getData() << "\n";
}

//Node destructor
template <class T>
Node<T>::~Node()
{

}
#endif