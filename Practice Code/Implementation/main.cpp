////Inserting a node at the beginning
#include<iostream>

using namespace std;

struct Node{
    int data;//taking data
    Node* next;//taking address "next"
};
struct Node* head; //Global Variable or Make Header Node

void insert(Node** head,int x)
{
   struct Node* temp = (Node*) malloc (sizeof(struct Node));//Creating memory block
   temp->data = x;
   temp->next=NULL;
   if(*head !=NULL)
    temp->next = *head;
   *head=temp;
}

void Print(Node* head)//Argument As head
{
struct Node* temp =head;
cout<<"List is: "<<endl;
while(head != NULL){
    cout<<head->data<<endl;
    head=head->next;
}
printf("\n");
}

int main()
{
   Node* head = NULL;//empty list
   cout<<"How many numbers??"<<endl;
   int i,x,n;
   cin>> n;
   for(int i=0;i<n;i++){
   cout<<"Enter the number"<<endl;
   cin>>x;
   insert(& head,x);
   Print(head);
   }
}
