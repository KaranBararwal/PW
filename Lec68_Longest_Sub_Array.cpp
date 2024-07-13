#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

int maxLengthZeroSumSubArray(vector<int> &v){
    // Time Complexity --> O(N)
    // 
    unordered_map<int,int> m;
    int prefixSum = 0;
    int maxLength = 0;

    for(int i = 0 ; i < v.size() ; i++){
        prefixSum+=v[i];

        // if all the elements are 0
        if(prefixSum == 0){
            maxLength++;
        }

        if(m.find(prefixSum) != m.end()){
            maxLength = max(maxLength , i - m[prefixSum] );
        }
        else{
            m[prefixSum] = i;
        }
    }

    return maxLength;
}

int main(){
    int n;
    cout<<"enter the size of the array"<<endl;
    cin>>n;

    vector<int> v(n);
    cout<<"enter elements"<<endl;
    for(int i = 0 ; i < n ; i++){
        cin>>v[i];
    }

    cout<<"maximum length of sub array with zero sum " <<maxLengthZeroSumSubArray(v)<<endl;
    return 0;
}