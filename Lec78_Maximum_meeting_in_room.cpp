#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct meeting{
      int start;
      int end;
      int idx;
};

bool cmp( meeting m1 , meeting m2){
      return m1.end < m2.end;
}

void print_max_meeting( vector<meeting> &arr){
    sort(arr.begin() , arr.end() , cmp);
    // cuz we need to insert first meeting (in sorted array ) so we'll print it
    cout<<arr[0].idx<<"  ";
    meeting last = arr[0]; // for storing which is last meeting was held

    for(int i = 1 ; i < arr.size(); i++){
        if(arr[i].start > last.end){
            cout<<arr[i].idx<<"  ";
            last = arr[i];
        }
    }
}

int main(){
    int n;
    cout<<"enter the number of total meetings "<<endl;
    cin>>n;

    vector <meeting> arr;
    int i = 0;
    while(n--){
        int s , e;
        i++;
        meeting m;
        cout<<"enter the starting and ending time of "<<i<<"th meeting "<<endl;
        cin>>s>>e;
        m.start = s;
        m.end = e;
        m.idx = i;
        arr.push_back(m);
    }
     cout<<"indexes of meetings that can be held "<<endl;
     print_max_meeting(arr);
}