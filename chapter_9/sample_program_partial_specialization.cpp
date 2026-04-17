// sample_program_partial_specialization.cpp
// A simple C++ program that demonstrates partial specialization of a class template.
#include <iostream>

// Generic template for Pair
template <typename T1, typename T2> class Pair
{
  public:
    Pair(T1 first, T2 second) : a(first), b(second)
    {
    }

    void show() const
    {
        std::cout << "Generic Pair: " << a << ", " << b << "\n";
    }

  private:
    T1 a;
    T2 b;
};

// Partial specialization when second type is int
template <typename T1> class Pair<T1, int>
{
  public:
    Pair(T1 first, int second) : a(first), b(second)
    {
    }

    void show() const
    {
        std::cout << "Pair with int as second: " << a << ", integer = " << b << "\n";
    }

  private:
    T1 a;
    int b;
};

int main()
{
    Pair<std::string, double> p1("pi", 3.14);
    p1.show(); // uses generic version

    Pair<std::string, int> p2("count", 42);
    p2.show(); // uses partially specialized version

    return 0;
}
