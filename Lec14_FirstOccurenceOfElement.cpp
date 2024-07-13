#include<iostream>
#include<vector>
using namespace std;

int FirstOccurence( vector <int> &v ,int target ){
    int n=v.size();
    int lo=0;
    int hi=n-1;
    int ans=-1;
    while(lo<=hi){
         int mid=lo+(hi-lo)/2;
         if(v[mid]==target){
            ans=mid;
            hi=mid-1;
         }
         else if(v[mid]<target){
            lo=mid+1;
         }
         else{
            hi=mid-1;
         }
    }

    return ans;
}

int main(){
   int n;
   cout<<"enter the size "<<endl;
   cin>>n;

   cout<<"enter "<<n<<" sorted elements "<<endl;
   vector <int> v(n);
   for(int i=0;i<n;i++){
    cin>>v[i];
   }

   int target;
   cout<<"enter the target value ";
   cin>>target;

   cout<<"first occurence index is "<<FirstOccurence(v,target);
}