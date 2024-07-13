#include<iostream>
#include<vector>
using namespace std;

void merge(vector <int> &nums1 , vector <int> &nums2 , vector <int> &result){
    int n = nums1.size();
    int m = nums2.size();

    int i = 0;
    int j = 0;
    int k = 0;

    // this is very important otherwise we can't assign the value to the result vector
    // Assuming result vector is empty initially
    result.resize(n + m);

    while(i < n && j < m){
        if(nums1[i] < nums2[j]){
            result[k++] = nums1[i++];
        }
        else{
            result[k++] = nums2[j++];
        }
    }

    while(i < n){
        result[k++] = nums1[i++];
    }
    while(j < m){
        result[k++] = nums2[j++];
    }
}

int main(){
    int n;
    cout<<"enter the size of first array"<<endl;
    cin>>n;

    vector<int> nums1(n);
    cout<<"enter the elements of first array"<<endl;
    for(int i = 0 ; i < n ; i++){
        cin>>nums1[i];
    }

    int m;
    cout<<"enter the size of second array"<<endl;
    cin>>m;

    vector<int> nums2(m);
    cout<<"enter the elements of second array"<<endl;
    for(int i = 0 ; i < m ; i++){
        cin>>nums2[i];
    }

    vector<int> result;

    merge(nums1,nums2,result);
    for(int i = 0 ; i < result.size() ; i++){
        cout<<result[i]<<"  ";
    }
    cout<<endl;
    return 0;
}