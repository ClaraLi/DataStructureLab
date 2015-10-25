//Construct postfix calculator using the STL stack class
#include "postfixCalculator.h"


void postfixCalculator::number(int x){
  Stack.push(x);
}
void postfixCalculator::add(){
 
    int number2 = Stack.top();
    Stack.pop();
    int number1 = Stack.top();
    Stack.pop();
    int temp = number1 + number2;
    Stack.push(temp);
}
void postfixCalculator::subtract(){
 
    int number2 = Stack.top();
    Stack.pop();
    int number1 = Stack.top();
    Stack.pop();
    int temp = number1 - number2;
    Stack.push(temp);

}
void postfixCalculator::multiply(){
 
   int number2 = Stack.top();
    Stack.pop();
    int number1 = Stack.top();
    Stack.pop();
    int temp = number1 * number2;
    Stack.push(temp);

}
void postfixCalculator::divide(){

    int number2 = Stack.top();
    Stack.pop();
    int number1 = Stack.top();
    Stack.pop();
    int temp = number1 / number2;
    Stack.push(temp);

}
void postfixCalculator::negate(){
  int temp = Stack.top();
  Stack.pop();
  temp *= -1;
  Stack.push(temp);
}

int postfixCalculator::result(){
  return Stack.top();
}
