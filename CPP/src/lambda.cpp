#include <iostream>

int main()
{
    auto func_1 = []() -> int {
        return 3 * 3;
    };

    std::cout << func_1() << std::endl;

    return 0;
}