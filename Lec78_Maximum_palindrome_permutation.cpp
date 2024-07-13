#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// for checking that palindrome is possible or not
bool isPossible(unordered_map <int , int > &mp){
    int count = 0;
    for( int i = 0 ; i <= 9 ;i++){
        if(mp.count(i)){  
            if(mp[i]%2 != 0){  // number's frequnecy is odd
                count++;
            }
        
          // if two integer got the odd frequency then palindrome is not possible
            if(count > 1){ 
                return false;
            }
        }
        return true;
    }
}

string max_palindrome(string num){  // take number as string
     int l = num.size();
     unordered_map<int , int> mp;

     for(int i = 0 ; i<l ; i++){
        mp[num[i] - '0']++; // - '0' for converting string into int
     }

     if(!isPossible(mp)){
        return "Not Possible ";
     }

     vector <char> v(l);
     int front = 0; // for index
     for(int i = 9 ; i >= 0 ; i--){
        // if number have odd frequncy then we'll first place it in middle
        if(mp[i]%2 != 0){
            v[l/2] = char(i + 48); // ASCII value of 0
            mp[i]--;
        }

        while(mp[i] > 0){
            // starting
            v[front] = char(i + 48); // type cast
            // ending
            v[l - front - 1] = char(i + 48);
            mp[i] -= 2;
            front++;
        }
     }
     string res = "";
     for(int i = 0 ; i < v.size(); i++){
        res += v[i];
     }
          return res;
}

int main(){
    cout<<max_palindrome("313551");
    return 0;
}