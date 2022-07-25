#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
struct Node
{
    //declaration
    int value;
    Node* next;
};


class List
{
private:
    Node* head;
public:
    //taking function
     List();
    bool isEmpty();
    int length();
    void print();
    void addAsHead(int);
    void addAsTail(int);
    Node* find(int);
    void reverse();
    int popHead();
    void removeFirst(int);
    void removeAll(int);
    void addAll(List&);
     ~List();
};

#endif // LIST_H_INCLUDED
