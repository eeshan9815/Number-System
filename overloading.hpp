#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
//Operator Overloading
template <class T1, class T2>
int operator+(const T1& a, const T2& b)    //Addition
{
  return a.number + b.number;
}
template <class T1, class T2>
int operator-(const T1& a, const T2& b)    //Subtraction
{
  return a.number - b.number;
}
template <class T1, class T2>
int operator*(const T1& a, const T2& b)    //Multiplication
{
  return a.number * b.number;
}
template <class T1, class T2>
int operator/(const T1& a, const T2& b)    //Integer Division
{
  return a.number / b.number;
}
