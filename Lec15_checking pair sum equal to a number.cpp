#include<iostream>
#include<vector>

using namespace std;

int pairSum(vector<int> &a,int x){
    int count=0;
    for(int i=0;i<a.size();i++){
        for(int j=i+1;j<a.size();j++){
            if(a[i]+a[j]==x){
                count++;
            }
        }
    }
    return count;
}
/*for triplets write third loop 
for(k=j+1;k<n;k++){
    if(a[i]+a[j]+a[k]==x){
        count++;
    }
    }
    */

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

    int x;
    cout<<"enter number for pair sum "<<endl;
    cin>>x;

    int p=pairSum(v,x);
    cout<<"pair sum equal to number is "<<p;



}