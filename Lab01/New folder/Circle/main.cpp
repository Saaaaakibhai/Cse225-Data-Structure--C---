#include<iostream>
#include "circle.h"
using namespace std;
int main(void){
    circle c;
    c.store(5.0);
    cout<<"The area of circle s is "<<c.area()<<endl;
    c.display();
    display(50);
}
