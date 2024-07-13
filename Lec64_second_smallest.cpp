#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(){

    int n;
    cout<<"enter the size of vector "<<endl;
    cin>>n;

    vector<int> v(n);
    cout<<"enter "<<n<<" elements "<<endl;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    set<int> s;
    for(auto val : v){
        s.insert(val);
    }

    auto itr = s.begin();
    itr++;
    cout<<"second smallest number is "<<*itr<<endl;
    return 0;
}