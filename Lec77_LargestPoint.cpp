#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int largestPoint(vector <int> &v , int n , int k){

    // creating min heap for getting minimum value at top of queue
    priority_queue<int , vector<int> , greater <int> > pq;

    // inserting  vector elements
    for( auto i : v){
        pq.push(i);
    }

    // now we'll remove the smallest two numbers and add their product in queue
    while(k--){
        int firstSmallest = pq.top();
        pq.pop();
        int secondSmallest = pq.top();
        pq.pop();

        int product = firstSmallest * secondSmallest;
        pq.push(product);
    }

    // we have to return the biggest element in min heap 
    // so we'll pop the elements untill single element left

    while(pq.size() > 1){
        pq.pop();
    }
    return pq.top();
}

int main(){
    int n;
    cout<<"enter the size of vector "<<endl;
    cin>>n;

    int k;
    cout<<"enter the number of operations "<<endl;
    cin>>k;

    vector <int> v(n);
    cout<< "enter "<<n<<" elements "<<endl;
    for(auto &i : v){
        cin>>i;
    }

    cout<<largestPoint(v , n ,k);
    return 0;
}
/*
In the code you provided, the use of the `&` in the line `for(auto &i : v)` is used to create a reference to each element in the vector `v`. This is a common and useful practice when you are taking input into a vector or any other container. 

Here's why it's important to use a reference in this context:

1. **Efficiency**: When you use `&`, you are creating a reference to each element in the vector rather than making a copy. Without `&`, if you use `auto i`, then `i` would be a copy of each element. This is less efficient in terms of memory and performance, especially when dealing with large data structures.

2. **Modifying Elements**: If you use a reference, any modifications you make to `i` inside the loop will directly affect the corresponding element in the vector. Without the reference, any changes you make to `i` will be local to the loop and won't affect the vector.

3. **Correct Input**: When reading user input, you want to modify the actual elements in the vector, not copies of them. Using a reference ensures that the input is correctly stored in the vector.

In summary, using `&` in the for loop when taking input into a vector is a good practice to ensure efficiency and correctness when working with containers. It allows you to work directly with the elements in the container rather than copies of them.
*/