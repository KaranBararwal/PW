#include<iostream>
using namespace std;


class Parent{
    public:
      Parent(){
        cout<<"Parent class"<<endl;
      }
       
};

class Child: public Parent{
    public:
    Child(){
        cout<<"Child class"<<endl;
    }
};

class GrandChild: public Child{
    public:
      GrandChild(){
        cout<<"Grandchild class"<<endl;
      }
};

// multiple inheritence
class Parent1{
    public:
      Parent1(){
        cout<<"Parent1 class"<<endl;
      }
       
};
class Parent2{
    public:
      Parent2(){
        cout<<"Parent2 class"<<endl;
      }
       
};
class Child1: public Parent1, public Parent2{
    public:
    Child1(){
        cout<<"Child1 class"<<endl;
    }
};

// hierarchical inheritence

class Parent3{
    public:
      Parent3(){
        cout<<"Parent3 class"<<endl;
      }
       
};

class Child2: public Parent3{
    public:
    Child2(){
        cout<<"Child2 class"<<endl;
    }
};

class Child3: public Parent3{
    public:
    Child3(){
        cout<<"Child3 class"<<endl;
    }
};

// Hybrid inheritence (combination of more than one inheritence)





int main(){
    // single inheritence
   // Child c;
    // first it will access Parent class then it will go to Child class
    
    //multilevel inheritence
   // GrandChild gc;
    
    //multiple inheritence
   // Child1 c1;
   
   // Hierarchical inheritence
   //Child2 c2;
   

    return 0;
}