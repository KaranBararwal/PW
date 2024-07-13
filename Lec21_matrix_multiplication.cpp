#include<iostream>
using namespace std;

int main(){
    int r,c;
    cout<<"enter the value of row and column of first matrix"<<endl;
    cin>>r>>c;

    int mat[r][c];

    cout<<"enter "<<r*c<<" elements "<<endl;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>mat[i][j];
        }
    }

  int R,C;
    cout<<"enter the value of row and column of second matrix"<<endl;
    cin>>R>>C;

    int MAT[R][C];

    cout<<"enter "<<R*C<<" elements "<<endl;

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>MAT[i][j];
        }
    }

    int ProductMatrix[r][C];
  for(int i=0;i<r;i++){
    for(int j=0;j<C;j++){
        ProductMatrix[i][j]=0;
        for(int k=0;k<c;k++){
           ProductMatrix[i][j]+=mat[i][k]*MAT[k][j];
        }
    }
  }

for(int i=0;i<r;i++){
    for(int j=0;j<C;j++){
        cout<<ProductMatrix[i][j]<<"  ";
    }
    cout<<endl;
}


}