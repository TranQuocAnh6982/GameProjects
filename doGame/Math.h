#ifndef MATH_H_INCLUDED
#define MATH_H_INCLUDED

#include<iostream>
using namespace std;
struct Vector2f{
    double x, y;
Vector2f():x(0.0f), y(0.0f){}
Vector2f(double _x, double _y ): x(_x),y(_y){}
void print(){
cout<<x<<", "<<y<<endl;
}
};

#endif // MATH_H_INCLUDED
