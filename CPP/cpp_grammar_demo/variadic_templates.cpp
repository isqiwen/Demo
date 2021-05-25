#include <iostream>

void print()
{
}

template <typename... Types>
void print(const Types &...args)
{
    std::cout << "print" << std::endl;
}

template <typename T, typename... Types>
void print(const T &first_arg, const Types &...args)
{
    // std::cout << sizeof...(args) << std::endl;
    std::cout << first_arg << std::endl;
    print(args...);
}

int main()
{
    print(1, "hello world", 3.2f);
}
