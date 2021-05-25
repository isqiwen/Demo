#include <iostream>

typedef int func_t_t(int, int);
typedef int (*func_t_p)(int, int);
typedef int (&func_t_r)(int, int);

using func_u_t = int(int, int);
using func_u_p = int (*)(int, int);
using func_u_r = int (&)(int, int);

int sum(int a, int b)
{
    return a + b;
}

int main()
{
    func_t_t *f_t_t = sum;
    func_t_p f_t_p = sum;
    func_t_r f_t_r = sum;

    func_u_t *f_u_t = sum;
    func_u_p f_u_p = sum;
    func_u_r f_u_r = sum;

    std::cout << f_t_t(1, 2) << std::endl;
    std::cout << f_t_p(1, 2) << std::endl;
    std::cout << f_t_r(1, 2) << std::endl;

    std::cout << f_u_t(1, 2) << std::endl;
    std::cout << f_u_p(1, 2) << std::endl;
    std::cout << f_u_r(1, 2) << std::endl;

    return 0;
}
