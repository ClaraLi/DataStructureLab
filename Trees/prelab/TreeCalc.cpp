////////
// Clara Li
// jl2qp
// TreeCalc.cpp
// 10/12/2015
////////
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations
// using a stack to help you read in a postfix expression into an expression tree
// Sample execution run
/*
 Enter elements one by one in postfix notation
 Any non-numeric or non-operator character, e.g. #, will terminate input
 Enter first element: 34
 Enter next element: 6
 Enter next element: +
 Enter next element: -8
 Enter next element: 4
 Enter next element: /
 Enter next element: -
 Enter next element: #
 Expression tree in postfix expression: 34 6 + -8 4 / -
 Expression tree in infix expression: ((34 + 6) - (-8 / 4))
 Expression tree in prefix expression: - + 34 6 / -8 4
 The result of the expression tree is 42 
*/

#include "TreeCalc.h"
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <string>
using namespace std;

//Constructor
TreeCalc::TreeCalc() {
}

//Destructor- frees memory
TreeCalc::~TreeCalc() {
 
  cleanTree(mystack.top());
  
}

//Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* ptr) {
    if(ptr == NULL){
        return;
    }
    cleanTree(ptr -> left);
    cleanTree(ptr -> right);
    delete ptr;
}

//Gets data from user
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0]=='/' || response[0]=='*'
            || response[0]=='-' || response[0]=='+' ) {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

//Puts value in tree stack
void TreeCalc::insert(const string& val) {
    // insert a value into the tree

  
     if (val == "+"||val == "-"||val == "*"||val == "/"){

       TreeNode *node = new TreeNode(val);
       node->right = mystack.top();
       mystack.pop();
       node->left = mystack.top();
       mystack.pop();
       mystack.push(node);
       
     }
     
     else{ 
       TreeNode *node = new TreeNode(val);
       mystack.push(node);
     }
   
   

  
}

//Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* ptr) const {
  if (ptr == NULL){
    return ;
  }
  cout << ptr->value <<" ";
  printPrefix(ptr->left);
  printPrefix(ptr->right);
  
}

//Prints data in infix form
void TreeCalc::printInfix(TreeNode* ptr) const {
    // print tree in infix format with appropriate parentheses
   
    if (ptr->left== NULL|| ptr->right==NULL){
      cout<<ptr->value<<"";
        return ;
    }
   
    cout <<"("<<"";
    printInfix(ptr->left);
    cout << " " << ptr->value << " ";
    printInfix(ptr->right);
    cout <<")"<<"";
}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* ptr) const {
    // print the tree in postfix form
    if(ptr == NULL){
        return;
    }
    printPostfix(ptr -> left);
    printPostfix(ptr -> right);
    cout << ptr->value << " ";
  
}

// Prints tree in all 3 (pre,in,post) forms

void TreeCalc::printOutput() const {
    if (mystack.size()!=0 && mystack.top()!=NULL) {
        cout << "Expression tree in postfix expression: ";
        // call your implementation of printPostfix()
        printPostfix(mystack.top());
        cout << endl;
        cout << "Expression tree in infix expression: ";
        // call your implementation of printInfix()
	printInfix(mystack.top());
        cout << endl;
        cout << "Expression tree in prefix expression: ";
        // call your implementation of printPrefix()
	printPrefix(mystack.top());
        cout << endl;
    } else
        cout<< "Size is 0." << endl;
}

//Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* ptr) const {
  string str = ptr->value;
      if (ptr->value == "+"){
          return calculate(ptr->left) + calculate(ptr->right);
      }
      else if (ptr->value == "-"){
          return calculate(ptr->left) - calculate(ptr->right);
      }
      else if (ptr->value == "*"){
          return calculate(ptr->left) * calculate(ptr->right);
      }
      else if (ptr->value == "/"){
          return calculate(ptr->left) / calculate(ptr->right);
      }
      else {
	return atoi(str.c_str());
      }    
	    
	    
  // Traverse the tree and calculates the result
}

 
//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
    int i = 0;
    // call private calculate method here
    i = calculate(mystack.top());

    return i;
}
