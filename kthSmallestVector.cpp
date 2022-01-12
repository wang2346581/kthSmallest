#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;
constexpr double maxDouble = numeric_limits<double>::max();
void insertionSort(vector<double> &arr, int size);
double findMedian(vector<double> &arr, int n);
int partition(vector<double> &arr, int l, int r, int x);
double kthSmallest(vector<double> &arr, int l, int r, int k);

void insertionSort(vector<double>::iterator &arr, int size){
    for(int i = 1; i < size; i++)
    {
        double tmp = *(arr + i);
        int j = i-1;
        while(tmp < *(arr+j) && j >= 0)
        {
            *(arr+j+1) = *(arr+j);
            j--;
        }
        *(arr+j+1) = tmp;
    }
}

double findMedian(vector<double>::iterator &arrBegin, int n)
{
    //sort(arrBegin, arrBegin+n);  // Sort the array
    insertionSort(arrBegin, n);
    return *(arrBegin + (n/2));
}

int partition(vector<double> &arr, int l, int r, int x)
{
    int i;
    for (i=l; i<r; i++)
        if (arr[i] == x)
           break;
    swap(arr[i], arr[r]);
    i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}

double kthSmallest(vector<double> &arr, int l, int r, int k)
{
    if (k > 0 && k <= r - l + 1)
    {
        int n = r-l+1;
        int i;
        vector <double> median;
        median.reserve((n+4)/5);
        for (i=0; i<n/5; i++){
            vector<double>::iterator arrBegin = arr.begin() + l + i * 5;
            median[i] = findMedian(arrBegin, 5);
        }
        if (i*5 < n)
        {
            vector<double>::iterator arrBegin = arr.begin() + l + i * 5;
            median[i] = findMedian(arrBegin, n%5);
            i++;
        }   
        int medOfMed = (i == 1)? median[i-1]:
                        kthSmallest(median, 0, i-1, i/2);
        int pos = partition(arr, l, r, medOfMed);
        if (pos-l == k-1)
            return arr[pos];
        if (pos-l > k-1)
            return kthSmallest(arr, l, pos-1, k);
        return kthSmallest(arr, pos+1, r, k-pos+l-1);
    }
    return maxDouble;
}

// Driver program to test above methods
int main()
{
    vector<double> arr = {12, 3, 5, 7, 4, 19, 26, 112, 13, 15, 17, 14, 119, 126};
    int n = arr.size(), k = 10;
    cout << "K'th smallest element is "
         << kthSmallest(arr, 0, n-1, k) << endl;
    return 0;
}


