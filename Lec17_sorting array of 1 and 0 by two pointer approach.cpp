#include<iostream>
#include<vector>
using namespace std;


int sortArray( vector <int> &v){
   
int i=0;
int j=v.size()-1;

while(i<j){
    if(v[i]==1 && v[j]==0){
        v[i]=0;
        v[j]=1;
        i++;
        j--;
    }
    if(v[i]==0){
        i++;
    }
    if(v[j]==1){
        j--;
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

  sortArray(v);

  for(int i=0;i<n;i++){
    cout<<v[i]<<" ";
  }
}

