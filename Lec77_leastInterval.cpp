#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

int leastInterval(vector<char> tasks , int n){

    //1. cout freq of tasks
    unordered_map<char ,int> taskFreq;
    for(auto t: tasks){
        taskFreq[t]++;
    }

    //2. insert frequency into max heap
    priority_queue<int> pq;
    for(auto e : taskFreq){
        pq.push(e.second);
    }

    //3. finding time untill pq is empty
    int totalTime =0;
    while(!pq.empty()){

        vector<int> temp;
        // looping ine time frame = (n+1) units of time
        for(int i=0;i<=n;i++){

            if(!pq.empty()){
                int freq = pq.top();
                pq.pop();

                if(freq>1){
                    temp.push_back(freq-1); // adding remaining tasks in temp vector
                }
            }

            totalTime++;

             if(pq.empty() && temp.empty()){
            return totalTime ; // all tasks have been executed
        }      
        }

        for(auto t : temp){
            pq.push(t); // adding back remaining tasks from temp vector to pq
        }
    }

    return totalTime;
}

int main(){
    int n;
    cout<<"enter the number of tasks "<<endl;
    cin>>n;

    vector<char> tasks(n);
    cout<<"enter the tasks "<<endl;
    for(int i=0;i<n;i++){
        cin>>tasks[i];
    }

    int cooldown;
    cout<<"enter the cooldown time "<<endl;
    cin>>cooldown;
    
    int leastTime = leastInterval(tasks , cooldown);
    cout<<"Least Number of units of time: "<<leastTime <<endl;

    return 0;
}