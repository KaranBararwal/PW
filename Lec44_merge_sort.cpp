#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &nums , int l , int mid , int r){
    // size of first array
    int an = mid - l + 1;
    int bn = r - mid;

    // creating two temp arrays
    vector <int> a(an);
    vector <int> b(bn);

    for(int i = 0 ; i < an ; i++){
        a[i] = nums[l+i];
    }

    for(int j = 0 ; j < bn ; j++){
        b[j] = nums[mid+1+j];
    }

    int i = 0 ; // initial index of first subarray , a
    int j = 0 ; // initial index of first subarray , b
    int k = l ; // initial index of merged subarray 

    while(i < an && j < bn){
        if(a[i] < b[j]){
            nums[k++] = a[i++];
        }
        else{
            nums[k++] = b[j++];
        }
    }

    while(i < an){
        nums[k++] = a[i++];
    }

    while(j < bn){
        nums[k++] = b[j++];
    }

}

void mergeSort(vector<int> &nums , int l , int r){
    // base case
    if(l >= r){
        return ;
    }
    int mid = (l+r)/2;

    mergeSort(nums , l , mid);
    mergeSort(nums,mid+1 , r);
    merge(nums,l,mid,r);
}

int main(){
    int n;
    cout<<"enter the size of the array "<<endl;
    cin>>n;

    vector<int> nums(n);
    cout<<"enter the elements "<<endl;
    for(int i = 0 ; i < n ; i++){
        cin>>nums[i];
    }

    mergeSort(nums,0,n-1);
    for(int i = 0 ; i < n ; i++){
        cout<<nums[i]<<"  ";
    }
    cout<<endl;
    return 0;
}