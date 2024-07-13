#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int> &v, int x){
int index=-1;
for(int i=0;i<v.size();i++){
    if(v[i]==x){
        index=i;
    }
    
}
return index;
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

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    int a;
    cout<<"enter element for checking index"<<endl;
    cin>>a;
    int ind=solve(v,a);
    cout<<"last index of thr number is "<<ind;
}
   