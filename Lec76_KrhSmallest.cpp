#include<iostream>
using namespace std;
int const N = 1e3;

void heapify(int arr[] , int size , int curr){

    while( 2*curr + 1 < size) { // 0 base indexing
    
       int leftChild = 2*curr + 1;
       int rightChild = 2*curr + 2;
       int minChild = leftChild;

       if(rightChild < size && arr[leftChild] > arr[rightChild]){
        minChild = rightChild;
       }

       if(arr[curr] <= arr[minChild]){
        return;
       }

       swap(arr[curr] , arr[minChild]);
       curr = minChild;
}
}

void remove(int arr[] , int &size){

    arr[0] = arr[size-1];
    // we overwrite the first index value by last index value and reduce the size buy one
    // and after that again heapify the tree

    for(int i = size/2-1 ; i>=0 ; i--){
        heapify(arr , size ,0); // 0 base indexing
    }
}

int KthSmallestElement( int arr[] , int size , int k ){
     
     // 1. creating the min Heap
     for(int i = size/2-1 ; i>=0 ;i--){  // cuz it is 0 base indexing
          heapify(arr , size , i);
     }

     // 2. removing (k-1) elements
     k-=1; // k = k -1
     while(k--){
        remove(arr , size);
     }
      
      // now we have remain the kth greatest element at top
     return arr[0];
}

int main(){
    
    // here we are doing 0 base indexing
    int arr[N] = {60 , 10 , 80 , 50 , 5 , 20 , 70 };
    int size = 7;
    
    cout<<KthSmallestElement(arr , size ,3)<<endl;;
}