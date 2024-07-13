#include<iostream>
using namespace std;

int FMN(int nums[],int n){
    int found[n+1];

    for(int i=0;i<=n;i++){
        found[i]=0; //initialize found array with 0
    }

    for(int i=0;i<n;i++){
        found[nums[i]]=1;
    }
    for(int i=0;i<=n;i++){
        if(found[i]==0){
            return i;
        }
    }

}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int result=FMN(arr,n);
    cout<<result;
}