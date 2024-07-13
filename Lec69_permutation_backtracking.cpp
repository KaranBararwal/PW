#include<iostream>
using namespace std;

void permutation ( string & str , int i){
    // base case
    if (i==str.size()){
        cout<<str<<endl;
        return ;
    }
    
    int n = str.size();

    for(int j=i;j<n;j++){
          swap(str[i],str[j]); // it is making changes in our actual string
          permutation(str,i+1);
          swap(str[i],str[j]);  // this is important for getting our original string
    }

}

int main(){
    string str;
    cout<<"enter the string "<<endl;
    cin>>str;

    permutation(str,0);
    return 0;


}