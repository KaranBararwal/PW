// IMPORTANT
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// dry run it
vector <int> next_greater_element( vector <int> &input){
     int n = input.size();

     stack <int> st; // it is storing indexes
     st.push(0);
     vector <int> output(n,-1); 

     for(int i=1; i<n; i++){
           while(!st.empty() && input[st.top()] < input[i]){ // for next smaller element code just change the sign to ">"
            output[st.top()] = input[i];
              st.pop();
           }
           st.push(i);
     }

   while(!st.empty()){   // not mandatory while loop
    output[st.top()] = -1;
    st.pop();
   }
   return output;
}

int main(){
    int n;
    cout<<"enter the size of vector "<<endl;
    cin>>n;

    vector <int> input(n);
    cout<<"enter "<<n<<" elements "<<endl;

    for(int i=0;i<n;i++){
        cin>>input[i];
    }

    vector <int> output = next_greater_element(input);

    for(int i=0;i<output.size();i++){
        cout<<output[i]<<" ";
    }
    cout<<endl;

    return 0;
}