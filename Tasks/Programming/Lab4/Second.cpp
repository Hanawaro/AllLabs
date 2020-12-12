#include "Second.hpp"

namespace Programming { namespace FourthLab { namespace Second {
    
    std::string UsersManager::ReadFile(const std::string& path) {
        std::string result;
        std::ifstream in(path);
        if (in.is_open()) {
            in.seekg(0, std::ios::end);
            result.resize(in.tellg());
            in.seekg(0, std::ios::beg);
            in.read(&result[0], result.size());
            in.close();
        } else {
            std::cout << "  Не удалось открыть файл" << std::endl;
            throw "Read file error";
        }
        
        return result;
    }
    
    std::vector<UsersManager::User> UsersManager::GetUserVector(const std::string& data) {
        std::vector<User> result;
        
        std::stringstream users(data);
        
        int tmpDay, tmpMonth, tmpYear;
        std::string typeTmp;
        double tmpSum;
        int tmpSender;
        int tmpRecipient;
        
        
        for (std::string user; std::getline(users, user);) {
            std::stringstream tmp(user);
            
            UsersManager::User newUser;
            
            // date
            tmp >> tmpDay >> tmpMonth >> tmpYear;
            newUser.date = Date(tmpDay, tmpMonth, tmpYear);
            // type
            tmp >> typeTmp;
            newUser.info = GetType(typeTmp);
            // sum
            tmp >> tmpSum;
            newUser.sum = tmpSum;
            // sender id
            tmp >> tmpSender;
            newUser.senderID = tmpSender;
            // recipient id
            tmp >> tmpRecipient;
            newUser.recipientID = tmpRecipient;
            
            result.push_back(newUser);
        }
        
        return result;
    }
    
    Date UsersManager::GetDate(std::string& date) {
        return Date(0, 0, 0);
    }
    
    UsersManager::Type UsersManager::GetType(std::string& type) {
        Type result = Type::Undef;
        std::transform(type.begin(), type.end(), type.begin(), [](unsigned char c){ return std::tolower(c); });
        if (type == "credit") {
            result = Type::Credit;
        } else if (type == "communalpayment") {
            result = Type::CommunalPayment;
        } else if (type == "mobilephone") {
            result = Type::MobilePhone;
        }
        
        return result;
    }
    
    double UsersManager::GetSum(std::string& date) {
        return double();
    }
    
    uint32_t UsersManager::GetSender(std::string& date) {
        return 0;
    }
    
    uint32_t UsersManager::GetRecipient(std::string& date) {
        return 0;
    }
    
    
    void Task::DoExample(const std::string& path) const {
        auto users = UsersManager::GetUserVector(UsersManager::ReadFile(path));
        uint32_t count[static_cast<int>(UsersManager::Type::Undef)];
        double maximalSum[static_cast<int>(UsersManager::Type::Undef)];
        for (int i = 0; i < static_cast<int>(UsersManager::Type::Undef); i++) {
            count[i] = 0;
            maximalSum[i] = 0;
        }
        for (const auto& user : users) {
            if (user.info == UsersManager::Type::Undef)
                throw "unknown type";
            count[static_cast<int>(user.info)]++;
            if (maximalSum[static_cast<int>(user.info)] < user.sum)
                maximalSum[static_cast<int>(user.info)] = user.sum;
        }
        
        for (int i = 0; i < static_cast<int>(UsersManager::Type::Undef); i++) {
            std::cout << "  " << i << ": " << count[i] << " with max = " << maximalSum[i] << std::endl;
        }
    }
    
} } }
