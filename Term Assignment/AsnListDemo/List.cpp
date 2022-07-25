#include<iostream>
#include"List.h"

//boolean
List:: List() : head(nullptr) {}
bool List::isEmpty()
{
    return head == nullptr;
}
//length
int List :: length()
{
    int length = 0;
    Node* ptr = head;
    while (ptr != nullptr)
    {
        ptr = ptr->next;
        ++length;
    }
    return length;
}
//printing
void List:: print()
{
    Node* ptr = head;
    std::cout << '[';
    while (ptr != nullptr)
    {
        if (ptr != head)
        {
            std::cout << ", ";
        }
        std::cout << ptr->value;
        ptr = ptr->next;
    }
    std::cout << ']';
}

//asHead
void List:: addAsHead(int i)
{
    head = new Node{i, head};
}

//asTail
void List:: addAsTail(int i)
{
    if (head == nullptr)
    {
        head = new Node{i, nullptr};
        return;
    }
    Node* ptr = head;
    while (ptr->next != nullptr)
    {
        ptr = ptr->next;
    }
    Node* node = new Node{i, nullptr};
    ptr->next = node;
}
//Node Find
Node*  List:: find(int i)
{
    Node* ptr = head;
    while (ptr != nullptr)
    {
        if (ptr->value == i)
        {
            return ptr;
        }
        ptr = ptr->next;
    }
    return nullptr;
}

//reverse

void List:: reverse()
{
    if (head == nullptr || head->next == nullptr)
    {
        return;
    }
    Node* ptr = head;
    Node* ptr1 = head->next;
    ptr->next = nullptr;
    while (ptr1 != nullptr)
    {
        Node* temp = ptr;
        ptr = ptr1;
        ptr1 = ptr1->next;
        ptr->next = temp;
    }
    head = ptr;
}

//popHead
int List:: popHead()
{
    if (head == nullptr)
    {
        return -1;
    }
    Node* temp = head;
    head = head->next;
    return temp->value;
}

//removeFirst
void List:: removeFirst(int i)
{
    Node* ptr = head;
    Node* ptr1 = head;
    while (ptr != nullptr)
    {
        if (ptr->value == i)
        {
            if (ptr == head)
            {
                head = head->next;
                delete ptr;
                return;
            }
            ptr1->next = ptr->next;
            delete ptr;
            return;
        }
        else ptr1 = ptr;
        ptr = ptr->next;
    }
}

//removeAll
void List:: removeAll(int i)
{
    Node* ptr = head;
    Node* ptr1 = head;
    while (ptr != nullptr)
    {
        if (ptr->value == i)
        {
            if (ptr == head)
            {
                head = head->next;
                delete ptr;
                ptr = head;
                continue;
            }
            ptr1->next = ptr->next;
            Node* temp = ptr;
            ptr = ptr->next;
            delete temp;
        }
        else
        {
            ptr1 = ptr;
            ptr = ptr->next;
        }
    }
}

//addAll
void List:: addAll(List& l)
{
    if (l.head == nullptr)
    {
        return;
    }
    Node* ptr = head;
    if (ptr == nullptr)
    {
        ptr = new Node{l.head->value, nullptr};
        head = ptr;
    }
    else
    {
        while (ptr->next != nullptr)
        {
            ptr = ptr->next;
        }
        Node* temp = ptr;
        ptr = new Node{l.head->value, nullptr};
        temp->next = ptr;
    }
    Node* ptr1 = l.head->next;
    while (ptr1 != nullptr)
    {
        Node* temp = ptr;
        ptr = new Node{ptr1->value, nullptr};
        temp->next = ptr;
        ptr1 = ptr1->next;
    }
}
List:: ~List()
{
    Node* ptr = head;
    while (ptr != nullptr)
    {
        Node* temp = ptr;
        ptr = ptr->next;
        delete temp;
    }
}

