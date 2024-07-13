// using QuickSort
#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &nums , int l , int r){
    // quickSort me hum last wala element select krke uski correct position nikalte hai
    int pivot = nums[r]; 

    int i = l;
    // i point kar rha hai pivot se bdi value ko jo array me sbse pehle aa rhi hai
    // yha par l and r lene pde h kyuki hume function me original array liya hai
    for(int j = l ; j < r ; j++){
        if(nums[j] < pivot){
            swap(nums[i] ,nums[j]);
            i++;
        }
    }
    // pivot element ko swap kr denge taki uske right me saari bdi or left me saari chhoti value aa jaye
    swap(nums[i] , nums[r]);
    return i; // pivot element ka index
}

int KthSmallest(vector<int> &nums , int l , int r , int k){

    if(k > 0 && k <= r-l+1){

        // position of the pivot element
        int pos = partition(nums,l,r);

        // positon original array k related hi aayegi
        if(pos - l == k-1){
            return nums[pos];
        }
        else if (pos-l > k-1){
            // so the element is in left side of the array
            return KthSmallest(nums , l , pos-1 , k);
            // k ki value same hi rahegi kyuki left wala part zero se start hota hai
        }
        else{
            return KthSmallest(nums , pos+1 , r , k-(pos-l+1));
            // k ki value right wale part k array k relative nikalni hai 
            // for example 1 4 2 6 3 5 7 8 9
            // isme agar k = 7 ho to right wale part ke liye k ki value uske relative change krni hogi
        }
    }
    return -1;
}

int main(){
    int n;
    cout<<"enter the size of array"<<endl;
    cin>>n;

    vector<int> nums(n);
    cout<<"enter the elements"<<endl;
    for(int i = 0 ; i < n ; i++){
        cin>>nums[i];
    }

    int k;
    cout<<"enter which smallest element you want"<<endl;
    cin>>k;

    cout<<"Kth smallest number is "<<KthSmallest(nums,0,n-1,k);
}