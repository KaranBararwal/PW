#include<iostream>
#include<string>
using namespace std;

/*
 // declartion of class
class Fruit{
public: // if we want to access we need to make it public
    string name;
    string color;

};
*/

//2. constructo
    
     class Rectangle{
        public:
        int l;
        int b;

        Rectangle(){ // default constructor - no args passed
            l=0; 
            b=0;

        }
        Rectangle(int x,int y){ // parameterised constructor - args pass
            l=x;
            b=y;
        }
        Rectangle( Rectangle &r){ // copy constructor - initialise an object by another existing object
            l=r.l;
            b=r.b;
        }
         ~Rectangle(){  // Destructor
          cout<<"Destructor is called "<<endl;
     }
     };
     


int main(){
    /*
    // accessing the class
    Fruit apple; // object
    apple.name = "Apple";
    apple.color = "Red";
    cout<<apple.name<<" - "<<apple.color<<endl;

    // another way of declaring 

    Fruit *mango = new Fruit();
    mango->name = "Mango";
    mango->color = "Yellow";
    cout<<mango->name<<" - "<<mango->color<<endl;

    */

   
   //2. constructor
   Rectangle r1;
   cout<<r1.l<<"  "<<r1.b<<endl;
   
   
   Rectangle *r11= new Rectangle();
   cout<<r11->l<<"  "<<r11->b<<endl;
   // Destructor
   delete r11; // it only can be used in pointer object

   Rectangle r2(3,4);
   cout<<r2.l<<"  "<<r2.b<<endl;

   Rectangle r3(r2);
   // Rectangle r3=r2;
   cout<<r3.l<<"  "<<r3.b<<endl;

   
   

    return 0;
}

