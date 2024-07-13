#include<iostream>
#include<vector>
using namespace std;

int equalSum(vector <int> &v,int n){

int totalSum=0;

for(int i=0;i<n;i++){
  totalSum+=v[i];
}

cout<<"total sum is "<<totalSum<<endl;
int prefixSum=0;
int sufixSum=0;
for(int i=0;i<n;i++){

prefixSum+=v[i];
sufixSum=totalSum-prefixSum;

if(sufixSum==prefixSum){

cout<<"at "<<i<< " index preifix sum equal to sufix sum";
}

}

}

int main(){
  int n;
  cout<<"enter the size of array "<<endl;
  cin>>n;

  vector <int> v;

  for(int i=0;i<n;i++){
    int p;
    cout<<"enter "<<i<<" element"<<endl;
    cin>>p;
    v.push_back(p);
  }


  equalSum(v,n);
}