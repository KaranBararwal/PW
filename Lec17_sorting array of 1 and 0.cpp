#include<iostream>
#include<vector>
using namespace std;

void sortvector(vector <int> &a){
   int count_zero=0;
   int i=0;
   for(i=0;i<a.size();i++){
    if(a[i]==0){
        count_zero++;
    }
   }
   for(int i=0;i<a.size();i++){
    if(i<count_zero){
        a[i]=0;
    }
    else{
        a[i]=1;
    }
   }

    return ;
}

int main(){

    int n;
    cout<<"enter the size "<<endl;
    cin>>n;
    vector<int> v;

    for(int i=0;i<n;i++){
        int p;
        cout<<"enter the "<<i<<"element"<<endl;
        cin>>p;
        v.push_back(p);
    }
    
    sortvector(v);
    cout<<"sorted array is"<<endl;
    for(int i=0;i<n;i++){
        cout<<v[i]<<endl;
    }
}
