#include "Second.hpp"

namespace Programming { namespace ThirdLab { namespace Second {
    
    unsigned int Student::s_ID = 0;
    unsigned int Group::s_ID = 0;
    
    Student::Student(const std::string& name) : m_Name(name), m_ID(s_ID++) {
        for (int i = 0; i < static_cast<int>(Subjects::Amount); i++)
            m_Marks[i] = 0;
    }
    
    Student::Student(const std::string& name, const std::vector<unsigned int>& marks) : m_Name(name), m_ID(s_ID++) {
        if (marks.size() != static_cast<int>(Subjects::Amount))
            throw "bad vector size";
        for (int i = 0; i < static_cast<int>(Subjects::Amount); i++)
            m_Marks[i] = marks[i];
    }
    
    Student::Student(const std::string& name, const unsigned int* marks) : m_Name(name), m_ID(s_ID++){
        for (int i = 0; i < static_cast<int>(Subjects::Amount); i++)
            m_Marks[i] = marks[i];
    }
    
    Student::Student(const Student& student) : m_Name(student.m_Name), m_ID(student.m_ID) {
        for (int i = 0; i < static_cast<int>(Subjects::Amount); i++)
            m_Marks[i] = student.m_Marks[i];
    }
    
    Student::Student(Student&& student) : m_Name(student.m_Name), m_ID(student.m_ID) {
        for (int i = 0; i < static_cast<int>(Subjects::Amount); i++)
            m_Marks[i] = student.m_Marks[i];
    }
    
    const Student& Student::operator=(const Student& student) {
        m_Name = student.m_Name;
        m_ID = student.m_ID;
        for (int i = 0; i < static_cast<int>(Subjects::Amount); i++)
            m_Marks[i] = student.m_Marks[i];
        return *this;
    }
    
    const Student& Student::operator=(Student&& student) {
        m_Name = student.m_Name;
        m_ID = student.m_ID;
        for (int i = 0; i < static_cast<int>(Subjects::Amount); i++)
            m_Marks[i] = student.m_Marks[i];
        return *this;
    }
    
    
    Group::Group(void) : m_ID(s_ID++) {}
    
    Group::Group(const std::list<Student>& group) : m_ID(s_ID++), m_Students(group) {}
    
    Group::Group(const Group& group) : m_ID(group.m_ID), m_Students(group.m_Students) {}
    
    Group::Group(Group&& group) : m_ID(group.m_ID), m_Students(group.m_Students) {}
    
    const Group& Group::operator=(const Group& group) {
        m_ID = group.m_ID;
        m_Students = group.m_Students;
        return *this;
    }
    
    const Group& Group::operator=(Group&& group) {
        m_ID = group.m_ID;
        m_Students = group.m_Students;
        return *this;
    }
   
    void Group::AddStudent(const Student& student) {
        m_Students.push_back(student);
    }
    
    void Group::RemoveStudent(const Student& student) {
        for (auto it = m_Students.begin(); it != m_Students.end(); it++) {
            if (it->GetID() == student.GetID()) {
                m_Students.erase(it);
                break;
            }
        }
    }
    
    const Student& Group::GetStudent(unsigned int id) const {
        static Student badStudent("bad student");
        for (const auto& element : m_Students)
            if (element.GetID() == id)
                return element;
        throw "no such student";
        return badStudent;
    }
    
    double Group::GetAverageMark(Subjects subject) const {
        double mark = 0;
        for (auto& element : m_Students)
            mark += element[subject];
        return mark / m_Students.size();
    }
    
    
    Faculty::Faculty(const std::list<Group>& group) {
        m_Groups = group;
    }
    
    void Faculty::AddGroup(const Group& group) {
        m_Groups.push_front(group);
    }
    
    void Faculty::RemoveGroup(const Group& group) {
        for (auto it = m_Groups.begin(); it != m_Groups.end(); it++) {
            if (it->GetID() == group.GetID()) {
                m_Groups.erase(it);
                break;
            }
        }
    }

    const Group& Faculty::GetGroup(unsigned int id) const {
        static Group badGroup;
        for (const auto& element : m_Groups)
            if (element.GetID() == id)
                return element;
        throw "no such student";
        return badGroup;
    }
    
    double Faculty::GetAverageMark(Subjects subject) const{
        double mark = 0;
        unsigned int count = 0;
        for (const auto& element : m_Groups) {
            for (const auto& student : element) {
                mark += student[subject];
                count++;
            }
        }
        return mark / count;
    }
    
    
    void Task::DoExample(void) {
        Faculty faculty;
         
        static int idGroup = 1;
        int countID = 0;
        
        std::list<Group> groups_list;
        // faculty
        for (int countGroups = 0; countGroups < 5; countGroups++) {
            // group
            countID++;
            Group group;
            for (int countStudents = 0; countStudents < 10; countStudents++) {
                // student
                static unsigned int marks[static_cast<int>(Subjects::Amount)];
                for (int countMarks = 0; countMarks < static_cast<int>(Subjects::Amount); countMarks++) {
                    marks[countMarks] = rand()%(m_MaximalMark - m_MinimalMark) + m_MinimalMark;
                }
                Student student(m_Names[rand()%m_Names.size()], marks);
                group.AddStudent(student);
            }
            faculty.AddGroup(group);
        }
        
        std::cout << "  Оценка по факультету = " << faculty.GetAverageMark(Subjects::Math) << std::endl;
        
        std::cout << "  Оценка 0-ой группы   = " << faculty.GetGroup(idGroup).GetAverageMark(Subjects::Math) << std::endl;
        
        idGroup += countID;
    }

} } }
