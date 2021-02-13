#pragma once

#include <vector>
#include <string>

class Node {

private:
    Node* parent;
    std::vector <Node*> children;

    std::string data;

public:
    Node();
    Node(Node *parent, std::vector<Node*> children);
    Node(Node *parent, std::vector<Node*> children, int data);

    Node* GetParent();

    void SetChildren(std::vector<Node*> children);
    std::vector<Node*> GetChildren();
    void AddChildren(Node* children);

    void SetData(int data);
    int GetData();

    bool IsLeaf();
    bool IsInternalNode();
    bool IsRoot();

};