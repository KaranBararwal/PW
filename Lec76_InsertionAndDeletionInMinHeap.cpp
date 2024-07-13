#include<iostream>
using namespace std;

// making array size constant so we don't have to change it after insertiom
int const N = 1e3 ;// 1000

void insertMinHeap(int arr[] , int & size , int value){

    size++;
    // inserting the value at the last position
    arr[size] = value;

    int curr = size; // it will track the position

    while( (curr/2) > 0 && arr[curr/2] > arr[curr]){   // curr/2 > 0 is for checking it has reached to root or not
              swap(arr[curr] , arr[curr/2]);
              curr = curr/2 ;
    }
     
}

void deletionMinHeap( int arr[] , int &size){

    // we can only delete at root 
    arr[1] = arr[size];
    size--;
    int curr = 1;

    while( 2*curr <= size ){   // it means it have child
        
        int leftChild = 2*curr;
        int rightChild = 2*curr+1;
        int minChild = leftChild;
        if(rightChild<=size && arr[rightChild] < arr[leftChild]){
            minChild = rightChild;
        }

        if(arr[minChild] >= arr[curr])  {// it means node have greater value then its child
             return;
    } 
        
        // if it is not the case then we need to swap the value
        swap( arr[curr] , arr[minChild]);
        curr = minChild;   // index in array 
    }
}

int main(){

    int minHeap[N] = {-1 , 10 , 20 , 30 , 40 , 50 };  // making 0 index element equal to -1
    int size = 5;

    int value = 5; // value to be inserted

        for(int i =0 ;i<=size ; i++){
        cout<<minHeap[i]<<"  ";
    } cout<<endl;

    insertMinHeap(minHeap , size , value);

    for(int i =0 ;i<=size ; i++){
        cout<<minHeap[i]<<"  ";
    }cout<<endl;

    deletionMinHeap( minHeap , size);
    for(int i =0 ;i<=size ; i++){
        cout<<minHeap[i]<<"  ";
    }  
    return 0;
}