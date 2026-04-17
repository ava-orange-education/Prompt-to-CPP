#include <iostream>
template<typename T>
T add(T a, T b)
{
    return a + b;
}

int main()
{
    int result = add(10, 12.35);

    return 0;
}