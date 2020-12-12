#pragma once

#include <iostream>
#include <vector>
#include <list>

namespace Programming { namespace ThirdLab { namespace Second {
    
    enum class Subjects {
        Math = 0,
        Programming,
        Amount
    };
    
    class Student {
    public:
        Student(const std::string& name);
        Student(const std::string& name, const std::vector<unsigned int>& marks);
        Student(const std::string& name, const unsigned int* marks);
        
        Student(const Student& student);
        Student(Student&& student);
        
        const Student& operator=(const Student& student);
        const Student& operator=(Student&& student);
        
        ~Student(void) = default;
        
        unsigned int operator[] (Subjects subject) const { return m_Marks[static_cast<int>(subject)]; }
        
        inline unsigned int GetID(void) const { return m_ID; } 
    private:
        std::string m_Name;
        unsigned int m_ID;
        unsigned int m_Marks[static_cast<int>(Subjects::Amount)];
        
        static unsigned int s_ID;
    };
    
    class Group {
    public:
        Group(void);
        Group(const std::list<Student>& group);
        
        Group(const Group& group);
        Group(Group&& group);
        
        const Group& operator=(const Group& group);
        const Group& operator=(Group&& group);
        
        ~Group(void) = default;
        
        void AddStudent(const Student& student);
        void RemoveStudent(const Student& student);
        
        const Student& GetStudent(unsigned int id) const;
        double GetAverageMark(Subjects subject) const;
        inline unsigned int GetID(void) const { return m_ID; }
        
        inline std::list<Student>::iterator begin(void) { return m_Students.begin(); }
        inline std::list<Student>::iterator end(void) { return m_Students.end(); }
        inline std::list<Student>::const_iterator begin(void) const { return m_Students.begin(); }
        inline std::list<Student>::const_iterator end(void) const { return m_Students.end(); }
    private:
        unsigned int m_ID;
        std::list<Student> m_Students;
        
        static unsigned int s_ID;
    };
    
    class Faculty {
    public:
        Faculty(void) = default;
        Faculty(const std::list<Group>& faculty);
        ~Faculty(void) = default;
        
        void AddGroup(const Group& group);
        void RemoveGroup(const Group& group);
        
        const Group& GetGroup(unsigned int id) const;
        double GetAverageMark(Subjects subject) const;
    private:
        std::list<Group> m_Groups;
    };
    
    class Task {
    public:
        void DoExample(void);
    private:
        const std::vector<std::string> m_Names = {
            "Петя",
            "Саша",
            "Владик",
            "Генадий",
            "Альберт"
        };
        
        const unsigned int m_MaximalMark = 5;
        const unsigned int m_MinimalMark = 2;
    };
    
} } }
