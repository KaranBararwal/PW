#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int CountSort(vector<int> &v)
{
    int n = v.size();

    int m = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        m = max(m, v[i]);
    }
    cout << "maximum element is " << m << endl;

    // making array of size (m+1)
    int freq[m + 1] = {0};

    // for each element value in array we are increasing frequency array value by 1 for that index
    for (auto x : v)
    {
        freq[x]++;
    }
    cout << endl;
    cout << "frequency array is " << endl;
    for (int i = 0; i <= m; i++)
    {
        cout << freq[i] << "  ";
    }
    cout << endl;

    // adding sum of previous index in each element of frequency array
    for (int i = 1; i <= m; i++)
    {
        freq[i] += freq[i - 1];
    }
    cout << "cumilitive frequency is " << endl;

    for (int i = 0; i <= m; i++)
    {
        cout << freq[i] << "  ";
    }

    cout << endl;
    int ans[n] = {0};
    for (int i = n - 1; i >= 0; i--)
    {
        // important
        /* first get value of element from array
        for that value check index of frequncy array
        decrease it by 1 and make that decreased value  index of answer array
        for that index insert the original array value
        */
        ans[--freq[v[i]]] = v[i];
    }
    for (int i = 0; i < n; i++)
    {
        v[i] = ans[i];
    }
    cout << "sorted array is " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << "  ";
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

    CountSort(v);
}