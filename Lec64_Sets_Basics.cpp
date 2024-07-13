#include<iostream>
#include<set>
using namespace std;

int main(){

    // declartion 
    set <int> set1;
    // for printing the values in decreasing order
    set<int, greater<int> > set2;

    // inserting 
    set1.insert(3);
    set1.insert(2);
    set1.insert(1);

    cout<<set1.size()<<endl;

    set1.insert(3);
    
    cout<<set1.size()<<endl;
    //size remains the same because duplicate value is added
    // setcontains only unique value
    
    // iterator is used for pointing at position in sets
    // declartion

    set<int>::iterator itr;

    // set.begin() points to the position of first element
    // set.end() points to the position after the last element

    for(itr = set1.begin(); itr!=set1.end();itr++){   // here we can write auto itr then we don't need to declare the iterator
        cout<<*itr<<" "; // cuz it points at position (pointer concept)
    }
    cout<<endl;

    set1.insert(4);
    set1.insert(5);

    // for each loop
    for(auto value:set1){
        cout<<value<<" ";
    }
    cout<<endl;

    //deletion
    cout<<"delete by value"<<endl; 
    set1.erase(4);  // it deletes the value not the position
      for(auto value:set1){
        cout<<value<<" ";
    }
    cout<<endl<<"delete by position"<<endl;
      
      set1.insert(4);
    auto Itr = set1.begin();
      advance(Itr,3);
      set1.erase(Itr);
    
    for(auto value:set1){
        cout<<value<<" ";
    }
    cout<<endl;
    
     set1.insert(4);

    cout<<"deleting elements in a range"<<endl;
    /* here elements are deleted of range including start_ptr element , excluding end_ptr element
    */
    auto start_itr = set1.begin();
    start_itr++; // pointing at second element

    auto end_itr = set1.begin();
    advance(end_itr,3); // range limit

    set1.erase(start_itr,end_itr);

    for(auto value:set1){
        cout<<value<<" ";
    }
    cout<<endl;
    set1.insert(2);
    set1.insert(3);
   

    // find()  member function
    // it will return the pointer to the element if it is present
    // otherwise it will return the end pointer

    if(set1.find(4)!=set1.end()){
         cout<<"value is present"<<endl;
    }
    else{
      cout<<"value is not present"<<endl;
    }
    
    // lower_bound()
    // return itreator if element is present
    // else returns just greater value

    // upper_bound()
    // return the next greater value
     return 0;
}