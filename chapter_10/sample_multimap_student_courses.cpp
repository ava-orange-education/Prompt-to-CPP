/*
 * Copyright (C) 2026
 * Author: Vivek Bhadra
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */
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
