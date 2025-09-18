#include <iostream>

void bubblesort(int v[], int n)
{
    for(int j = 0; j < n-1; j++)
    {
        //int i = 0;
        for(int i = 0; i < n-j-1; i++ )
        {
            if (v[i+1] < v[i])
            {
                int temp = v[i];
                v[i] = v[i+1];
                v[i+1] = temp;
            }
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
    bubblesort(v, N);
    return 0;
}
