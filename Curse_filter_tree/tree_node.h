#pragma once
#include <string>

class Node
{
private:
	std::string data;
	Node* child;
	Node* sibling;
public:
	Node(std::string data);
	~Node();

	void DeleteNode(Node* n);
	void SetData(std::string data);
	void SetChild(Node* child);
	void SetSibling(Node* sibling);
	std::string GetData();
	Node* GetChild();
	Node* GetSibling();
};