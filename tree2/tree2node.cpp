#include "tree2node.h"

Node::Node() {
    this->parent = NULL;
    this->children = { 0, };
    this->data = "";
}

Node::Node(Node* parent, std::vector<Node*> children) {
    this->parent = parent;
    this->children = children;
}

Node::Node(Node* parent, std::vector<Node*> children, int data) {
    this->parent = parent;
    this->children = children;
    this->data = data;
}

Node* Node::GetParent() {
    return this->parent;
}

void Node::SetChildren(std::vector<Node*> children) {
    this->children = children;
}

std::vector<Node*> Node::GetChildren() {
    return this->children;
}

void Node::AddChildren(Node* children) {
    this->children.push_back(children);
}

void Node::SetData(int data) {
    this->data = data;
}