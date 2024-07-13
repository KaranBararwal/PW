#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue <int> qu;
    qu.push(1);
    qu.push(2);
    qu.push(3);
    qu.push(4);
    qu.pop();
    qu.push(5);

    while(not qu.empty()){
        cout<<qu.front()<<"  ";
        qu.pop();
    }

    return 0;
}