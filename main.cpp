#include "UserInputController.hpp"
#include <clocale>

int main(int argc, char** argv) {
    std::setlocale(LC_ALL,"Russian_Russia.1251");
    
    srand(static_cast<unsigned int>(time(NULL)));
    
    bool run = true;
    Programming::UserInputController inputProgramming;
    SAOD::UserInputController inputSAOD;
    Others::UserInputController inputOthers;
    do {
        int labNumber = 0;
        std::cout << "Введите номер задания: ";
        std::cin >> labNumber;
        switch (labNumber) {
            case 0:
                run = false;
                continue;
            // ====================
            // Others
            // ====================
            case 1:
                inputOthers.OnOS5();
                break;
            case 2:
                inputOthers.OnOS6();
                break;
            // ====================
            // SAOD
            // ====================
            case -11:
                inputSAOD.OnFirstLabFirst();
                break;
            case -21:
                inputSAOD.OnSecondLabFirst();
                break;
            case -31:
                inputSAOD.OnThirdLabFirst();
                break;
            case -41:
                inputSAOD.OnFourthLabFirst();
                break;
            case -51:
                inputSAOD.OnFifthLabFirst();
                break;
            case -61:
                inputSAOD.OnSixthLabFirst();
                break;
            case -71:
                inputSAOD.OnSeventhLabFirst();
                break;
            // ====================
            // programming
            // ====================
            case 11:
                inputProgramming.OnFirstLabFirst();
                break;
            case 12:
                inputProgramming.OnFirstLabSecond();
                break;
            case 13:
                inputProgramming.OnFirstLabThird();
                break;
            case 21:
                inputProgramming.OnSecondLabFirst();
                break;
            case 22:
                inputProgramming.OnSecondLabSecond();
                break;
            case 31:
                inputProgramming.OnThirdLabFirst();
                break;
            case 32:
                inputProgramming.OnThirdLabSecond();
                break;
            case 41:
                inputProgramming.OnFourthLabFirst();
                break;
            case 42:
                inputProgramming.OnFourthLabSecond();
                break;
            case 43:
                inputProgramming.OnFourthLabThird();
                break;
            case 51:
                inputProgramming.OnFifthLabFirst();
                break;
            case 61:
                inputProgramming.OnSixthLabFirst();
                break;
            case 62:
                inputProgramming.OnSixthLabSecond();
                break;
            default:
                std::cout << "Некорректный номер задания" << std::endl;
                break;
        }
    } while (run);
}
