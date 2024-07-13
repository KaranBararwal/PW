#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &v)
{
    int n = v.size();
    for (int i = 1; i < n; i++)
    {

        // finding correct position for current element
        int j = i - 1;
        int current = v[i];
        while (j > -1 && v[j] > current)
        {
            v[j + 1] = v[j];
            j--;
        }

        // insert current element
        v[j + 1] = current;
    }
    return;
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

    insertionSort(v);

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << "  ";
    }

    return 0;
}