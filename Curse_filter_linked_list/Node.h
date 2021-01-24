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
	int count; //list 의 크기

public:
	Node* Head = new Node;
	Node* Tail = new Node;
	List();
	~List();
	char* getData(int index); //index 데이터 출력
	void add(char* data); //맨 앞에 새로운 노드 추가
	int size(); //list 의 크기
	void setData(int index, char* data); //해당 index에 데이터 변경
	void remove(int index); //노드 삭제
	void show();
};