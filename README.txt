TASK 2: Number System Program Using OOP Concepts in C++
-Eeshan Gupta 16CS30009

Documentation:
There is a base class 'System' which is designed to be abstract and has virtual member functions, which the classes that derive from it can give their own definition to. But, pointers to the base class can call those functions and hence become a powerful tool for object oriented programming.

The operators '+', '-', '*', '/' have been overloaded to work on the 'System' class.

An enumeration called 'Bases' holds the four bases as integer values for better readability.

The history is written to a file named 'history.txt' and can be read and manipulated with.

There are separate header files for different fuctionality for better organization.

Functionality, and how to run the code: 
The program is designed to have a command-line interface.
The class 'Run' handles a menu-driven scheme to perform various actions.
All functionality is attatched in a screenshot

Enter 1 to enter a new number, choose a base and then enter the number in that base.
Enter 2 to display a list of all numbers entered during this runtime.
Enter 3 to look at and manipulate history of operations. The history isn't deleted after a particular runtime.
      Within this, Enter 1 to View History, 2 to delete a specific row-number from the history and 3 to delete the entire history.
Enter 4 to perform operations. The user can select the base in which he/she wants the resultant number to be displayed. To perform an operation, first choose the serial numbers of the two number, then the resultant base, and finally the operation.

Enter -1 to exit and deallocate the memory used by the Numbers stored.