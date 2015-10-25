#include <iostream>
#include "ListItr.h"
using namespace std;

//Constructor

ListItr::ListItr(){  
    current = NULL;
}

//One parameter constructor

ListItr::ListItr(ListNode* theNode){
    current = theNode;
}

//Returns true if past end position in list, else false
bool ListItr::isPastEnd() const{
   // return current -> next -> next == NULL;
   return current -> next == NULL;
}
    
//Returns true if past first position in list, else false  
bool ListItr::isPastBeginning() const{
    return current -> previous == NULL;
}
    
//Advances current to next position in list (unless already past end of list)    
void ListItr::moveForward(){
    if (!isPastEnd()){
    current = current -> next;
    }
    else{
    cout << "Please double check\n" <<endl;
    }
}

//Moves current back to previous position in list (unless already past beginning oflist)
void ListItr::moveBackward(){	
    if (!isPastBeginning()){
    current = current -> previous;
    }
    else{
    cout << "Please double check\n" << endl;
    }
}

//Returns item in current position
int ListItr::retrieve() const{
    return current -> value;
}    	




    
    
    