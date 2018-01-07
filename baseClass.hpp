#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
//Abstract Base Class
class System
{
protected:
  // int number;
  //int decimal_eq;
public:
  int number;
  System()
  {
    number=0;
    //decimal_eq=0;
  }
  System(int n)
  {
    number=n;
  }
  //int decimal_eq;
  virtual void Display() =0;
  virtual void History(ofstream& fout) =0;
  virtual int getnumber() =0;
  //virtual int convertDec() =0;
  //virtual void convertBack(int n) =0;

};
//enumeration
enum Base {DEC=1, BIN, OCT, HEX};
