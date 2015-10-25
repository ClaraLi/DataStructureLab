//Construct postfix calculator using the STL stack class
#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H
#include <iostream>
#include <stack>

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
        stack<int> Stack;
               
};

#endif
