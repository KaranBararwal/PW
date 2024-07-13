#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(){
    int m,n;
    cout<<"enter the size of vectors "<<endl;
    cin>>m>>n;

    vector <int> v1(m);
    cout<<"enter "<<m<<" elemets of first vector "<<endl;
    for(int i=0;i<m;i++){
        cin>>v1[i];
    }

    vector <int> v2(n);
    cout<<"enter "<<n<<" elemets of second vector "<<endl;
    for(int i=0;i<n;i++){
        cin>>v2[i];
    }

    int ans_sum =0;
    
    set <int> s;
    for(auto ele :v1){
        s.insert(ele);
    }
  
    for(auto ele : v2){  
        if(s.find(ele)!=s.end()){
            ans_sum+=ele;
        }
    }

    cout<<"common elements of vectors have sum = "<<ans_sum;
    return 0;
}