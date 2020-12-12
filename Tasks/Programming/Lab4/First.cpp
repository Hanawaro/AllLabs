#include "First.hpp"

namespace Programming { namespace FourthLab { namespace First {
    
    unsigned int Student::s_ID = 0;
    
    Student::Student(const std::string& name, const std::string& course) : m_Name(name), m_Course(course), m_ID(s_ID++) {}
    
    std::ostream& operator<<(std::ostream& out, const Student& student) {
        return out << student.m_Name << " from " << student.m_Course << " ( id = " << student.m_ID << " )" << std::endl;
    }
    
    
    GraduateStudent::GraduateStudent(const std::string& name, const std::string& course, const std::string& topic)
        : Student(name, course), m_Topic(topic) {}
    
    std::ostream& operator<<(std::ostream& out, const GraduateStudent& student) {
        return out << student.m_Name << " from " << student.m_Course << " ( id = "
            << student.m_ID << " )" << " with " << student.m_Topic << " topic"<<  std::endl;
    }
    
    void Task::DoExample(void) {
        Student student("Tim", "PRI");
        GraduateStudent graduateStudent("Tommy", "FBI", "Kidding");
        
        std::cout << "  " << student << "  " << graduateStudent;
    }
    
} } }
