#include <iostream>
#include "List.h"
using namespace std;
#include "ListNode.h"
#include "ListItr.h"
//Constructor
List::List(){
    head = new ListNode;
    tail = new ListNode;
  
    head -> previous = NULL;
    head -> next = tail;
    tail -> previous = head;
    tail -> next = NULL;
    
    count = 0;  
}				

//Copy Constructor This will create a new list of ListNodes 
//whose contents are the same values as the ListNodes in source.
List::List(const List& source){
    head = new ListNode;
    tail = new ListNode;
    
    head -> next = tail;
    tail -> previous = head;
    count = 0;
    ListItr iter(source.head -> next);
    while (!iter.isPastEnd()) {       // deep copy of the list
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}
//Destructor
List::~List(){	
    makeEmpty();
    delete head;
    delete tail;
}

//Equals Operator
List& List::operator=(const List& source) { //Equals operator
    if (this == &source)
        return *this;
    else {
        makeEmpty();
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}


//Returns true if empty; else false
bool List::isEmpty() const{
    return count == 0;
}
//Removes all items except blank head and tail
void List::makeEmpty(){  

   ListItr *l = new ListItr(first());
    while (!l -> isPastEnd()) {
    delete l -> current;
    l -> moveForward();
    }
    head -> next = tail;
    tail -> previous = head;
    count = 0;
}	
//Returns an iterator that points to the ListNode in the first position
ListItr List::first(){
    ListItr *l = new ListItr(head -> next);
    l -> current -> previous = head;
    return *l;
}	
//Returns an iterator that points to the ListNode in the last position
ListItr List::last(){
    ListItr *l = new ListItr(tail -> previous);
    l -> current -> next = tail;
    return *l;
}			

//Inserts x after current iterator position p
void List::insertAfter(int x, ListItr position){
    ListNode *l = new ListNode;
    l -> value = x;
    l -> previous = position.current;
    l -> next = position.current -> next;
    
    position.current -> next -> previous = l;
    position.current -> next = l;
    
    count++;
    
 }   

 //Inserts x before current iterator position p
void List::insertBefore(int x, ListItr position){
    ListNode *l = new ListNode;
    l -> value = x;
    l -> previous = position.current -> previous;
    l -> next = position.current;
    position.current -> previous -> next = l;
    position.current -> previous = l;
    
    
    count++;
}    
    
//Insert x at tail of list
void List::insertAtHead(int x){
    ListNode *l = new ListNode;
    l -> value = x;
    l -> previous = head ;
    l -> next = head -> next;
   
    head -> next -> previous = l;
    
    head -> next = l;
    
    count++;
}

void List::insertAtTail(int x){
    ListNode *l = new ListNode;
    l -> value = x;
    l -> previous = tail -> previous;
    l -> next = tail;
   
    tail -> previous -> next = l;
    
    tail -> previous = l;
    
    count++;
}

//Removes the first occurrence of x
void List::remove(int x){
    ListItr *l = new ListItr(find(x));

    if (!l->isPastEnd())
    {
         l -> current -> previous -> next = l -> current -> next;
         l -> current -> next -> previous = l -> current -> previous;
         count -= 1;

    }    
 }  
//Returns an iterator that points to
// the first occurrence of x, else return a iterator to the dummy tail node

ListItr List::find(int x){

    ListItr *l = new ListItr(head -> next);
   
    while (!l -> isPastEnd()) {
    
        if (l -> current -> value == x) {
            return *l;
        }
        else {
        l -> moveForward();
        }
    }
  //  l -> current -> next = tail;
    return *l;    
}

//Returns the number of elements in the list
int List::size() const{
    return count;
    } 


void printList(List& source, bool direction)
{
    
    if (direction)
    {        
        ListItr *l = new ListItr(source.first());
        while (!l -> isPastEnd()) 
        {
            cout << l -> retrieve() << "  ";
            l -> moveForward();
        }
    }
    else
    {

        ListItr *l = new ListItr(source.last());
        while (!l -> isPastBeginning())
        {
            cout << l -> retrieve() << "  ";
            l -> moveBackward();
        }
    }
    
}
