#include<iostream>
#include<vector>
using namespace std;

int squareArray(vector <int> &a){
    int n=a.size();
    vector <int> v;
    for(int i=0;i<n;i++){
        int s=a[i]*a[i];
        v.push_back(s);

    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(v[i]>v[j]){
                int c=v[i];
                v[i]=v[j];
                v[j]=c;
            }
        }
    }

for(int i=0;i<n;i++){
    cout<<v[i]<<"  ";
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

  squareArray(v);
}