#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &s){

    vector<vector<int>> ans;
    int j=0;
    ans.push_back(s[0]);

    for(int i=1;i<s.size();i++){
        if(ans[j][1]>=s[i][0]){
            ans[j][1]=max(ans[j][1],s[i][1]);
        }
        else{
            j++;
            ans.push_back(s[i]);
        }
    }
    return ans;
}

int main(){
    int r;
    int c=2;
    cout<<"enter the value of rows ";
    cin>>r;

    vector<vector<int> > v(r,vector<int>(c));

cout<<"enter "<<r*c<< " elements "<<endl;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
         cin>>v[i][j];
        }
       
    }

    vector<vector<int>> ans=merge(v);

for(int i=0;i<ans.size();i++){
    cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
}

}