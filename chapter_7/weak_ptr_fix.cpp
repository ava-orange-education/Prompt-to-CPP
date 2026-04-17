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
// weak_ptr_fix.cpp
// Resolves a circular reference by making one side non-owning using std::weak_ptr

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
    std::shared_ptr<Course> m_course; // owning link to Course
};

class Course
{
  public:
    void setStudent(const std::shared_ptr<Student> &s)
    {
        m_student = s;
    }
    std::shared_ptr<Student> getStudent() const
    {
        // First check if the weak_ptr has expired
        if (m_student.expired())
        {
            // The Student object has already been destroyed
            return nullptr;
        }

        // Safe to convert weak_ptr to shared_ptr
        std::shared_ptr<Student> p_student = m_student.lock();
        return p_student;
    }
    ~Course()
    {
        std::cout << "Course destroyed\n";
    }

  private:
    std::weak_ptr<Student> m_student; // non-owning link to Student
};

int main()
{
    std::shared_ptr<Student> p_objStudent = std::make_shared<Student>(); // owning reference
    std::shared_ptr<Course> p_objCourse = std::make_shared<Course>();    // owning reference

    p_objStudent->setCourse(p_objCourse);  // Student holds an owning reference
    p_objCourse->setStudent(p_objStudent); // Course holds a non-owning reference

    // At program end, destructors are called correctly
    // because there is no circular ownership.
    return 0;
}
