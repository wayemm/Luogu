#include<iostream>
using namespace std;

// int main()
// {
//     int n, L;
//     int **arr1 = new int *[n];
//     for (int i = 0; i < n; i++)
//     {
//         arr1[i] = new int[L]{};
//     }
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < L; j++)
//         {
//             cin>>arr1[i][j];
//         }
//         cout << endl;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < L; j++)
//         {
//             cout << arr1[i][j] << ' ';
//         }
//         cout << endl;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         delete[] arr1[i];
//     }
//     delete[] arr1;
// }
int main()
{
    const int size = 10;
    int j;
    int *pi = new int[size];
    int pp[size] = {12, 12, 10, 9, 8, 12, 9, 4, 5, 10};

    for (size_t i = 0; i < size; i++)
    {
        /* code */for (size_t j = i; j< size; j++)
        {
            
            if (pp[i]=pp[j])
            {
                pp[i] = pi[j];
                j++;
            }
            

        }
        
    }
    delete[] pi;
    return 0;
}