#pragma once

#include "node.h"

class LinkedList
{
    Node *head, *tail, *iter;
public:
    LinkedList();
    ~LinkedList();
    void addNode(int val);
    void delNode(int val);
};

