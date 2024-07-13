#include<iostream>
using namespace std;

int const N = 1e3;

void insertMaxHeap(int arr[] , int &size , int value){

    size++;
    arr[size] = value;

   int  curr = size;

    while( (curr/2) > 0 && arr[curr/2]  < arr[curr]){
        swap(arr[curr] , arr[curr/2]);
        curr = curr/2;
    }
}

int main(){

    int maxHeap[N] = {-1 , 60 , 50 , 40 , 30 , 20 , 10 , 5};
    int size = 7;
    int value = 100;

    for(int i=0 ; i<=size ; i++){
         cout<<maxHeap[i]<<"  ";
    }cout<<endl;

    insertMaxHeap(maxHeap , size , value);

    for(int i=0 ; i<=size ; i++){
        cout<<maxHeap[i]<<"  ";
    }cout<<endl;
}