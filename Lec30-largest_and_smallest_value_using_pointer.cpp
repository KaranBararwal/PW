#include<bits/stdc++.h>
using namespace std;

int smallestAndLargest(int num1,int num2,int num3,int *largest){
    *largest=max(num1,max(num2,num3));
    return min(num1,min(num2,num3));

}
int main(){
    int num1,num2,num3;
    cout<<"enter three numbers "<<endl;
    cin >> num1>>num2>>num3;
    
    int largest;
    int smallest= smallestAndLargest(num1 ,num2 ,num3,&largest);
    cout<<"largest value is "<<largest<<endl<<"smallest value is "<<smallest;
}