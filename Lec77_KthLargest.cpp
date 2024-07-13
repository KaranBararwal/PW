#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int KthLargestElement(vector <int> v , int size , int k){
    // first we'll create a min heap of size k (which largest value we need)

    priority_queue<int , vector<int> , greater <int> > pq;

    // now we'll push the vector elements in priority queue
    for(int i =0 ;i<size ;i++){
        pq.push(v[i]);
        
        // if the size of queue is greater then k then we'll remove the smallest value from heap which is at the root (top)
        if(pq.size() > k ){
            pq.pop(); // removing the smallest element out of k+1 elements
        }
    }

    return pq.top(); // it will be the Kth largest element
}

int main(){
    int n;
    cout<<"enter the size of vector "<<endl;
    cin>>n;
    
    vector<int> v(n);
    cout<<"enter "<<n<<" elements "<<endl;
    for(int i=0 ;i<n ;i++){
        cin>>v[i];
    }
    
    int k;
    cout<<"enter which largest value u need to find "<<endl;
    cin>>k;

    cout<<k<<"th largest element is "<<KthLargestElement(v,n,k);
}