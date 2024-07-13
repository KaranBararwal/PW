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
    int t=1;
    for(int i=0;i<r;i++){
        for(int j=i;j<c;j++){
            if(mat[i][j]!=mat[i+1][j+1] && j!=c-1 && i!=r-1){
                t=0;
                cout<<mat[i][j];
                break;
            }  
        }
}
if(t==1){
    cout<<"true ";
}
else{
    cout<<"false ";
}

/*                                                         <<<--- SECOND METHOD--->>>

bool check(vector<vector<int>>& mat)
{
int r=mat.size();
int c=mat[0].size();
for(int i=1;i<r;i++)
{
for(int j=1;j<c;j++)
{
if(mat[i][j]!=mat[i-1][j-1])
{
return false;
}
}
}
return true;
}*/

}
