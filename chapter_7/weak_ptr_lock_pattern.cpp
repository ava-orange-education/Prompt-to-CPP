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