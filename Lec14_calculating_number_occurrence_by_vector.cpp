#include<iostream>
#include<vector>

using namespace std;

int solve(vector <int> &a , int x){
    int count=0;
    for(int i=0;i<a.size();i++){
     if(x==a[i]){
    count++;
     }
    }
    return count;
}

int main(){
    int n;
    cout<<"enter the size of array"<<endl;
    cin>>n;

    vector<int> v;

    for(int i=0;i<n;i++){
        int p;
        cout<<"enter the "<<i<< " element"<<endl;
        cin>>p;
        v.push_back(p);
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    int x;
    cout<<"enter the number for occurrence";
    cin>>x;
    int count=solve(v,x);
    cout<<"occurrence is "<<count;
}