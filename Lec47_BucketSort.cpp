#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int BucketSort(float arr[], int n)
{

    vector<vector<float>> bucket(n, vector<float>());

    // inserting elements into bucket
    for (int i = 0; i < n; i++)
    {
        int index = arr[i] * n;
        bucket[index].push_back(arr[i]);
    }

    // sorting the buckets
    for (int i = 0; i < n; i++)
    {
        if (!bucket[i].empty())
        {
            sort(bucket[i].begin(), bucket[i].end());
        }
    }

    int k = 0;
    // combining elements from buckets
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < bucket[i].size(); j++)
        {
            arr[k++] = bucket[i][j];
        }
    }
}

int main()
{
    int n;
    cout << "enter the size of array " << endl;
    cin >> n;

    float arr[n];
    cout << "enter " << n << " elements " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    BucketSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    return 0;
}