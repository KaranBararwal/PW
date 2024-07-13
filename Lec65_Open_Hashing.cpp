#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

class Hashing{
      
      vector <list<int> > hashtable;
      int buckets;

      public:
      // making hashtable which contain buckets 
        Hashing(int size){
            buckets = size;
            hashtable.resize(size);
        }
      
      // function (way) of hashing
      // division method (dividing value with number(bucket_size))
      int hashvalue(int key){
        return key%buckets;
      }

      // inserting the element in bucket according to hashvalue
      void addKey(int key){
        // calculating the index where we have to insert the value
        int idx = hashvalue(key);
        // we need to insert the element at last of linkedlist which is contained by every bucket
        hashtable[idx].push_back(key);
      }
     
     // getting iterator to check if value is present or not
     // it will type of linkedlist

     list<int> :: iterator searchKey(int key){
        // first we need to calculate the index of that bucket which is containig that element hashvalue
        int idx = hashvalue(key);

        // now we'll search for that element in that linkedlist which is contained by element hashvalue wali bucket

        return find(hashtable[idx].begin(), hashtable[idx].end(),key);
        // here hashtable[idx] is returing us the linkedlist of bucket
        // if element is not found then it will return iterator pointing at the end element of linkedlist
     }

     void deleteKey(int key){
       
          int idx = hashvalue(key);

          if(searchKey(key)!=hashtable[idx].end()){ // it means key(element) is present
             hashtable[idx].erase(searchKey(key));
             // it means we'll go to the that bucket of hashtable
             // then delete the element of linkedlist in that bucket
             cout<<key<<" is deleted"<<endl;
          }
          else{
            cout<<"Key is not present in the hashtable"<<endl;
          }
     }

};

int main(){
    Hashing h(10); // 10 buckets

    h.addKey(5);
    h.addKey(9);
    h.addKey(3);
    
    h.deleteKey(3);
    h.deleteKey(3);
    return 0;
}
