#include<iostream>
using namespace std;

class sum{
   public:
   void add(int x,int y){
    int sum=x+y;
    cout<<sum<<endl;
   }

   void add(int x, int y, int z){
    int sum= x + y + z;
    cout<<sum<<endl; 
   }

   void add(float x, float y){
    float sum = x + y;
    cout<<sum<<endl;
   }
};

int main(){
    sum s;
    s.add(3,4);
    s.add(3,4,5);
    s.add(float(3.4),float(3.5));// we have to tell that it is float value or it will confuse between two functions
}
