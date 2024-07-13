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

   
    int sum=0;

    /*

    *(mat + i): This gets the pointer to the i-th row of the matrix. In other words, it retrieves a pointer to the array of elements for the current row.
*(*(mat + i) + i): This gets the value at the i-th position in the row (i.e., the element at position (i, i) in the matrix).

*/
    for(int i=0;i<n;i++){
        sum+=*(*(mat+i)+i);
    }
    cout<<"sum is equal to "<<sum;
}