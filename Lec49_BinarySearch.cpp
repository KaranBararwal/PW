#include <iostream>
#include <vector>
using namespace std;

int BinarySearch(vector<int> &v, int target)
{
    int n = v.size();
    // defining search space
    int lo = 0;     // start of search space
    int hi = n - 1; // end of search space

    while (lo <= hi)
    {
        // calculating midpoint for the search space
        int mid = (lo + hi) / 2;
        if (v[mid] == target)
        {
            return mid;
        }
        else if (v[mid] >= target)
        {
            // discard the right of mid
            hi = mid - 1;
        }
        else
        {
            // discard the left of mid
            lo = mid + 1;
        }
    }
    return -1;
}

int BinarySearchRecursive(vector<int> &v, int target, int lo, int hi)
{
    if (lo > hi)
    {
        return -1;
    }
    int mid = (lo + hi) / 2;
    /* if both the value of low and high are very big
    so we get error by this formula
    so we need to create a formula that is more optimise
    so
    mid=(lo+hi+lo-lo)/2
    mid=((lo+lo)+(hi-lo))/2
    mid=lo+(hi-lo)/2
    */
    mid = lo + (hi - lo) / 2;
    if (v[mid] == target)
    {
        return mid;
    }
    else if (v[mid] < target)
    {
        BinarySearchRecursive(v, target, mid + 1, hi);
    }
    else
    {
        BinarySearchRecursive(v, target, lo, mid - 1);
    }
}

int main()
{
    int n;
    cout << "enter the size " << endl;
    cin >> n;

    cout << "enter " << n << " sorted elements " << endl;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int target;
    cout << "enter the target value ";
    cin >> target;

    cout << BinarySearch(v, target) << " index" << endl;
    cout << "By recursive function index is " << BinarySearchRecursive(v, target, 0, n - 1);
    return 0;
}