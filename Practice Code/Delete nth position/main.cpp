#include <iostream>

using namespace std;

struct Node{
   int data;
   struct Node* next;

};
struct Node* head;//global

void insert(int data);//insert value end of the list
{
   Node *temp1 = new Node();
   temp->data = x;
   temp->next=NULL;
   if(*head !=NULL)
    temp->next = *head;
   *head=temp;
}
void print(); //print all element in the list

void delete(int n);//delete node at position n
{
    struct Node* temp1 = head;
    if(n=1){
        head = temp1-> next;
        free(temp1);
        return;
    }
    int i;
    for(i=0;i<n-2;i++)
        temp1=temp1->next;
    struct Node* temp2=temp1->next;
    free(temp2);
}


int main()
{
    int n;
    head=NULL;
    insert(2);
    insert(4);
    insert(6);
    insert(5);
    print();
    cout<<"Enter a position: "<<endl;
    cin>>n;
    delete(n);
    print();
    return 0;
}
