#include<iostream>
#include<vector>
using namespace std;

class Queue {
    int front;
    int back;
    vector <int> v;
    
    public:
    Queue(){
        front = -1;
        back = -1;

    }

    void enqueue(int data){
        v.push_back(data);
       
        back++;
        // back = -1+1; // for empty queue
        if(back == 0){ // if it was a empty queue 
            front = 0;    
        }
         return;
    }

    void dequeue(){
        if(front == back == -1){ // empty queue
           cout<<"Underflow"<<endl;
           return;
        }
        if(front == back){ // single element
           front = -1;
           back = -1;
           // here we need to clear the previous vector otherwise when we'll do (front+1) value it will give the same output
           v.clear(); 
        }
        else{
            front++; // we'll just left the access no need for specific deletion
        }
    }

    int getFront(){
        if(front == -1){
            return -1;
        }
        return v[front];
    }

    bool isEmpty(){
        return front == -1;
    }
};

int main(){
    Queue qu;
    qu.enqueue(1);
    qu.enqueue(2);
    qu.enqueue(3);
    qu.enqueue(4);
    
    qu.dequeue();
    qu.enqueue(5);
    //  qu.dequeue();
    //   qu.dequeue();
    //    qu.dequeue();
    //     qu.dequeue();
    //      qu.enqueue(6);


    while(not qu.isEmpty()){
         cout<<qu.getFront()<<endl;
         qu.dequeue();
    }
    return 0;
}