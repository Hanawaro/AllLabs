#pragma once

#include <iostream>
#include <string>

namespace Programming { namespace FourthLab { namespace First {
    
    class Student {
    public:
        Student(const std::string& name, const std::string& course);
        virtual ~Student(void) = default;
        
        friend std::ostream& operator<<(std::ostream& out, const Student& student);
        
        inline void SetName(const std::string& name) { m_Name = name; }
        inline void SetCourse(const std::string& course) { m_Course = course; }
        
        inline const std::string& GetName(void) const { return m_Name; }
        inline const std::string& GetCourse(void) const { return m_Course; }
        inline unsigned int GetID(void) const { return m_ID; }
    protected:
        std::string m_Name;
        std::string m_Course;
        unsigned int m_ID;
        
        static unsigned int s_ID;
    };
    
    class GraduateStudent : public Student {
    public:
        GraduateStudent(const std::string& name, const std::string& course, const std::string& topic = "");
        virtual ~GraduateStudent(void) = default;
        
        friend std::ostream& operator<<(std::ostream& out, const GraduateStudent& student);
        
        inline void SetTopic(const std::string& topic) { m_Topic = topic; }
        inline const std::string& GetTopic(void) const { return m_Topic; }
    private:
        std::string m_Topic;
    };
    
    class Task {
    public:
        void DoExample(void);
    };

} } }
