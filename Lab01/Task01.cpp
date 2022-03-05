#include<iostream>
using namespace std;
int main(){
    int *Array;
    int size;
    //Size
    cout<<"Enter the Array of size"<<endl;
    cin>>size;
    Array = new int[size];
    //taking the value
    cout<<"Enter those element"<<endl;
    for(int i=0;i<size;i++){
        cin>>Array[i];
    }
    for(int i=0;i<size;i++){
        cout<<Array[i]<<" ";
    }
    cout<<endl;
    delete []Array;
}
