#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Item{
     int value; // profit
     int weight;
};

bool cmp( Item i1 , Item i2 ){
      // custom comprator for sorting
      double v_w_i1 = static_cast<double> (i1.value) / i1.weight;
      double v_w_i2 = static_cast<double> (i2.value) / i2.weight;
      return v_w_i1 > v_w_i2;
}

double fractional(int W , vector <Item> &items){
    // W is total capacity
    double ans = 0;
    sort( items.begin() , items.end() , cmp);

    for(const auto &item : items){
        // if we can fit the whole product
        if(item.weight <= W){
            ans += item.value;
            W -= item.weight;
        }
        else{  // we can't pick the whole item as space in knapsack is less
            double fraction = static_cast <double> (W) / item.weight;
            ans += fraction * item.value ; // fractional profit
            W = 0; // l=no space is left
        }
    }
    return ans;
}

int main(){
    int n,W;
    cout<<"enter the number of products "<<endl;
    cin>>n;

    cout<<"enter the total capacity "<<endl;
    cin>>W;

    vector <Item> items; 

    for(int i = 0 ; i < n ; i++){
        int v , w;
        cout<<"enter the "<<i+1<<"th product profit and weight "<<endl;
        cin>>v>>w;
        Item it;
        it.value = v;
        it.weight = w;
        items.push_back(it);
    }

    cout<<"maximum profit is "<<fractional(W , items)<<endl;
    return 0;
}