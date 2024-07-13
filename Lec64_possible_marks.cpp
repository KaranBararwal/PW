#include<iostream>
#include<unordered_set>
using namespace std;

int main(){

    int n,p,q;
    cout<<"enter total number of questions "<<endl;
    cin>>n;

    cout<<"positive marks of one question "<<endl;
    cin>>p;

    cout<<"negative marks of one question "<<endl;
    cin>>q;  

    unordered_set<int> s; // we only need unique elements

    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){

            int correct = i;
            int incorrect = j;
            int unattended = n-(i+j);

            // unattended questions can't be negative
            if(unattended>=0){
                int score = correct*p + incorrect*(-q) ;
                s.insert(score);
            }
            else{
                break; // breaking j loop
            }
        }
    } 
    
    for(auto score : s){
        cout<<score<<" ";
    }
    cout<<endl;

    cout<<"Ans: = "<<s.size()<<endl;
    return 0;
}