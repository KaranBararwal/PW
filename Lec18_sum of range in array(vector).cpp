#include<iostream>
#include<vector>
using namespace std;


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

  //convert array into prefix sum array


  for(int i=1;i<n;i++){
      v[i]+=v[i-1];
  }


int q;
cout<<"number of queries "<<endl;
cin>>q;

int l,r;

int ans_sum=0;
while(q--){
    cout<<"enter index of range "<<endl;
    cin>>l>>r;

  /* sum of elemnts in a = sum from starting to last index of range -sum till one less index of starting of range
  
    int answerSum=sum from 0 to r -sum till (l-1)
   */
  
    ans_sum=v[r]-v[l-1];
    cout<<"sum of elements in range "<<ans_sum<<endl;
}
}