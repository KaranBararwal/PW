#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main(){
    int n;
    cout<<"enter the size of vector "<<endl;
    cin>>n;

    cout<<"enter "<<n<<" elements "<<endl;

    vector <int> input(n);
    for(int i=0;i<n;i++){
        cin>>input[i];
    }

    map<int , int> m; // time complexitiy = O(n)
    for(int i=0;i<n;i++){
        // if key is already present there then it will increase the value
        // if key is not present there then it will made a new key with value starting with 1
        m[input[i]]++;
        // it is storing frequency of elements in input array 
    } 

    int sum = 0;
    // finding sum of repititive elements
    // pair = {element , frequency}

    for(auto pair : m){ // time complexity is going to be less then n (cuz repititve got eleminated)
        if(pair.second>1){  // element is repititive
          sum+=pair.first; 
        }
    }
    cout<<"Sum is "<<sum;

    // overall time complexity is O(n) {greater one}
}