// member_initialiser_list.cpp
// This file demonstrates the use of member initialiser lists in C++.
// It shows how to initialise class members using an initialiser list in the constructor.
// It also illustrates the order of initialisation and the use of const members.
#include <iostream>
#include <string>

class Animal
{
  public:
    // Default constructor: members are initialised before the body runs.
    Animal() : m_colour{"unknown"}, m_habitat{"unknown"}, m_id{0}
    {
        std::cout << "[default] colour=" << m_colour << ", habitat=" << m_habitat << ", id=" << m_id << '\n';
    }

    // Parameterised constructor (written order matches declaration order).
    Animal(int id, const std::string &colour, const std::string &habitat)
        : m_habitat{habitat}, m_colour{colour}, m_id{id}
    {
        std::cout << "[params]  colour=" << m_colour << ", habitat=" << m_habitat << ", id=" << m_id << '\n';
    }

    void printInfo() const
    {
        std::cout << "Animal{id=" << m_id << ", colour=" << m_colour << ", habitat=" << m_habitat << "}\n";
    }

  private:
    std::string m_colour;
    std::string m_habitat;
    const int m_id; // must be initialised in the member initialiser list
};

int main()
{
    Animal a;
    a.printInfo();

    Animal b(7, "white", "jungle");
    b.printInfo();

    return 0;
}
