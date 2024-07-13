#include<iostream>
#include<vector>
using namespace std;

int lowerbound(vector<int> &nums , int target){ // first index >= target
    /*
    Time : O(logn)
    Space : O(1)
    */

   int lo = 0;
   int hi = nums.size()-1;
   int ans = -1;

   while(lo <= hi){
    int mid = lo + (hi-lo)/2;
    if(nums[mid] >= target){
        ans = mid;
        hi = mid - 1;
    }
    else{
        lo = mid+1;
    }
   }
    return ans;
}

int upperbound(vector<int> &nums , int target){  // first index of element greater then the target
    /*
    Time : O(logn)
    Space : O(1)
    */
   int lo = 0;
   int hi = nums.size()-1;
   int ans = -1;

   while(lo <= hi){
    int mid = lo + (hi-lo)/2;

    if(nums[mid] > target){
        ans = mid;
        hi = mid - 1;
    }
    else{
        lo = mid+1;
    }
   }
   return ans;
}

int main(){
    int n;
    cout<<"enter the size of the array "<<endl;
    cin>>n;

    vector<int> nums(n);
    cout<<"enter the elements"<<endl;
    for(int i = 0 ; i < n ; i++){
        cin>>nums[i];
    }

    int target;
    cout<<"enter the element of first and last index"<<endl;
    cin>>target;

    int lb = lowerbound(nums,target);

    vector<int> result;
    if(nums[lb]!=target){
        result.push_back(-1);
        result.push_back(-1);
    }
        else{
            int ub = upperbound(nums , target);
            result.push_back(lb);
            result.push_back(ub);
        }
    cout<<"the lower and upper bound are "<<result[0]<<"  "<<result[1]<<endl;
    return 0;
}

