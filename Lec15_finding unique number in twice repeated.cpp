#include<iostream>
#include<vector>

using namespace std;

int unique(vector<int> &v){
    int uni;
    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
            if(v[i]==v[j]){
                v[i]=v[j]=-1;
            }
            else{
                uni=v[i];
            }
        }
    }
    return uni;
}
int main(){
    int n;
    cout<<"enter the size of array"<<endl;
    cin>>n;

    vector <int> v;
    for(int i=0;i<n;i++){
        int p;
        cout<<"enter "<<i+1<<" element"<<endl;
        cin>>p;
        v.push_back(p);
    }
  
    int p=unique(v);
    cout<<"unique number is "<<p;

}