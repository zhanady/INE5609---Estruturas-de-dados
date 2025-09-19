#include <iostream>

void sort(int v[], int n)
{
    int min_index = 0;
    int min_value = v[0];
       
    for( int j = 0; j < n; j++)
    { 
        int min_index = j;
        //int min_value = v[j];
        for(int i = j + 1; i < n; i++)
        {
            if (v[i] < v[min_index])
            {
                min_index = i;
            }
        }
        // Troca v[j] com v[min_index]
        int temp = v[j];
        v[j] = v[min_index];
        v[min_index] = temp;
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
