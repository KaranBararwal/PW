#include<iostream>
#include<vector>
using namespace std;

int productElements(vector <int> &v,  int n){

  for(int i=1;i<n;i++){
    v[i]*=v[i-1];
  }

  cout<<"array of prefix product "<<endl;
     for(int i=0;i<n;i++){
        cout<<v[i]<< "  ";
    }
    cout<<endl;

  for(int i=0;i<n;i++){
    v[i]=(v[n-1])/(v[i]);
  }

  cout<<"array of product expect that element "<<endl;
     for(int i=0;i<n;i++){
        cout<<v[i]<< "  ";
    }
    cout<<endl;
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

productElements(v,n);
  
}