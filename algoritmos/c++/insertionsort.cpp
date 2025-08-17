#include <iostream>

void sort(int v[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int j = i;
        while(j < n and v[j] < v[j-1] and j>0 )
        {
            int temp = v[j-1];
            v[j-1] = v[j];
            v[j] = temp;

            j -= 1;
        }
    }
    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << '\n';
}

int main()
{
    const int N = 50;
    int v[N] = {42, 15, 73, -5, 0, 99, 18, 67, 23, 42, 3, 88, 56, -12, 77, 11, 5, 5, 60, 34, 29, 1, -7, 44, 81, 13, 25, 92, 61, -3, 100, 45, 76, 19, 2, 9, 87, 36, 8, 55, 70, -9, 31, 47, 50, 90, 12, 33, 6, 4};
    sort(v, N);
    return 0;
}
