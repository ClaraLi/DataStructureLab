#include "stack.h"

// constructor
stack::stack()
{
    theStack = new List;
    count = 0;
}

// destructor
stack::~stack()
{
    theStack->makeEmpty();
    delete theStack; 
}

void stack::push(int x)
{
    theStack->insertAtHead(x);
}

void stack::pop()
{
    ListItr first = theStack->first();
    theStack->remove(first.retrieve());
}

int stack::top() const
{   ListItr first = theStack->first();
  //first.moveForward();
    return first.retrieve();
}

bool stack::empty() const
{
    return count < 1;
}
