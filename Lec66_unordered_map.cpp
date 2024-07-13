#include<iostream>
#include<unordered_map>
using namespace std;

int main(){

    unordered_map <int , string> record; // stores in random order
    // roll no. and name

    record.insert(make_pair(3,"ria"));
    record[1]= "ankit";
    record[2] = "bala";

    // if we write in square bracket then value will get updated

    record[3] = "piya";

    // if we write in insert function then nothing happen

    record.insert(make_pair(2,"lala"));


   for(auto pair : record){
       cout<<"Roll No.->"<<pair.first<<endl;
       cout<<"Name-> "<<pair.second<<endl;
   }

   return 0;
}