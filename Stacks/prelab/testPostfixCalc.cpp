//Test file for the postfix calculator
#include <iostream>
#include <cstdlib>
#include <string>
#include "postfixCalculator.h"

class postfixCalculator;

int main(){
  postfixCalculator theStack;

 while(cin.good()){
     string s;
    cin >> s;
    if(s == "+"){
      theStack.add();
    }
    else if(s == "-"){
      theStack.subtract();
    }
    else if(s == "*"){
      theStack.multiply();
    }
    else if(s == "/"){
      theStack.divide();
    }
    else if(s == "~"){
      theStack.negate();
    }
    else if(s=="") continue;
    else{
      theStack.number(atoi(s.c_str()));
    }
 
  }
  cout << "Result:" << theStack.result() << endl;
  return 0;
}
