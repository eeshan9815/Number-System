#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;
//Derived Decimal Class
class Decimal: public System
{
public:
  Decimal(){}
  Decimal(int n) : System (n){}
  void Display() {cout<<dec<<number<<'_'<<10;}
  void History(ofstream& fout) {fout<<dec<<number<<'_'<<10;}
  int getnumber(){return number;}
};
int Bin2Dec(int n)
{
  int decimal_eq=0;
  int temp=n, i=0;
  while(temp!=0)
    {
      decimal_eq+=(temp%10)*pow(2,i);
      temp/=10;
      i++;
    }
  return decimal_eq;
}
//Derived Binary Class
class Binary: public System
{
private:
  int binaryform;
public:
  Binary(){}
  Binary(int n) : System (Bin2Dec(n)){binaryform=n;}
  void Display(){cout<<binaryform<<'_'<< 2 <<" : "<<number;}
  void History(ofstream& fout){fout<<binaryform<<'_'<< 2;}
  int getnumber(){return number;}

};
//Derived Octal Class
class Octal: public System
{
public:
  Octal(){}
  Octal(int n) : System (n){}
  void Display() {cout<<oct<<number<<dec<<'_'<<8<<" : "<<number;}
  void History(ofstream& fout) {fout<<oct<<number<<dec<<'_'<<8<<" : "<<number;}
  int getnumber(){return number;}
};
//Derived Hexadecimal Class
class Hex: public System
{
public:
  Hex(){}
  Hex(int n) : System (n){}
  void Display() {cout<<hex<<number<<dec<<'_'<<16<<" : "<<number;}
  void History(ofstream& fout) {fout<<hex<<number<<dec<<'_'<<16;}
  int getnumber(){return number;}
};
