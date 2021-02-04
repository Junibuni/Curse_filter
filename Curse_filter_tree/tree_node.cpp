#include "tree_node.h"
#include "tree_class.h"

Node::Node(std::string data)
{
	this->data = data;
	this->child = nullptr;
	this->sibling = nullptr;
}
Node::~Node()
{
	DeleteNode(child);
	DeleteNode(sibling);
}

void Node::DeleteNode(Node* n)
{
	if (n == nullptr) return;
	delete n;
}

void Node::SetData(std::string data){this->data = data;}
void Node::SetChild(Node* child){this->child = child;}
void Node::SetSibling(Node* sibling){this->sibling = sibling;}
std::string Node::GetData(){return data;}
Node* Node::GetChild(){return child;}
Node* Node::GetSibling(){return sibling;}


void Tree::ParentInsertChild(std::string data)
{
	Node* tmp;
	if (this->current == nullptr) this->current->SetChild(new Node(data));
	else
	{
		tmp = this->current->GetChild();
		if (tmp == nullptr)
		{
			this->current->SetChild(new Node(data));
			return;
		}
		while (1)
		{
			if (tmp->GetSibling() == nullptr)
			{
				tmp->SetSibling(new Node(data));
				break;
			}
			tmp = tmp->GetSibling();
		}
	}
}

void Tree::ParentDeleteChild(std::string data) {
	Node* tmp = nullptr;
	Node* pre = nullptr;
	tmp = this->current->GetChild();

	if (tmp == nullptr)
	{
		std::cout << "data가 없습니다." << std::endl;
		return;
	}
	if (tmp->GetData() == data)
	{
		this->current->SetChild(tmp->GetSibling());
		tmp->SetSibling(nullptr);
		delete tmp;
		return;
	}

	while (1) //형제는 살리고 자식만 자르기
	{
		pre = tmp;
		tmp = tmp->GetSibling();
		if (tmp == NULL) return;
		if (tmp->GetData() == data)
		{
			pre->SetSibling(tmp->GetSibling());
			tmp->SetSibling(nullptr);
			delete tmp;
			break;
		}
	}
	if (tmp == NULL) std::cout << "data가 없습니다." << std::endl;
}

void Tree::PrintChild()
{
	Node* tmp = this->current->GetChild();
	if (tmp == nullptr) std::cout << "child가 없습니다." << std::endl;
	else
	{
		while (1)
		{
			if (tmp == nullptr) break;
			std::cout << tmp->GetData() << std::endl;
			tmp = tmp->GetSibling();
		}
		std::cout << std::endl;
	}
}