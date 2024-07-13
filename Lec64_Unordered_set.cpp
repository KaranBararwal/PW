#include<iostream>
#include<unordered_set>
using namespace std;

int main(){

    unordered_set<int> s1;

    s1.insert(3);
    s1.insert(1);
    s1.insert(2);
    s1.insert(1);

    for(auto value : s1){
        cout<<value<<" ";
    }
    cout<<endl;

    // Time complexity
    // 1. Insert
    // single element O(1)-> average
    //                O(N)-> worst

    // multiple element O(n)-> average (n is no. of elements being inserted)
    //                  O(n*(N+1))-> worst (N is size of unordered_set)


    // unordered_multiset
    unordered_multiset<int> ms; // allows duplicate value (ordered set)
    ms.insert(4);
    ms.insert(8);
    ms.insert(3);
    ms.insert(1);
    ms.insert(4);

    for(auto value : ms){
        cout<<value<<" ";
    }cout<<endl;

  
}