#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int BucketSort(float arr[],int n){
    
    vector <vector <float > > bucket(n,vector<float> ());
    
    // finding range
    float max_ele=arr[0];
    float min_ele=arr[0];
    for(int i=0;i<n;i++){
        max_ele=max(max_ele,arr[i]);
        min_ele=min(min_ele,arr[i]);
    }

    float range= (max_ele-min_ele)/n;

    // inserting elements 
    for(int i=0;i<n;i++){
        int index= (arr[i]-min_ele)/range;
        float diff=(arr[i]-min_ele)/range -index;

        /*boundary condition
        for maximum element the {(arr[i]-min_ele)/range} value will be equal to size 
        for example size is 8 
        but here we have only array till 7th index
        so we check the difference if it is equal to zero than it is minimum value or maximum value
        */
        if(diff==0 && arr[i]!=min_ele){    
        bucket[index-1].push_back(arr[i]);
        }
        else{
        bucket[index].push_back(arr[i]);
        }
    }

    // sorting the buckets
    for(int i=0;i<n;i++){
        if(!bucket[i].empty()){
            sort(bucket[i].begin(),bucket[i].end());
        }
    }

    int k=0;
    // combining elements from buckets 
    for(int i=0;i<n;i++){
        for(int j=0;j<bucket[i].size();j++){
          arr[k++]=bucket[i][j];
        }
    }

}
int main(){
    int n;
    cout<<"enter the size of array "<<endl;
    cin>>n;

    float arr[n];
    cout<<"enter "<<n<<" elements "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    BucketSort(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<"  ";
    }
}