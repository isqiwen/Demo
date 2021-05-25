#include <iostream>

int main()
{
    int a[10];
    char b[] = "hello world";
    const char *c = "hello world";
    std::cout << "sizeof int a[10]: " << sizeof(a) << std::endl;
    std::cout << "sizeof char b[] = \"hello world\": " << sizeof(b) << std::endl;
    std::cout << "sizeof const char *c = \"hello world\": " << sizeof(c) << std::endl;
}