#ifndef _circle_h_

#define _circle_h_

class circle{
private:
    double radius;
public:
    circle();
    void store(double);
    double area();
    void display();
};
void display(double r);
#endif
