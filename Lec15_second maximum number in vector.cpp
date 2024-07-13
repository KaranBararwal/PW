#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int secondmax(vector <int> &v){
    int max=INT_MIN;
    int smax=INT_MIN;

    for(int i=0;i<v.size();i++){
        if(v[i]>max){
            max=v[i];
        }
    }
    
    for(int i=0;i<v.size();i++){
        if(max!=v[i]){
            if(v[i]>smax){
                smax=v[i];
            }
        }
    }
    return smax;
}

int main(){
  
    vector<int> v;
    int n;
    cout<<"enter the size of array"<<endl;
    cin>>n;

    for(int i=0;i<n;i++){
    int p;
    cout<<"enter "<<i<<" element ";
    cin>>p;
    v.push_back(p);
    }
    cout<<"second maximum number is "<<secondmax(v);
}