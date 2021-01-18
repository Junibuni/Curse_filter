#include <iostream>
#include "Node.h"

List::List()
{
	Head->nextNode = NULL;
	Tail->nextNode = NULL;
	List::count = 0;
}

List::~List() {}

std::string List::getData(int index)
{
	Node* temp = Head;
	for (int i = 0; i <= index; ++i)
	{
		temp = temp->nextNode;
	}
	return temp->data;
}

void List::add(std::string data)
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->nextNode = NULL;

	if (Head->nextNode == NULL)
	{
		Head->nextNode = newNode;
	}
	else
	{
		Tail->nextNode->nextNode = newNode;
	}
	Tail->nextNode = newNode;
	List::count++;
}

int List::size()
{
	return List::count;
}

void List::setData(int index, std::string data)
{
	Node* temp = Head;
	for (int i = 0; i <= index; ++i)
	{
		temp = temp->nextNode;
	}
	temp->data = data;

}

void List::remove(int index)
{
	Node* temp = Head;
	Node* remove = Head;

	for (int i = 0; i < index; ++i)
	{
		temp = temp->nextNode;
		remove = remove->nextNode;
	}
	remove = remove->nextNode;
	temp->nextNode = remove->nextNode;
	remove->nextNode = NULL;
	delete remove;
	List::count--;
}

void List::show()
{
	Node* temp = Head;
	while (temp != NULL)
	{
		std::cout << temp->nextNode->data << std::endl;
		temp = temp->nextNode;
	}
	delete temp;
}