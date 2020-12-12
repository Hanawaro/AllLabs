#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

namespace Programming { namespace FourthLab { namespace Second {
    
    struct Date {
    public:
        Date(uint32_t day, uint32_t month, uint32_t year) : m_Day(day), m_Month(month), m_Year(year) {}
        
        inline void SetDate(uint32_t day, uint32_t month, uint32_t year) { m_Day = day; m_Month = month; m_Year = year; }
        
        inline uint32_t day(void) const { return m_Day; }
        inline uint32_t month(void) const { return m_Month; }
        inline uint32_t year(void) const { return m_Year; }
    private:
        uint32_t m_Day   = 0;
        uint32_t m_Month = 0;
        uint32_t m_Year  = 0;
    };
    
    class UsersManager {
    public:
        enum class Type {
            Credit,
            CommunalPayment,
            MobilePhone,
            
            Undef
        };
        
        struct User {
            Date date = Date(0, 0, 0);
            Type info = Type::Undef;
            double sum = 0;
            uint32_t senderID = 0;
            uint32_t recipientID = 0;
        };
    public:
        ~UsersManager(void) = default;
        
        UsersManager(const UsersManager&) = delete;
        UsersManager& operator=(const UsersManager&) = delete;
        
        static std::string ReadFile(const std::string& path);
        static std::vector<User> GetUserVector(const std::string& data);
    private:
        UsersManager(void) = default;
        
        static Date GetDate(std::string& date);
        static Type GetType(std::string& type);
        static double GetSum(std::string& date);
        static uint32_t GetSender(std::string& date);
        static uint32_t GetRecipient(std::string& date);
    };
    
    class Task {
    public:
        void DoExample(const std::string& path) const;
    };
    
} } }
