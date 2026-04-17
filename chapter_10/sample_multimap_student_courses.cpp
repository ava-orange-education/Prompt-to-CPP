// sample_multimap_student_courses.cpp
// This program demonstrates the use of a multimap to store multiple courses for each student.
#include <iostream>
#include <map>
#include <string>

int main()
{
    std::multimap<std::string, std::string> studentCourses;

    // Define student names once
    const std::string alice = "Alice";
    const std::string bob   = "Bob";
    const std::string carol = "Carol";

    // Each student enrolls in multiple courses
    studentCourses.insert(std::make_pair(alice, "Mathematics"));
    studentCourses.insert(std::make_pair(alice, "Computer Networks"));
    studentCourses.insert(std::make_pair(bob, "Physics"));
    studentCourses.insert(std::make_pair(alice, "Operating Systems"));
    studentCourses.insert(std::make_pair(carol, "Database Systems"));
    studentCourses.insert(std::make_pair(bob, "Linear Algebra"));

    const std::string name = alice; // Change this to Bob or Carol to see their courses

    std::cout << "Courses enrolled by " << name << ":\n";

    // Retrieve all courses for the specified student
    auto range = studentCourses.equal_range(name);

    for (auto it = range.first; it != range.second; ++it)
    {
        std::cout << "- " << it->second << '\n';
    }

    return 0;
}
