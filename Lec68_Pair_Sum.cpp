#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> targetSumPair(vector<int> v , int target){

    // Time Complexity --> O(n)
    // n is size of the vector

    // Space Complexity --> array + map
    unordered_map<int,int> m;
    vector<int> result(2,-1);

    for(int i = 0 ; i < v.size() ; i++){
        if(m.find(target - v[i]) != m.end()){
            // first index of element
            result[0] = m[target-v[i]];
            // second index
            result[1] = i;
            return result;
        }
        else{
            m[v[i]] = i;
        }
    }
    return result;
}

int main(){
    int n;
    cout<<"enter the size of vector "<<endl;
    cin>>n;

    vector<int> v(n);
    cout<<"enter elements "<<endl;
    for(int i = 0 ; i < n ; i++){
        cin>>v[i];
    }

    int t;
    cout<<"enter the target sum we need "<<endl;
    cin>>t;

    vector<int> ans = targetSumPair(v,t);
    cout<<"indexes of the target sum are "<<ans[0]<<" and "<<ans[1]<<endl;
}