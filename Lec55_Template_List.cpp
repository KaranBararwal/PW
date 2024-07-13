#include<iostream>
#include<list>
using namespace std;

int main(){

    list <int> l1 = {1,2,3,4};
   // list<int> :: iterator itr;
   auto itr = l1.begin();

   // l1.end() - iterator pointing to the memory location after 4
   cout<<*itr<<endl; // here itr stores the address of l1.begin()

   advance(itr,2);
   cout<<*itr<<endl;

   for(auto num: l1){
    cout<<num<<"->";
   }
   cout<<endl;
   
   cout<<"By iterators "<<endl;
   //using iterators
   for(auto Itr = l1.begin(); Itr!=l1.end(); Itr++){
    cout<<*Itr<<" ";
   }
   cout<<endl;

   //reverse traversal
   cout<<"By reverse traversal"<<endl;
   for(auto itr = l1.rbegin(); itr!=l1.rend(); itr++){
       cout<<*itr<<" ";
   }
   cout<<endl;

   return 0;
}