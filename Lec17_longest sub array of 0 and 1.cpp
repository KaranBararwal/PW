#include<iostream>
#include<vector>
using namespace std;

int maximumSequence(vector <int> &v, int n){

    int zeroNumber=0;
    int oneNumber=0;

    for(int i=0;i<n;i++){

    if(v[i]==0){
        zeroNumber++;
        v[i]=-1;
    }
    }
    
    cout<<"array after making 0 to -1 "<<endl;
    for(int i=0;i<n;i++){
        cout<<v[i]<< "  ";
    }

    cout<<endl;

    int maxSubArray=0;

    for(int i=1;i<n;i++){
     v[i]+=v[i-1];
    }

cout<<"array of sum "<<endl;
     for(int i=0;i<n;i++){
        cout<<v[i]<< "  ";
    }
    cout<<endl;
    
    for(int i=n-1;i>0;i--){
        if(v[i]==0){
maxSubArray=i;
break;
        }
    }
return maxSubArray;
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

  int MS=maximumSequence(v,n);
  cout<<"max sub array is till "<<MS<<" index";
}