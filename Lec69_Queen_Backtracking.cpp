#include<iostream>
#include<vector>
using namespace std;

bool CanWePlace(int row , int col , vector<vector<char> > &grid){
    // important thing is that attack can only come from the upper side 
    
    // checking if there is attack coming from the vertical or not
    for(int i = row-1 ; i >= 0 ; i--){
          if(grid[i][col]=='Q'){
            return false;
          }
    }
     
    // cheacking attack from both the cross ways

    // left side
    for(int i = row - 1 , j = col - 1 ; i >= 0 and j >= 0 ; i-- , j--){
        if(grid[i][j]=='Q'){
            return false;
        }
    }
    
    // right side
     for(int i = row - 1 , j = col + 1 ; i >= 0 and j < grid.size() ; i-- , j++){
       if(grid[i][j]=='Q'){
            return false;
        }
    }
    return true;
    
}

void nQueen(int currRow , int n , vector<vector<char> > &grid){
    // base case
    if(currRow == n){
        // then we'll print the configration
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n ;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl<<endl;
        }
        cout<<"********"<<endl<<endl;
        return ; // not mandatory cuz loop will not run for col>=n but just for safe
    }

    // Backtracking 
    for(int col = 0; col < n ; col++){
        // we'll go to the all the columns
        // lets check can we place the queen at currRow and col
        if(CanWePlace(currRow, col, grid)){
            grid[currRow][col] = 'Q';
            // after filling the box with 'Q' we'll try to fill the next Row
            nQueen(currRow+1 , n , grid);
            // now after checking the one condition of placing we'll get back to check another probablity of placing
            grid[currRow][col] = '.';
        }
    }
}

int main(){
    int n;
    cout<<"enter the number of rows and column for square matrix "<<endl;
    cin>>n;
    
    // intilizing the 2 - D vector
    vector<vector<char> > grid(n , vector<char> (n , '.'));

     for(int i = 0; i < n; i++){
            for(int j = 0; j < n ;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl<<endl;
        }
    cout<<"configration are these "<<endl<<endl;
    nQueen(0,n,grid);
    return 0;
}