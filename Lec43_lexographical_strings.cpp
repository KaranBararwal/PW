#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

void selectionSort(vector <string> & fruit, int n){

    for(int i = 0 ; i < n-1 ; i++){

        // finding the minimum element
        int min_index = i;
        for(int j = i+1 ; j < n ; j++){
            // if(strcmp(fruit[min_index] , fruitj]) > 0){    for array of the strings

            // Comparison of C++ strings: The strcmp function is used for comparing C-style strings (character arrays). 
            // However, your vector is of type string, and you should use the compare method for comparing C++ strings.
            if(fruit[min_index].compare(fruit[j]) > 0){
                min_index = j;
            }
        }

        // place the minimum element at the begining
        if(i!=min_index){ // it means we've found the lesser order element then the current loop i element
            swap(fruit[i] , fruit[min_index]);
        }
    }
}
int main(){
    int n;
    cout<<"enter the number of fruits"<<endl;
    cin>>n;

    vector <string> s(n);
    cout<<"enter fruits name"<<endl;
    for(int i = 0 ; i < n ; i++){
        cin>>s[i];
    }

    selectionSort(s , n);
    for(int i = 0 ; i < n ; i++){
        cout<<s[i]<<"  ";
    }
    return 0;
}