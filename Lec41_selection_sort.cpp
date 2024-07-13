#include<iostream>
#include<vector>
using namespace std;

void selectionSort( vector <int> &v){
    int n=v.size();

    //finding minimum element
    //we need n-1 passes for sorted array
    for(int i=0;i<n-1;i++){
        int min_idx=i;

        for(int j=i+1;j<n;j++){
          if(v[j]<v[min_idx]){
            min_idx=j;
          }
        }

        //placing the minimum element in the starting
        if(min_idx!=i){
             swap(v[i],v[min_idx]);
        }
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
    selectionSort(v);
    for(int i=0;i<n;i++){
        cout<<v[i]<<"  ";
    }

}