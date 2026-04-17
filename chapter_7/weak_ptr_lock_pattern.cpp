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
// weak_ptr_lock_pattern.cpp
// Demonstrates the recommended pattern for accessing an object through std::weak_ptr

#include <iostream>
#include <memory>
#include <string>

class Student
{
  public:
    Student(const std::string &name) : m_name{name}
    {
    }

    void display() const
    {
        std::cout << "Student name: " << m_name << '\n';
    }

  private:
    std::string m_name;
};

class Course
{
  public:
    void setStudent(const std::shared_ptr<Student> &student)
    {
        m_student = student;
    }

    std::shared_ptr<Student> getStudent() const
    {
        return m_student.lock();
    }

  private:
    std::weak_ptr<Student> m_student;
};

int main()
{
    std::shared_ptr<Student> objStudent = std::make_shared<Student>("Alice");
    Course objCourse;

    objCourse.setStudent(objStudent);

    std::shared_ptr<Student> studentRef = objCourse.getStudent();

    if (studentRef)
    {
        studentRef->display();
    }
    else
    {
        std::cout << "Student object is no longer available.\n";
    }

    return 0;
}