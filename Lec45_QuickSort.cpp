#include <iostream>
using namespace std;

int partion(int arr[], int first, int last)
{
    int pivot = arr[last];
    // ((doubt 'why we didn't take i=first and in loop swap(arr[i],arr[j]) then i++ ))
    int i = first - 1; // for inserting elements < pivot
    int j = first;     // for finding elements < pivot (it helps us to find how many elements are less than pivot so we can know the correct position of pivot)

    for (; j < last; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // now i is pointing to the last element < pivot
    //  correct position for pivot will be = i+1
    swap(arr[last], arr[i + 1]);
    return i + 1;
}

void QuickSort(int arr[], int first, int last)
{
    // base case
    if (first >= last)
    {
        return;
    }

    // recursive case
    int pi = partion(arr, first, last);
    QuickSort(arr, first, pi - 1);
    QuickSort(arr, pi + 1, last);
}

int main()
{
    int n;
    cout << "enter the size of array " << endl;
    cin >> n;

    int arr[n];
    cout << "enter " << n << " elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    QuickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}