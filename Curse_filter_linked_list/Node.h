#pragma once
#include <iostream>

class List
{
private:
	class Node
	{
	public:
		std::string data;
		Node* nextNode;
	};
	int count; //list �� ũ��
	Node* Head = new Node;
	Node* Tail = new Node;
public:
	List();
	~List();
	std::string getData(int index); //index ������ ���
	void add(std::string data); //�� �տ� ���ο� ��� �߰�
	int size(); //list �� ũ��
	void setData(int index, std::string data); //�ش� index�� ������ ����
	void remove(int index); //��� ����
	void show();
};