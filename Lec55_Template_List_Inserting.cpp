#include<iostream>
#include<list>
using namespace std;

int main(){

    list <int> l = {1,2,3,4};

    auto itr = l.begin();

     for(auto itr = l.begin(); itr!=l.end();itr++){
       cout<<*itr<<" ";
    }
    cout<<endl;

     advance(itr,2);

   // l.insert(itr,5);
    // it will insert element before the element where itr is pointing
    // for(auto itr = l.begin(); itr!=l.end();itr++){
    //    cout<<*itr<<" ";
    // }
    // cout<<endl;


    // l.insert(itr,3,5);

    //  for(auto itr = l.begin(); itr!=l.end();itr++){
    //    cout<<*itr<<" ";
    // }
    // cout<<endl;

    auto s = l.begin();
    auto r = l.begin();
    
    advance(r,2); // now r is pointing to 3

    l.insert(itr,s,r);

      for(auto itr = l.begin(); itr!=l.end();itr++){
       cout<<*itr<<" ";
    }
    cout<<endl;
    
    // 1 2 1 2 3 4
    auto s_itr = l.begin();
    advance(s_itr,2); // s_itr is pointing to 3rd elementn (1 here)

    auto e_itr = l.begin();
    advance(e_itr,4); // e_itr is pointing to 5th element (3 here)
    
    l.erase(s_itr,e_itr);
     // it will delete elements from start pointer to end pointer (not end pointer element)
           for(auto itr = l.begin(); itr!=l.end();itr++){
       cout<<*itr<<" ";
    }
    cout<<endl;
   
    }