// LeetCode - 283. Move Zeroes

#include<iostream>
#include<vector>
using namespace std;

void moveZerosToEnd(vector <int> &nums){
    int n = nums.size();

    for(int i = n-1 ; i > 0 ; i--){
        int j = 0;
        bool flag = false;
        while(j!=i){
            if(nums[j] == 0 && nums[j+1]!=0){
                swap(nums[j] , nums[j+1]);
                // cout<<"swap done"<<endl;
                flag = true;
            }
            j++;
        }
            if(!flag){
                break;
            }
    }
}

int main(){
    int n;
    cout<<"enter the size of array"<<endl;
    cin>>n;

    vector<int> nums(n);
    cout<<"enter elements"<<endl;
    for(int i = 0 ; i < nums.size() ; i++){
        cin>>nums[i];
    }

    moveZerosToEnd(nums);
    for(int i = 0 ; i < nums.size() ; i++){
        cout<<nums[i]<<"  ";
    }
    cout<<endl;
    return 0;
}