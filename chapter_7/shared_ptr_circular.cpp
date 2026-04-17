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
// shared_ptr_circular.cpp
// Demonstrates a circular reference using std::shared_ptr

#include <iostream>
#include <memory>

class Course; // forward declaration

class Student
{
  public:
    void setCourse(const std::shared_ptr<Course> &c)
    {
        m_course = c;
    }
    ~Student()
    {
        std::cout << "Student destroyed\n";
    }

  private:
    std::shared_ptr<Course> m_course; // owning link to Course (creates cycle)
};

class Course
{
  public:
    void setStudent(const std::shared_ptr<Student> &s)
    {
        m_student = s;
    }
    ~Course()
    {
        std::cout << "Course destroyed\n";
    }

  private:
    std::shared_ptr<Student> m_student; // owning link to Student (creates cycle)
};

int main()
{
    std::shared_ptr<Student> p_objStudent = std::make_shared<Student>();
    std::shared_ptr<Course> p_objCourse = std::make_shared<Course>();

    p_objStudent->setCourse(p_objCourse);
    p_objCourse->setStudent(p_objStudent);

    // At program end, destructors are never called
    // because p_objStudent and p_objCourse keep each other alive.
    return 0;
}
