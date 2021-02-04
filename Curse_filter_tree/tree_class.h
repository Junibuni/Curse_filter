#pragma once
#include <iostream>
#include "tree_node.h"

class Tree
{
private:
	Node* root;
	Node* current;
public:
	Tree() { this->root = nullptr; this->current = nullptr; }
	Tree(std::string data) { this->root = new Node(data); this->current = nullptr;}
	~Tree() { delete root; }
	void SetRoot(std::string data) { this->root = new Node(data); this->current = root; }
	void SetCurrent(Node* n) { this->current = n; }
	Node* GetRoot() { return this->root; }
	Node* GetCurrent() { return this->current; }
	void NodeChangeData(std::string data) { this->current->SetData(data); }
	void ParentInsertChild(std::string data);
	void ParentDeleteChild(std::string data);
	void PrintChild();
};
