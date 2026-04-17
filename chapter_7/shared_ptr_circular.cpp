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
