#pragma once
#include <iostream>

class List
{
private:
	class Node
	{
	public:
		char* data;
		Node* nextNode;
	};
	int count; //list �� ũ��

public:
	Node* Head = new Node;
	Node* Tail = new Node;
	List();
	~List();
	char* getData(int index); //index ������ ���
	void add(char* data); //�� �տ� ���ο� ��� �߰�
	int size(); //list �� ũ��
	void setData(int index, char* data); //�ش� index�� ������ ����
	void remove(int index); //��� ����
	void show();
};