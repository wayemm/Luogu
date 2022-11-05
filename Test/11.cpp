#include<iostream>
void xx(int (arr)[10])
{
    for (size_t i = 0; i < 10; i++)
    {
        /* code */std::cout << arr[i];
    }
    
}
int main()
{
    using namespace std;
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    xx(arr);
    return 0;
}