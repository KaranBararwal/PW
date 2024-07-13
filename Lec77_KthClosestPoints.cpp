#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector <pair <int,int> > kClosestPoints(vector<pair<int , int> > pts , int size , int k){

    priority_queue< pair <int ,pair <int, int> > > pq; // max heap

    for( auto & pt : pts){
        // manhatten distance
        int distance = pt.first + pt.second;   // here we should use abs for absoulute value
        // pushing distance into priority queue
        pq.push(make_pair(distance , pt));

        if(pq.size() > k){
            pq.pop();   // remove largest distance pt in (k+1) pts
        }
    }
   
    vector<pair<int , int> > ans(k);
    while(!pq.empty()){
        // cuz bigest distance is at the root so we need to insert biggest element at the last
        ans[pq.size() - 1] = pq.top().second;   
        pq.pop();
    }

    return ans;
}
int main(){

    int n , k;
    cout<<"enter the number of points "<<endl;
    cin>>n;
    cout<<"enter how many closest pair u need "<<endl;
    cin>>k;
    cout<<"enter the value of all pairs "<<endl;
    vector <pair <int , int> > pts(n);

    for(auto &pt : pts){
        cin >> pt.first >> pt.second;
    }

     vector <pair <int , int> > anspts = kClosestPoints(pts , n ,k);
    
    cout<<k<<" closest pairs are "<<endl;
    for(auto &pt : anspts){
        cout<< pt.first << "  " <<pt.second <<" \n";
    }
    return 0;
}