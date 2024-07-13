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

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(mat[i][j]==0){
                for(int k=0;k<c;k++){
                    mat[i][k]=0;
                }
            }
        }
    }

       for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<mat[i][j]<<"  ";
        }
        cout<<endl;
    }
}