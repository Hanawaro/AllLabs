#include "UserInputController.hpp"

    namespace Programming {
    /**
        Описать динамический массив целых чисел (количество элементов указывает пользователь), для выделения памяти использовать операцию new, для очищения памяти использовать delete
     
        Все данные передаются в функции в виде параметров, глобальные переменные использовать запрещено; все дальнейшие пункты требований реализованы в виде отдельной функции
     
        Заполнить массив в зависимости от выбора способа пользователем:
            a. случайными числами (отдельная функция с аргументами: указатель на массив, количество элементов (по умолчанию 10)
            b. Вручную
            c. Из файла (имя файла вводит пользователь)
     
        Выполнить сортировку массива

        Выполнить действия согласно варианту
            "Удалить из массива отрицательные элементы"

        Результат вывести на экран и сохранить в файл (описать функцию сохранения массива в файл с аргументами: массив, количество элементов, имя файла)
    */
    void UserInputController::OnFirstLabFirst(void) {
        
        using namespace FirstLab::First;
        Task task;
        
        std::cout << " Введите режим чтения данных:\n" <<
                     "  1. Случайными числами\n" <<
                     "  2. Ручным вводом\n" <<
                     "  3. Из файла\n" <<
                     " ~ ";
        
        int type = 0;
        readData<int>(type, "", "  Неверный режим чтения", [](int data) { return data >= 1 && data <= 3; } );
        
        switch (type) {
            case 1:
                {
                    int size = 0;
                    readData<int>(size, " Введите размер массива: ", "  Неверный размер массива", [](int data) { return data > 0; } );
                    int left = 0;
                    readData<int>(left, " Введите меньшую границу: ", "", [](int data) { return true; } );
                    int right = 0;
                    readData<int>(right, " Введите большую границу: ", "  Неверный промежуток", [=](int data) { return data > left; } );
                    task.DoRand(size, left, right);
                }
                break;
            case 2:
                task.DoHand();
                break;
            case 3:
                {
                    std::string name;
                    readData<std::string>(name, " Введите имя файла: ", "  Некорректное имя", [](std::string data) { return data.size(); });
                    task.DoFile(name);
                }
                break;
        }
    }

    /**
        Выполнить средствами STL vector в отдельной программе
     
        Все данные передаются в функции в виде параметров, глобальные переменные использовать запрещено; все дальнейшие пункты требований реализованы в виде отдельной функции
        
           Заполнить массив в зависимости от выбора способа пользователем:
               a. случайными числами (отдельная функция с аргументами: указатель на массив, количество элементов (по умолчанию 10)
               b. Вручную
               c. Из файла (имя файла вводит пользователь)
        
           Выполнить сортировку массива

           Выполнить действия согласно варианту
               "Удалить из массива отрицательные элементы"

           Результат вывести на экран и сохранить в файл (описать функцию сохранения массива в файл с аргументами: массив, количество элементов, имя файла)
    */
    void UserInputController::OnFirstLabSecond(void) {
        using namespace FirstLab::Second;
        Task task;
        
        std::cout << " Введите режим чтения данных:\n" <<
                     "  1. Случайными числами\n" <<
                     "  2. Ручным вводом\n" <<
                     "  3. Из файла\n" <<
                     " ~ ";
        
        int type = 0;
        readData<int>(type, "", "  Неверный режим чтения", [](int data) { return data >= 1 && data <= 3; } );
        
        switch (type) {
            case 1:
                {
                    int size = 0;
                    readData<int>(size, " Введите размер вектора: ", "  Неверный размер вектора", [](int data) { return data > 0; } );
                    int left = 0;
                    readData<int>(left, " Введите меньшую границу: ", "", [](int data) { return true; } );
                    int right = 0;
                    readData<int>(right, " Введите большую границу: ", "  Неверный промежуток", [=](int data) { return data > left; } );
                    task.DoRand(size, left, right);
                }
                break;
            case 2:
                task.DoHand();
                break;
            case 3:
                {
                    std::string name;
                    readData<std::string>(name, " Введите имя файла: ", "  Некорректное имя", [](std::string data) { return data.size(); });
                    task.DoFile(name);
                }
                break;
        }
    }

    /**
        Дан массив целых чисел. Сравнить по модулю сумму элементов, стоящих на четных местах массива, с суммой элементов, стоящих на нечетных местах. Вычислить среднее геометрическое элементов массива
    */
    void UserInputController::OnFirstLabThird(void) {
        using namespace FirstLab::Third;
        Task task;
        
        int size = 0;
        int left = 0, right = 0;
        readData<int>(size, " Введите размер массива: ", "  Некорректный размер", [](int data) { return data > 0; });
        readData<int>(left, " Введите левую границу рандома: ", "", [](int data) { return true; });
        readData<int>(right, " Введите правую границу рандома: ", "  Некорректный промежуток", [=](int data) { return data > left; });
        
        task.Start({static_cast<uint32_t>(size), left, right});
    }


    /**
        Book: Автор, Название, Издательство, Год, Количество страниц. Создать массив объектов. Вывести:
          а) список книг заданного автора;
          б) список книг, выпущенных заданным издательством;
          в) список книг, выпущенных после заданного года.
    */
    void UserInputController::OnSecondLabFirst(void) {
        
        using namespace SecondLab::First;
        Task task;
        
        std::cout << " Введите режим чтения данных:\n" <<
                     "  1. Случайными значениями\n" <<
                     "  2. Ручным вводом\n" <<
                     " ~ ";
        
        int typeInput = 0;
        readData<int>(typeInput, "", "  Неверный режим чтения", [](int data) { return data >= 1 && data <= 2; } );
        
        switch (typeInput) {
            case 1:
                {
                    DataManager manager;
                    int size = 0;
                    readData<int>(size, " Введите количество книг: ", "  Неправильное количество", [](int data) { return data > 0; } );
                    task.SetBooksLibrary(manager.GetRandomData(size));
                }
                break;
            case 2:
                {
                    DataManager manager;
                    int size = 0;
                    readData<int>(size, " Введите количество книг: ", "  Неправильное количество", [](int data) { return data > 0; } );
                    for (int i = 0; i < size; i++) {
                        std::string name;
                        readData<std::string>(name, " Введите название книги: ", "  Некорректное название книги", [](std::string data) { return data.size(); } );
                        
                        std::string author;
                        readData<std::string>(author, " Введите автора книги: ", "  Некорректное имя автора книги", [](std::string data) { return data.size(); } );
                        
                        int date = 0;
                        readData<int>(date, " Введите год написания книги: ", "  Некорректная дата", [](int data) { return data > 0; } );
                        
                        int pages = 0;
                        readData<int>(pages, " Введите количество страниц книги: ", "  Некорректное количество страниц", [](int data) { return data > 0; } );
                        
                        manager.AddDataLine(Data(name, author, date, pages));
                    }
                    task.SetBooksLibrary(manager.GetData());
                }
                break;
        }
        
        std::cout << " Введите режим вывода данных:\n" <<
                     "  1. Все книги\n" <<
                     "  2. По автору\n" <<
                     "  3. По дате издания\n" <<
                     "  4. По количеству страниц\n" <<
                     " ~ ";
        
        int typeOutput = 0;
        readData<int>(typeOutput, "", "  Неверный режим вывода", [](int data) { return data >= 1 && data <= 3; } );
        
        switch (typeOutput) {
            case 1:
                task.DoWork([](const Data& data) { return true; });
                break;
            case 2:
                {
                    std::string author;
                    readData<std::string>(author, " Введите автора книги: ", "  Некорректное имя автора книги", [](std::string data) { return data.size(); } );
                    task.DoWork([&](const Data& data) { return data.Author == author; });
                }
                break;
            case 3:
                {
                    int date = 0;
                    readData<int>(date, " Введите год издания книги: ", "  Некорректный год издания", [](int data) { return data > 0; } );
                    task.DoWork([&](const Data& data) { return data.Date == date; });
                }
                break;
            case 4:
                {
                    int pages = 0;
                    readData<int>(pages, " Введите количество страниц книги: ", "  Некорректное количество страниц", [](int data) { return data > 0; } );
                    task.DoWork([&](const Data& data) { return data.Pages == pages; });
                }
                break;
        }
        
    }


    /**
        Разработать класс, реализующий алгоритм согласно варианту. Продемонстрировать работу алгоритма. Класс должен содержать конструкторы, деструкторы, обработку исключений.
     
        Построение приближающей функции методом наименьших квадратов 2 степени.
    */
    void UserInputController::OnSecondLabSecond(void) {
        
        using namespace SecondLab::Second;
        Task task;
        
        std::cout << " Введите режим чтения данных:\n" <<
                     "  1. Случайными значениями\n" <<
                     "  2. Ручным вводом\n" <<
                     " ~ ";
        
        int type = 0;
        readData<int>(type, "", "  Неверный режим чтения", [](int data) { return data >= 1 && data <= 2; } );
        
        switch (type) {
            case 1:
                {
                    PointsManager manager;
                    
                    int count = 0;
                    readData<int>(count, " Введите количество точек: ", "  Неверное количество", [](int data) { return data > 0; } );
                    double leftX = 0;
                    readData<double>(leftX, " Введите меньшую границу по X: ", "", [](double data) { return true; } );
                    double rightX = 0;
                    readData<double>(rightX, " Введите большую границу по X: ", "  Неверный промежуток", [=](double data) { return data > leftX; } );
                    double leftY = 0;
                    readData<double>(leftY, " Введите меньшую границу по Y: ", "", [](double data) { return true; } );
                    double rightY = 0;
                    readData<double>(rightY, " Введите большую границу по Y: ", "  Неверный промежуток", [=](double data) { return data > leftY; } );
                    
                    task.DoWork(manager.GetRandomPoints(count, leftX, rightX, leftY, rightY));
                }
                break;
            case 2:
                {
                    PointsManager manager;
                    
                    int count = 0;
                    readData<int>(count, " Введите количество точек: ", "  Неверное количество", [](int data) { return data > 0; } );
                    
                    std::cout << std::endl;
                    for (int i = 0; i < count; i++) {
                        std::cout << " Для " << i << " точки: " << std::endl;
                        double x = 0;
                        readData<double>(x, " Введите координату x: ", "", [](double data) { return true; } );
                        double y = 0;
                        readData<double>(y, " Введите координату y: ", "", [](double data) { return true; } );
                        manager.AddPoint({x, y});
                        std::cout << std::endl;
                    }
                    
                    task.DoWork(manager.GetPoints());
                }
                break;
        }
    }

    /**
        Определить класс «Квадратная матрица» – Matrix размерностью 3х3. Операции сложения, вычитания, умножения, умножения на число, метод вычисления суммы элементов главной диагонали. Разработать класс-вектор размерностью m, элементами которого являются матрицы. Реализовать сложение и вычитание таких векторов, проверить, все ли элементы первого вектора имеют большие суммы чисел по главной диагонали, чем элементы второго.
    */
    void UserInputController::OnThirdLabFirst(void) {
        using namespace ThirdLab::First;
        Task task;
        task.DoExample();
    }

    /**
        Разработать экзаменационную ведомость для группы. Создать несколько ведомостей для различных групп по нескольким предметам. Получать средний балл по предмету в группе, по предмету во всех группах, средний по группе и средний по факультету
    */
    void UserInputController::OnThirdLabSecond(void) {
        using namespace ThirdLab::Second;
        Task task;
        task.DoExample();
    }

    /**
        Создать класс студент, имеющий имя (указатель на строку), курс и идентификационный номер. Определить конструкторы, деструктор и функцию печати.

        Создать public-производный класс - студент-дипломник, имеющий тему диплома. Определить конструкторы по умолчанию и с разным числом параметров, деструкторы, функцию печати. Определить функции переназначения названия диплома и идентификационного номера. Написать программу, демонстрирующую все разработанные элементы класса.
    */
    void UserInputController::OnFourthLabFirst(void) {
        using namespace FourthLab::First;
        Task task;
        task.DoExample();
    }

        
    // remake
    /**
        Дан файл с информацией о платежах (дата, тип (кредит, коммунальный платеж, мобильный телефон), сумма, №отправителя, №получателя). Определить общее количество платежей по каждому типу. Найти максимальную сумму платежа для каждого типа.
    */
    void UserInputController::OnFourthLabSecond(void) {
        using namespace FourthLab::Second;
        Task task;
        std::string path;
        readData<std::string>(path, " Введите имя файла: ", "  Некорректное имя", [](std::string data) { return data.size(); });
        task.DoExample(path);
    }

    
    /**
        Удалить из текста все цифры. Подсчитать количество удаленных цифр. В заданном тексте заменить заданную последовательность символов на другую заданную последовательность символов.
    */
    void UserInputController::OnFourthLabThird(void) {
        using namespace FourthLab::Third;
        Task task;
        std::string path;
        readData<std::string>(path, " Введите имя файла: ", "  Некорректное имя", [](std::string data) { return data.size(); });
        if (!task.LookFile(path)) return;
        
        std::cout << " Выберите задание:\n" <<
                     "  1. Удалить и посчитать все цифры\n" <<
                     "  2. Заменить строку на свою подстроку\n" <<
                     " ~ ";
        int type = 0;
        readData<int>(type, "", "  Неверный режим чтения", [](int data) { return data >= 1 && data <= 2; } );
        
        switch (type) {
            case 1:
                task.Remove();
                break;
            case 2:
                {
                    std::string line;
                    readData<std::string>(line, " Введите подстроку: ", "  Некорректная страка", [](std::string data) { return data.size(); });
                    
                    std::string substring;
                    readData<std::string>(substring, " Введите подстроку: ", "  Некорректная страка", [](std::string data) { return data.size(); });
                    
                    task.Replace(line, substring);
                }
                break;
        }
    }

    // remake
    /**
        Печатное издание – Твердая обложка, мягкая обложка, журнал, черно-белая брошюра. Функция расчета стоимости N экземпляров, где стоимость одного экземпляра зависит от количества страниц:

        a. Тв. обл. = 10*кол.стр +200
        b. Мяг. Обл. =8*кол.стр +50
        c. Журнал = 12*кол.стр+125
        d. Ч.б. = 5*кол.стр+17

        Определить стоимость партии из А,В,С и Е экземпляров описанных типов изданий соответственно
    */
    void UserInputController::OnFifthLabFirst(void) {
        using namespace FifthLab::First;
        Task task;
        int count = 0;
        readData<int>(count, " Введите количество книг: ", "  Некорректное количество книг", [](int data) { return data > 0; });
        std::cout << " Выберите тип книги и количество страниц:\n" <<
                     "  1. Твердая обложка\n" <<
                     "  2. Магкая обложка\n" <<
                     "  3. Журнал\n" <<
                     "  4. Брошюра\n" << std::endl;
        for (int i = 0; i < count; i++) {
            std::cout << " Для " << i + 1 << " книги: " << std::endl;
            int type = 0;
            readData<int>(type, "  Введите тип книги: ", "  Некорректный тип", [](int data) { return data > 0 && data <= static_cast<int>(Task::Type::Amount); });
            int pages = 0;
            readData<int>(pages, "  Введите количество страниц: ", "  Некорректное количество страниц", [](int data) { return data > 0; });
            std::cout << std::endl;
            switch (type) {
                case 1:
                    task.push_back(new HardCover(pages));
                    break;
                case 2:
                    task.push_back(new SoftCover(pages));
                    break;
                case 3:
                    task.push_back(new Magazine(pages));
                    break;
                case 4:
                    task.push_back(new Brochure(pages));
                    break;
            }
            
        }
        
        task.DoExample();
    }
        
    void UserInputController::OnSixthLabFirst(void) {
        using namespace Programming::SixthLab::First;
        Task<int> task;
        DeepVector<int> vec;
        
        int countLine = 0;
        readData<int>(countLine, "  Введите количество строк: ", "  Некорректные данные", [](int data) { return data > 0; });
        std::cin.get();
        
        std::string lineData;
        for (int i = 0; i < countLine; i++) {
            std::cout << "  ";
            std::getline(std::cin, lineData);
            std::stringstream ss(lineData);
            vec.push_line_back({});
            int tmp = 0;
            while (ss >> tmp)
                vec.push_element_back(tmp, i);
        }
        
        task.DoExample(vec);
    }
        
    void UserInputController::OnSixthLabSecond(void) {
        using namespace Programming::SixthLab::Second;
        Task task;
        RandomBookManager rdBook;
        
        int countFirst = 0;
        readData<int>(countFirst, "  Введите количество книг (1): ", "  Некорректные данные", [](int data) { return data > 0; });
        std::deque<Book> f;
        for (int i = 0; i < countFirst; i++)
            f.push_back(rdBook.GetBook());
        
        int countSecond = 0;
        readData<int>(countSecond, "  Введите количество книг (2): ", "  Некорректные данные", [](int data) { return data > 0; });
        std::deque<Book> s;
        for (int i = 0; i < countSecond; i++)
            s.push_back(rdBook.GetBook());
        
        int index = 0;
        readData<int>(index, "  Введите индекс: ", "  Некорректные данные", [&](int data) { return data >= 0 && data < f.size(); });
        
        int count = 0;
        readData<int>(count, "  Введите количество: ", "  Некорректные данные", [&](int data) { return data >= 0 && data + index <= f.size(); });
        
        task.DoExample(f, s, index, count, [](Book& f, Book& s) { return f.pages < s.pages; });
    }
        
    // LAST TO THIS PROGRAMMING

}

namespace SAOD {
    
    void UserInputController::OnFirstLabFirst(void) {
        using namespace FirstLab::First;
        Task task;
        std::cout << " Выберите метод сортировки:\n" <<
                     "  1. n*logn без памяти\n" <<
                     "  2. n*logn с памятью\n" <<
                     " ~ ";
        int type = 0;
        readData<int>(type, "", "  Неверный метод", [](int data) { return data >= 1 && data <= 2; } );
        std::cin.get();
        
        switch (type) {
            case 1:
            {
                Task::QuickData qData;
                std::cout << " Введите данные: " << std::endl;
                FillData(qData);
                task.DoWork(qData);
                break;
            }
            case 2:
            {
                Task::SlowData sData;
                std::cout << " Введите данные: " << std::endl;
                FillData(sData);
                task.DoWork(sData);
                break;
            }
        }
    }
    
    void UserInputController::FillData(FirstLab::First::Task::QuickData& data) {
        std::cout << "  ";
        FillQuick(data);
        std::cout << "  ";
        FillQuick(data);
        std::cout << "  ";
        FillQuick(data);
    }
    
    void UserInputController::FillData(FirstLab::First::Task::SlowData& data) {
        std::cout << "  ";
        FillSlow(data.get_first());
        std::cout << "  ";
        FillSlow(data.get_second());
        std::cout << "  ";
        FillSlow(data.get_third());
    }
    
    void UserInputController::FillQuick(FirstLab::First::Task::QuickData& data) {
        std::string lineData;
        std::getline(std::cin, lineData);
        std::stringstream ss(lineData);
        
        if (!data.get_size().first) {
            double tmp;
            while (ss >> tmp) {
                data.push_first(tmp);
            }
        } else if (!data.get_size().second) {
            double tmp;
            while (ss >> tmp) {
                data.push_second(tmp);
            }
        } else if (!data.get_size().third) {
            double tmp;
            while (ss >> tmp) {
                data.push_third(tmp);
            }
        }
    }
    
    void UserInputController::FillSlow(std::vector<double>& vec) {
        std::string lineData;
        std::getline(std::cin, lineData);
        std::stringstream ss(lineData);
        double tmp;
        while (ss >> tmp) {
            vec.push_back(tmp);
        }
    }
    
    
    void UserInputController::OnSecondLabFirst(void) {
        using namespace SecondLab::First;
        Task task;
        
        std::string inPath;
        readData<std::string>(inPath, " Введите имя файла с текстом: ", "  Некорректное имя", [](std::string data) { return data.size(); });
        
        std::string outPath;
        readData<std::string>(outPath, " Введите имя нового файла: ", "  Некорректное имя", [](std::string data) { return data.size(); });
        
        std::wstring limiter;
        wreadData<std::wstring>(limiter, " Введите разграничитель: ", "  Некорректное имя", [](std::wstring data) { return data.size(); });
        
        task.DoWork(inPath, outPath, limiter);
    }
    
    void UserInputController::OnThirdLabFirst(void) {
        using namespace ThirdLab::First;
        Task task;
        task.DoExample();
    }
    
    void UserInputController::OnFourthLabFirst(void) {
        using namespace FourthLab::First;
        Task task;
        task.DoWork();
    }
    
    void UserInputController::OnFifthLabFirst(void) {
        using namespace FifthLab::First;
        Task task;
        task.DoExample();
    }
    
    void UserInputController::OnSixthLabFirst(void) {
        using namespace SixthLab::First;
        Task task;
        task.DoExample();
    }
    
    void UserInputController::OnSeventhLabFirst(void) {
        using namespace Seventh::First;
        Task task;
        task.DoExample();
    }
    
    // LAST TO THIS SAOD
}


namespace Others {
    
    void UserInputController::OnOS5(void) {
        OS5::Task task;
        
        const int typeOffet = 1;
        
        int countProcesses = 0;
        readData<int>(countProcesses, " Введите количество процессов: ", "  Некорректное количество", [](int data) { return data > 0; });
        
        std::cout << " Выберите способ ввода:\n" <<
                     "  1. Ручной ввод\n" <<
                     "  2. Случайными значениями\n" <<
                     " ~ ";
        int inputType = 0;
        readData<int>(inputType, "", "  Неверный способ", [&](int data) {
            return data - typeOffet >= 0 && data - typeOffet < static_cast<int>(OS5::Task::InputType::Count);
        });
        
        task.SetData(countProcesses, static_cast<OS5::Task::InputType>(inputType - typeOffet));
        
        std::cout << " Выберите алгоритм:\n" <<
                     "  1. FB\n" <<
                     "  2. SJF\n" <<
                     " ~ ";
        int alrorithmType = 0;
        readData<int>(alrorithmType, "", "  Неверный алгортм", [&](int data) {
            return data - typeOffet >= 0 && data - typeOffet < static_cast<int>(OS5::Task::AlgorithmType::Count);
        });
        
        OS5::Task::AlgorithmType type = static_cast<OS5::Task::AlgorithmType>(alrorithmType - typeOffet);
        switch (type) {
            case OS5::Task::AlgorithmType::FB:
                task.DoFB();
                break;
            case OS5::Task::AlgorithmType::SJF:
                task.DoSJF();
                break;
            default:
                throw std::runtime_error("unknown algorithm type");
                break;
        }
    }
    
    void UserInputController::OnOS6(void) {
        OS6::Task task;
        
        std::cin.get();
        task.DoExample();
    }
    
    // LAST TO THIS OTHER
}
