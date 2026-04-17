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
