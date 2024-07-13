#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &v)
{
    int n = v.size();
    // we need to run the loop n-1 times coz last element will automatically get sorted
    for (int i = 0; i < n - 1; i++)
    {
        // for optimization if there is sorted array we stop the loop
        bool flag = false;
        // we need to compare elements (n-i-1) times cuz last i elments are at right place after i swapping loops
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (v[j] > v[j + 1])
            {
                flag = true;
                swap(v[j], v[j + 1]);
            }
        }
        if (!flag)
        {
            break;
        }
    }
}
int main()
{
    int n;
    cout << "enter the size of array " << endl;
    cin >> n;

    vector<int> v(n);
    cout << "enter " << n << " elements " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    bubbleSort(v);
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << "  ";
    }
}