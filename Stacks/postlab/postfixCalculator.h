//Construct postfix calculator without STL stack class
//Stack class was implemented using double linked list
#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H
#include <iostream>
#include "stack.h"

using namespace std;

class postfixCalculator {
    public:
  
       	void number(int x);         
        void add();                 
        void subtract();            
        void multiply();            
        void divide();
	void negate();
        void fail();              
        int result();             
 private:
        stack Stack;
               
};

#endif
