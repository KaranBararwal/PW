#include<iostream>
using namespace std;

int main(){
    int r,c;
    cout<<"enter the value of row and column "<<endl;
    cin>>r>>c;

    int mat[r][c];

    cout<<"enter "<<r*c<<" elements "<<endl;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>mat[i][j];
        }
    }

    int max=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(mat[i][j]>max){
                max=mat[i][j];
            }
        }
    }

    cout<<"maximum element is "<<max;
}