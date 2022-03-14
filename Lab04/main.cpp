#include<iostream>
#include"unsortedtype.cpp"
#include"unsortedtype.h"
#include<string>
#include<string.h>
#include<bits/stdc++.h>// All header file
#include<list>
using namespace std; //User input and output print
template <class t>  //Gather all info of the .cpp in build in way
void print(UnsortedType<t> u){
    int length = u.LengthIs();
    t value;
    for(int i =0;i<length; i++){
        u.GetNextItem(value);
        cout<< value <<"\t";
    }
    cout<<endl;
}
template <class t>
void Retrieve (UnsortedType<t> u, t value){

    bool b;

    u.RetrieveItem(value, b);
    if(b){
        cout<< "Item found"<<endl;
    }
    else {
        cout<< "Item not found"<<endl;
    }
}
//template <class t>

void checkFull(bool b){
    if(b){
        cout<<"List is full"<<endl;
    }
    else
        cout<<"List is not full"<<endl;
}
int main()
{
  UnsortedType<int> t1;
  t1.InsertItem(5);
  t1.InsertItem(7);
  t1.InsertItem(6);
  t1.InsertItem(9);
  print(t1);

  cout<<t1.LengthIs();
  cout<<endl;

  t1.InsertItem(1);

  print(t1);

  Retrieve(t1,4);
  Retrieve(t1,5);
  Retrieve(t1,9);
  Retrieve(t1,10);

  checkFull(t1.IsFull());
  t1.DeleteItem(5);
  checkFull(t1.IsFull());
  t1.DeleteItem(1);
  print(t1);

  t1.DeleteItem(6);
  cout<<"List after delete 6:";
  print(t1);

}
