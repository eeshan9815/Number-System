#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
using namespace std;
//Function to display n in a given  base b
void convertBase(int n, int b)
{
  if(b==8)
    cout<<oct<<n;
  else if(b==16)
    cout<<hex<<n;
  else if(b==10)
    cout<<dec<<n;
  else if(b==2)
    cout<<bitset<16>(n);
  cout<<endl;
}
//Menu-driven execution class
class Run
{
private:
  int history_size;
  int sno;
  std::vector<string> history;
  std::vector<System *> list;    //vector to store the numbers
public:
  Run(){history_size=0;sno=0;menu();}
  void menu()
  {
    while(1)
      {
	std::cout<<"Choose an option: 1.Enter a new number\t2.List all existing numbers\t3.Manipulate history\t4.Perform the desired operation on two numbers\t-1.Quit     ";
	int driver;
	std::cin>>driver;
	if(driver == 1)
	  {
	    cout<<"Choose a base: 1.Decimal\t2.Binary\t3.Octal\t4.Hex:    ";
	    int n;
	    int base;
	    cin>>base;
	    if(base==BIN)
	      {
		cout<<"Enter the number: ";
		cin>>dec>>n;
		list.push_back(new Binary(n));
	      }
	    else if(base==DEC)
	      {
		cout<<"Enter the number: ";
		cin>>dec>>n;
		list.push_back(new Decimal(n));
	      }
	    else if(base==OCT)
	      {
		cout<<"Enter the number: ";
		cin>>oct>>n;
		list.push_back(new Octal(n));
	      }
	    else if(base==HEX)
	      {
		cout<<"Enter the number: ";
		cin>>hex>>n;
		list.push_back(new Hex(n));
	      }
	     
	  }
	else if(driver == 2)
	  {
	    for(int i=0; i<list.size(); i++)
	      {
		std::cout<<i+1<<". ";
		list[i]->Display();
		std::cout<<'\n';
	      }
	     
	  }
	else if(driver == 3)
	  {
	    cout<<"Enter: 1 to display history\t2 to delete a record\t3 to delete the entire file:    ";
	    std::ifstream fin("history.txt");
	    int hist_no;
	    cin>>hist_no;
	    if(hist_no==1)
	      {
		int i=1;
		for (std::string line ; std::getline(fin, line); i++)
		  {
		    std::cout << i << ". "<<line << std::endl;
		  }
	      }
	    else if(hist_no==2)
	      {
		cout<<"Enter line number to delete: ";
		int lineNo;
		cin>>lineNo;
		ofstream fout1("temp.txt");
		int i=1;
	   	for (std::string line ; std::getline(fin, line); i++)
		  {
		    if(i==lineNo)
		      continue;
		    fout1 << line <<'\n'; 
		    
		  }
		fout1.close();
		std::remove("history.txt"); 
		std::rename("temp.txt", "history.txt"); 
		
		
	      }
	    else if(hist_no==3)
	      {
		std::remove("history.txt"); 
				
	      }
	    fin.close();
	  }
	else if(driver == 4)
	  {
	    for(int i=0; i<list.size(); i++)
	      {
		std::cout<<i+1<<". ";
		list[i]->Display();
		std::cout<<'\n';
	      }
	    std::cout<<"Enter the serial numbers of the two numbers to perform the operation on: ";
	    int n1, n2;
	    std::cin>>n1>>n2;
	    ofstream fout("history.txt", ios::app);
	    n1--;n2--;
	    list[n1]->History(fout);
	    fout<<" and ";
	    list[n2]->History(fout);
	    //list[n1]->Display();
	    //list[n2]->Display();
	    std::cout<<"Enter the base in which you want the output to be:(Among 2, 8, 10, 16) ";
	    int b;
	    std::cin>>dec>>b;
	    std::cout<<"Enter: 1. Addition\t2. Subtraction\t3. Multiplication\t4. Integer Division:    ";
	    int j;
	    std::cin>>j;
	    if(j==1)
	      {
		cout<<"This evaluates to: ";
		convertBase((*(list[n1]))+(*(list[n2])), b);
		fout << " (+) = ";
		fout << ((*(list[n1]))+(*(list[n2])));
	      }
	    else if(j==2)
	      {
		cout<<"This evaluates to: ";
		convertBase((*(list[n1]))-(*(list[n2])), b);
		fout << " (-) = ";
		fout << ((*(list[n1]))-(*(list[n2])));
	      } 
	    else if(j==3)
	      {
		cout<<"This evaluates to: ";
		convertBase((*(list[n1]))*(*(list[n2])), b);
		fout << " (*) = ";
		fout << ((*(list[n1]))*(*(list[n2])));
	      }
	    else if(j==4)
	      {
		cout<<"This evaluates to: ";
		convertBase((*(list[n1]))/ (*(list[n2])), b);
		fout << " (/) = ";
		fout << ((*(list[n1]))/(*(list[n2])));
	      }
	    else
	      {
		std::cerr<<"Invalid Operation\n";
		 
	      }
	    cout<<'\n';
	    fout<<'\n';
	    fout.close();
	    // history_size ++;
	    // sno ++;
	  }
	else if (driver==-1)
	  {
	    for(int i=0; i<list.size();i++)
	      delete list[i];
	    return;
	  }
	
      }
  }
};
