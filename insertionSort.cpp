#include <iostream>
using namespace std;
void insertionSort(int a[], int size){
    for(int i = 1; i < size; i++){ // 對尚未排序元素做迴圈
        int tmp = a[i]; // 暫存第一個將被插入(或說取代)的值, 因為其尚未排序
        int j = i-1;
        while(tmp < a[j] && j >= 0){ // 若暫存值較小就讓已排序的前面元素依序往後插入
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = tmp; // 放入暫存值正確的位置
    }
}

int main()
{
    int a[] = {5, 7, 10, 6 , 2, 1};
    int n = sizeof(a) / sizeof(a[0]);
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    insertionSort(a, n);
    cout << "排序後" << endl;
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;    
    return 0;
}