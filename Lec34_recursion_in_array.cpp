#include<iostream>
using namespace std;

int print(int *arr,int idx,int n){
    //base case
    if(idx==n){
        return 0;
    }
    cout<<arr[idx]<<"  ";
    print(arr,idx+1,n);
}
 
int maximumElement(int *arr,int idx,int n){
    //base case
    if(idx==n-1){
        return arr[n-1];
    }
    //comparing the element with the maximum element of rest of array
       return max(arr[idx],maximumElement(arr,idx+1,n));
    }


int Sum(int *arr,int idx,int n){
    //base case
    if(idx==n-1){
        return arr[n-1];
    }
    //adding the array with sum of rest of array
         return arr[idx]+Sum(arr,idx+1,n);
    
}
int main(){
    int n;
    cout<<"enter the size of array "<<endl;
    cin>>n;

    int arr[n];
    cout<<"enter "<<n<<" elements"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
   cout<<"our array is "<<endl;
    print(arr,0,n);
    cout<<endl;

    cout<<"maximum element is "<<maximumElement(arr,0,n)<<endl;

    cout<<"sum of array is "<<Sum(arr,0,n);
    return 0;

}