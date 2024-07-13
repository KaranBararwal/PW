#include<iostream>
#include<vector>
using namespace std;

int diff( vector <int> &a, int x){
  int count=0;
for(int i=0;i<a.size();i++){
  for(int j=i+1;j<a.size();j++){
    if(a[j]-a[i]==x){
      count++;
    
    }
  }
}
return count;
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

  int x;
  cout<<"enter number for difference"<<endl;
  cin>>x;

  int r=diff(v,x);
  cout<<"frequency is "<<r;
}