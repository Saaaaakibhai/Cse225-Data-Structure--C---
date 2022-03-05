#include<iostream>
#include "circle.h"
using namespace std;
circle::circle()
{
    radius=0.0;
}
void circle::store(double r){
radius = r;
}
double circle::area()
{
return 3.14*radius*radius;
}
void circle::display(){
cout<<"r= " <<radius<<endl;
}
void display(double r){
cout<<r<<endl;
}
