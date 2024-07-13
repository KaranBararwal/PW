#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int CountSort( vector <int> &v, int n,int pos){

    int freq[10]={0};
    
    // here loop will go till n cuz we need v[i]
    for(int i=0;i<n;i++){
        freq[(v[i]/pos)%10]++;
    }
 
    cout<<endl;
    //cumulative frequency
    for(int i=1;i<10;i++){
        freq[i]+=freq[i-1];
    }

   int ans[n];
    for(int i=n-1;i>=0;i--){
        ans[--freq[(v[i]/pos)%10]]=v[i];
    }

    for(int i=0;i<n;i++){
        v[i]=ans[i];
    }
     cout<<"sorted array is "<<endl;
    for(int i=0;i<n;i++){
        cout<<v[i]<<"  ";
    }

}

int RadixSort( vector<int> &v){
    int n=v.size();

       int m=INT_MIN;
    for(int i=0;i<n;i++){
        m=max(m,v[i]);
    }
    cout<<"maximum element is "<<m<<endl;
    for(int pos=1;m/pos>0;pos*=10){
        CountSort(v,n,pos);
    }
}

int main(){
    int n;
    cout<<"enter the size of array "<<endl;
    cin>>n;

    vector <int> v(n);
    cout<<"enter "<<n<<" elements "<<endl;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    RadixSort(v);

}