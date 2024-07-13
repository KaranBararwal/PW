#include<iostream>
#include<vector>
using namespace std;

int minimumElementIndexInRotatedSortedArray(vector<int> &nums){
    if(nums.size() == 0 && nums.size() == 1){
        return nums.size()-1;
    }

    int lo = 0;
    int hi = nums.size()-1;
    // if the array is already sorted
    if(nums[lo] < nums[hi]){
        return lo;
    }

    // otherwise array is rotated
    while(lo < hi){
        int mid = lo + (hi-lo)/2;
        
        // if mid is around smallest element
        if(nums[mid] > nums[mid+1]){
            return mid+1;
        }

        // don't write like this
        // if(nums[mid] > nums[mid-1]){
        //     return mid-1;
        // }

        if(nums[mid] < nums[mid-1]){
            return mid;
        }

        if(nums[mid] > nums[lo]){
            lo = hi+1;
        }
        else{
            hi = lo-1;
        }
    }
    return -1;
}

int main(){
    int n;
    cout<<"enter the size of the array"<<endl;
    cin>>n;

    vector<int> nums(n);
    cout<<"enter the elements"<<endl;
    for(int i = 0 ; i < n ; i++){
        cin>>nums[i];
    }
    cout<<"minimum element is at index "<<minimumElementIndexInRotatedSortedArray(nums);
    return 0;
}