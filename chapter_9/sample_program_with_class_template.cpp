// sample_program_with_class_template.cpp
// A simple C++ program that uses a class template to handle triples of different data types.
#include <iostream>

template <typename T> class Triple
{
  public:
    Triple(T first, T second, T third) : a(first), b(second), c(third)
    {
    }

    T maxValue() const
    {
        T maxVal = a;
        if (b > maxVal)
            maxVal = b;
        if (c > maxVal)
            maxVal = c;
        return maxVal;
    }

  private:
    T a, b, c;
};

int main()
{
    Triple<int> triInt(3, 7, 5);
    std::cout << "Max of int triple: " << triInt.maxValue() << "\n";

    Triple<double> triDouble(2.3, 6.7, 4.4);
    std::cout << "Max of double triple: " << triDouble.maxValue() << "\n";

    return 0;
}
