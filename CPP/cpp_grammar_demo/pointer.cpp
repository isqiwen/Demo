#include <iostream>

void print(int arr[])
{
    std::cout << sizeof(arr) << std::endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4};
    print(arr);

    return 0;
}