#pragma once

#include "Reader.hpp"

#include "Tasks/AllTasks.hpp"

namespace Programming {
    
    class UserInputController {
    public:
        UserInputController(void) = default;
        virtual ~UserInputController(void) = default;
    
        void OnFirstLabFirst(void);
        void OnFirstLabSecond(void);
        void OnFirstLabThird(void);
        void OnSecondLabFirst(void);
        void OnSecondLabSecond(void);
        void OnThirdLabFirst(void);
        void OnThirdLabSecond(void);
        void OnFourthLabFirst(void);
        void OnFourthLabSecond(void);
        void OnFourthLabThird(void);
        void OnFifthLabFirst(void);
        void OnSixthLabFirst(void);
        void OnSixthLabSecond(void);
    };

}

namespace SAOD {
    
    class UserInputController {
    public:
        UserInputController(void) = default;
        virtual ~UserInputController(void) = default;
    
        void OnFirstLabFirst(void);
        void FillData(FirstLab::First::Task::QuickData& data);
        void FillData(FirstLab::First::Task::SlowData& data);
        void FillSlow(std::vector<double>& vec);
        void FillQuick(FirstLab::First::Task::QuickData& data);
        
        void OnSecondLabFirst(void);
        void OnThirdLabFirst(void);
        void OnFourthLabFirst(void);
        void OnFifthLabFirst(void);
        void OnSixthLabFirst(void);
        void OnSeventhLabFirst(void);
    };
    
}

namespace Others {
    
    class UserInputController {
    public:
        UserInputController(void) = default;
        virtual ~UserInputController(void) = default;
    
        void OnOS5(void);
        void OnOS6(void);
    };
    
}

