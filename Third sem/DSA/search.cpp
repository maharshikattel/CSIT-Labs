
#include <iostream>
using namespace std;

int lin_search(int a[], int n, int key)
{
    for (int i = 0; i < n; i++)
        if (a[i] == key)
            return i;
    return -1;
}

int bin_search(int a[], int n, int key)
{
    int mid, top = n - 1, bot = 0;
    while (bot <= top)
    {
        mid = (top + bot) / 2;
        if (key < a[mid])
            top = mid - 1;
        else if (key > a[mid])
            bot = mid + 1;
        else if (a[mid] == key)
            return mid;
    }
    return -1;
}

void result(int a)
{
    if (a == -1)
        cout << "Key not in array";
    else
        cout << "Key at index: " << a << endl;
}
int main()
{
    int a[7] = {1, 8, 19, 23, 45, 88, 107}, b[4] = {5, 12, 37, 45};
    int lin_result, bin_result, k = 5;
    lin_result = lin_search(b, 4, k);
    bin_result = bin_search(a, 7, k);
    result(lin_result);
    result(bin_result);
    return 0;
}
