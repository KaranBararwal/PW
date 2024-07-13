#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter the value of row and column in square matrix "<<endl;
    cin>>n;

    int mat[n][n];

    cout<<"enter "<<n*n<<" elements "<<endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }

    //first taking the transpose of matrix

    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            swap(mat[i][j],mat[j][i]);
        }
    }

    //now swap the column till middle of matrix

    for(int i=0;i<n;i++){
        for(int j=0;j<(n/2);j++){

            swap(mat[i][j],mat[i][n-1-j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<mat[i][j]<<"  ";
        }
        cout<<endl;
    }
}