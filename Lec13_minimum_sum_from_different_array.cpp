#include<iostream>
#include<climits>
using namespace std;

int min_sum(int a[],int b[], int n){
    int min_sum=INT_MAX;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j && (i<j||j<i||a!=b)){
                int sum=a[i]+b[j];
                if(sum<min_sum){
                    min_sum=sum;
                }
            }
        }
    }
    return min_sum;
}
int main(){
        int n;
        cout<<"enter size of the array"<<endl;
        cin>>n;
        int arr[n];
        int ARR[n];
        cout<<"enter first array elements"<<endl;
        for(int i=0;i<n;i++){
        cin>>ARR[i];
        }
cout<<"enter second array elements"<<endl;
        for(int i=0;i<n;i++){
        cin>>arr[i];
        }
int result=min_sum(arr,ARR,n);
cout<<"the minimum sum is "<<result<<endl;
}