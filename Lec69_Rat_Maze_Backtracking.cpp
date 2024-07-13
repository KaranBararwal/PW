#include<iostream>
#include<vector>
using namespace std;

bool CanWeGo(int a , int b , vector<vector<int>> &grid){
    return (a < grid.size() && b< grid.size() && a>=0 && b>=0) &&grid[a][b]==1;
}

int  RatMaze(int i , int j , vector<vector<int>> &grid){
    int n = grid.size();

    // base case
    if(i == n-1 && j ==n-1 ){
        // printing the path
        for(int i=0;i<n;i++){ 
            for(int j=0;j<n;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"*******"<<endl;
        return 1;
    }

    //Backtracking
    int ans=0;
    grid[i][j] = 2; // visited
    

    if(CanWeGo(i,j+1,grid)){
        ans+=RatMaze(i,j+1,grid); // right
    }
    
    if(CanWeGo(i+1,j,grid)){
        ans+=RatMaze(i+1,j,grid); // down
    }
    
    if(CanWeGo(i,j-1,grid)){
        ans+=RatMaze(i,j-1,grid); // left
    }
    
    if(CanWeGo(i-1,j,grid)){
       ans+=RatMaze(i-1,j,grid); // up
    }

    grid[i][j] = 1; // unmarked
    return ans;

}

int main(){

    vector<vector<int> > grid = {
           {1,1,1,1},
           {0,1,0,1},
           {0,1,1,1},
           {0,1,1,1}

    };

    int Ways = RatMaze(0,0,grid);
    cout<<"total number of ways are "<<Ways;
    return 0;

}