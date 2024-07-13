#include<iostream>
#include<vector>
#include<queue>
using namespace std;

float findMedian(vector <int> data , int size){
    // creating min heap and max heap
    // storing first lower half in max heap and upper half in min heap
    // median is equal to highest value of lower half + lowest value of upper half divide by 2 (size is even)
    // for odd size we'll get only highest value of lower half max heap

    priority_queue<int> maxpq; // for storing lower half of stream
    priority_queue<int , vector<int> , greater<int>> minpq; // for storing greater half of stream
    
    // inserting elements
    for(int i =0;i<size;i++){
        if(maxpq.empty() || data[i] <= maxpq.top()){
            maxpq.push(data[i]);
        }
        else{
            minpq.push(data[i]);
        }

        // rebalance the pq
        if(maxpq.size() > minpq.size()+1){
            minpq.push(maxpq.top());
            maxpq.pop();
        }
        else if(minpq.size() > maxpq.size()){
            maxpq.push(minpq.top());
            minpq.pop();
        }
    }
    
    // finding median
    if(minpq.size() == maxpq.size()){  // even elements
        return (minpq.top() + maxpq.top()) / 2.0;
    }
    else{
        // odd elements
        return maxpq.top();
    }
}

int main(){
    int n;
    cout<<"enter the size of data stream "<<endl;
    cin>>n;

    vector<int> data(n);
    cout<<"enter the data stream "<<endl;

    for(int i=0;i<n;i++){
        cin>>data[i];
    }

    float median = findMedian(data ,n);
    cout<<"the median is "<<median<<endl;
    return 0;
}