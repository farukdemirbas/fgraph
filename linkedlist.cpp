#include "linkedlist.h"

LinkedList::LinkedList()
    : head(nullptr), tail(nullptr), iter(nullptr)
{}

LinkedList::~LinkedList()
{
    Node* curr = head;
    iter = curr;
    while (iter != nullptr)
    {
        iter = iter->next;
        delete curr;
        Node* curr = iter;
    }
}

void LinkedList::addNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->next = nullptr;

    if (head == nullptr)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = tail->next;
    }
}

void LinkedList::delNode(int val)
{
    for(iter = head; iter != nullptr; iter = iter->next)
    {
        if(iter->data == val)
        {
            break;
        } // *iter is currently our target node
    }
    if (iter == head)
    {
        head = head->next;
        delete iter;
    }
    else
    {

    }
}
