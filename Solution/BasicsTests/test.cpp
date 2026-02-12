#include "pch.h"
#include "handbook_tasks.h"

#include <sstream> // Для std::stringstream
#include <streambuf> // Для std::streambuf
#include <array>

class MyClassTest : public ::testing::Test {
protected:

    // Объект класса для тестов

    // Дополнительные ресурсы

    // Оригинальные буферы std::cin и std::cout
    std::streambuf* originalCinBuffer;

    std::streambuf* originalCoutBuffer;
    // Строковые потоки для захвата вывода и подачи ввода
    std::stringstream testInputStream;
    std::stringstream testOutputStream;

    // Настройка перед каждым тестом
    void SetUp() override {

        // Инициализация объекта с параметрами

        
        // Сохраняем оригинальные буферы
        originalCinBuffer = std::cin.rdbuf();
        originalCoutBuffer = std::cout.rdbuf();

        // Перенаправляем std::cin на наш входной поток
        std::cin.rdbuf(testInputStream.rdbuf());
        // Перенаправляем std::cout на наш выходной поток
        std::cout.rdbuf(testOutputStream.rdbuf());
    }

    // Очистка после каждого теста
    void TearDown() override {
        // Восстанавливаем оригинальные буферы std::cin и std::cout
        std::cin.rdbuf(originalCinBuffer);
        std::cout.rdbuf(originalCoutBuffer);

        // Очищаем буфер
        testInputStream.str("");
        testInputStream.clear();

        testOutputStream.str("");
        testOutputStream.clear();

    }

    // Вспомогательные методы
    void simulate_input(const std::string& input) {
        std::istringstream test_input(input);
        std::streambuf* orig_cin = std::cin.rdbuf(test_input.rdbuf());
        // Ввод будет автоматически использован в тесте
    }
};

namespace TestFirstSteps
{
    class ClassFirstSteps : public MyClassTest {
    protected:

        // Объект класса для тестов
        Basics::FirstSteps test_object;

        // Настройка перед каждым тестом
        void SetUp() override {
            // Инициализация объекта с параметрами
            test_object = Basics::FirstSteps();
            MyClassTest::SetUp();
            
        }

        // Очистка после каждого теста
        void TearDown() override {
            MyClassTest::TearDown();
        }

    };

    TEST_F(ClassFirstSteps, A)
    {
        test_object.a();
        const std::string res = "C++ is a general-purpose programming language with a bias towards systems programming that\n  - is a better C\n  - supports data abstraction\n  - supports object-oriented programming\n  - supports generic programming.\n";
        EXPECT_EQ(testOutputStream.str(), res);
    }
    TEST_F(ClassFirstSteps, B)
    {
        const int a = 4, b = 5;

        test_object.b(a, b);
        EXPECT_EQ(testOutputStream.str(), std::to_string(a + b) + '\n');
    }

};

namespace TestDataTypes
{

    class ClassDataTypes : public MyClassTest {
    protected:

        // Объект класса для тестов
        Basics::DataTypes test_object;

        // Настройка перед каждым тестом
        void SetUp() override {
            // Инициализация объекта с параметрами
            test_object = Basics::DataTypes();
            MyClassTest::SetUp();

        }

        // Очистка после каждого теста
        void TearDown() override {
            MyClassTest::TearDown();
        }
    };

    TEST_F(ClassDataTypes, A)
    {
        ASSERT_NEAR(test_object.a(1.1), 0.433071, 0.0001);
    }

    TEST_F(ClassDataTypes, B)
    {
        EXPECT_EQ(test_object.b(10), 55);
        EXPECT_EQ(test_object.b(100), 5050);
    }

};

namespace TestBranchesAndCycles
{
    class ClassBranchesAndCycles : public MyClassTest {
    protected:

        // Объект класса для тестов
        Basics::BranchesAndCycles test_object;

        // Настройка перед каждым тестом
        void SetUp() override {
            // Инициализация объекта с параметрами
            test_object = Basics::BranchesAndCycles();
            MyClassTest::SetUp();

        }

        // Очистка после каждого теста
        void TearDown() override {
            MyClassTest::TearDown();
        }

    };
    TEST_F(ClassBranchesAndCycles, A)
    {
        EXPECT_EQ(test_object.a(1, 1, 2, 2), "YES");
        EXPECT_EQ(test_object.a(1, 1, 2, 3), "NO");
        EXPECT_EQ(test_object.a(5, 6, 3, 3), "NO");
    }

    TEST_F(ClassBranchesAndCycles, B)
    {
        EXPECT_EQ(test_object.b(3, 4, 10), "UNDEFINED");
        EXPECT_EQ(test_object.b(3, 4, 5), "YES");
    }

    TEST_F(ClassBranchesAndCycles, C)
    {
        EXPECT_EQ(test_object.c(2003), "NO");
        EXPECT_EQ(test_object.c(2004), "YES");
        EXPECT_EQ(test_object.c(3000), "NO");
    }

    TEST_F(ClassBranchesAndCycles, D)
    {
        EXPECT_EQ(test_object.d(1, 2001), 31);
        EXPECT_EQ(test_object.d(2, 2001), 28);
    }

    TEST_F(ClassBranchesAndCycles, E)
    {
        test_object.e(7, 31);
        const std::string expected_output = "                   1 \n 2  3  4  5  6  7  8 \n 9 10 11 12 13 14 15 \n16 17 18 19 20 21 22 \n23 24 25 26 27 28 29 \n30 31 ";
        EXPECT_EQ(testOutputStream.str(), expected_output);
    }

    TEST_F(ClassBranchesAndCycles, F)
    {
        EXPECT_EQ(test_object.f(59), 14);
        EXPECT_EQ(test_object.f(11), 2);
    }

    TEST_F(ClassBranchesAndCycles, G)
    {
        ASSERT_NEAR(test_object.g(3), 0.833333, 0.0001);
        ASSERT_NEAR(test_object.g(2), 0.5, 0.0001);
        ASSERT_NEAR(test_object.g(1), 1.0, 0.0001);
    }

};

namespace TestVectorsAndStrings
{
    class ClassVectorsAndStrings : public MyClassTest {
    protected:

        // Объект класса для тестов
        Basics::VectorsAndStrings test_object;

        // Настройка перед каждым тестом
        void SetUp() override {
            // Инициализация объекта с параметрами
            test_object = Basics::VectorsAndStrings();
            MyClassTest::SetUp();

        }

        // Очистка после каждого теста
        void TearDown() override {
            MyClassTest::TearDown();
        }

    };

    TEST_F(ClassVectorsAndStrings, A)
    {
        const std::string password = "Vasya123";
        EXPECT_EQ(test_object.a(password), "YES");

        const std::string password_no = "Vasya123\n";
        EXPECT_EQ(test_object.a(password_no), "NO");
    }

    TEST_F(ClassVectorsAndStrings, B)
    {
        const std::string word_one = "ammonium";
        EXPECT_EQ(test_object.b(word_one), "a500");

        const std::string word_two = "implementation";
        EXPECT_EQ(test_object.b(word_two), "i514");
    }

    TEST_F(ClassVectorsAndStrings, C)
    {
        std::vector<unsigned int> vec = { 1, 2, 3, 5, 4 };
        std::vector<unsigned int> res = { 1, 2, 3, 5, 4 };
        EXPECT_EQ(test_object.c(vec), res);

        vec = { 11, 6, 8, 2, 10, 9, 4, 7, 3, 1, 5 };
        res = { 10, 4, 9, 7, 11, 2, 8, 3, 6, 5, 1 };
        EXPECT_EQ(test_object.c(vec), res);
    }

    TEST_F(ClassVectorsAndStrings, D)
    {
        std::vector<std::string> vec = { "one", "two", "three" };
        std::vector<std::string> res = { "two", "three", "one" };
        EXPECT_EQ(test_object.d(vec), res);
    }

    TEST_F(ClassVectorsAndStrings, E)
    {
        std::string input = "hello world";
        EXPECT_EQ(test_object.e(input), "NO");

        input = "never odd or even";
        EXPECT_EQ(test_object.e(input), "YES");
    }

    TEST_F(ClassVectorsAndStrings, F)
    {
        const std::vector<std::vector<unsigned int>> input = {
            {1, 1},
            {2, 2} };
        const std::string res = "* 2\n2 *\n1 1\n";
        EXPECT_EQ(test_object.f(3, 2, 2, input), res);
    }

}

namespace TestFunctions
{
    class ClassFunctions : public MyClassTest {
    protected:

        // Объект класса для тестов
        Basics::Functions test_object;

        // Настройка перед каждым тестом
        void SetUp() override {
            // Инициализация объекта с параметрами
            test_object = Basics::Functions();
            MyClassTest::SetUp();

        }

        // Очистка после каждого теста
        void TearDown() override {
            MyClassTest::TearDown();
        }

    };

    TEST_F(ClassFunctions, MatrixArgMax)
    {
        const std::vector<std::vector<int>> case_one = {
                                {0, 3, 2, 4},
                                {2, 3, 5, 5},
                                {5, 1, 2, 3}
        };
        const std::pair<size_t, size_t> res_one = { 1,2 };

        EXPECT_EQ(test_object.MatrixArgMax(case_one), res_one);

        const std::vector<std::vector<int>> case_two = { {1} };
        const std::pair<size_t, size_t> res_two = { 0, 0 };

        EXPECT_EQ(test_object.MatrixArgMax(case_two), res_two);

        const std::vector<std::vector<int>> input = {
                                {1, 2, 3, 4, 5},
                                {6, 7, 8, 9, 10},
                                {11, 12, 13, 14, 15}
        };
        const std::pair<size_t, size_t> res = { 2, 4 };

        EXPECT_EQ(test_object.MatrixArgMax(input), res);
    }

    TEST_F(ClassFunctions, CommonPrefix)
    {
        const std::vector<std::string> case_one = {
                                "apple",
                                "apricot" ,
                                "application"
        };
        const std::string res_one = "ap";
        EXPECT_EQ(test_object.CommonPrefix(case_one), res_one);

        const std::vector<std::string> case_two = { };
        const std::string res_two = "";
        EXPECT_EQ(test_object.CommonPrefix(case_two), res_two);
    }


    TEST_F(ClassFunctions, Split)
    {
        const std::string case_one = "What_is_your_name?";

        const std::vector<std::string> res_one = { "What",
                                                    "is",
                                                    "your",
                                                    "name?"};

        EXPECT_EQ(test_object.Split(case_one, '_'), res_one);
    }

    TEST_F(ClassFunctions, Join)
    {
        const std::vector<std::string> case_one = { "What", "is", "your", "name?" };

        const std::string res_one = "What_is_your_name?";

        EXPECT_EQ(test_object.Join(case_one, '_'), res_one);
    }

    TEST_F(ClassFunctions, Transpose)
    {
        const std::vector<std::vector<int>> case_one = { {1, 2, 3},
                                                        {4, 5, 6},
                                                        {7, 8, 9} };

        const std::vector<std::vector<int>> res_one = { {1, 4, 7},
                                                        {2, 5, 8},
                                                        {3, 6, 9} };
        EXPECT_EQ(test_object.Transpose(case_one), res_one);

        const std::vector<std::vector<int>> case_two = { {1, 2, 3},
                                                        {4, 5, 6}, };

        const std::vector<std::vector<int>> res_two = { {1, 4},
                                                        {2, 5},
                                                        {3, 6} };
        EXPECT_EQ(test_object.Transpose(case_two), res_two);
    }

    TEST_F(ClassFunctions, F)
    {
        std::vector<std::pair<int, int>> coords = { {2 ,3}, {1, 2} };

        std::vector<std::pair<int, int>> res = { {1, 2} , {2 ,3} };

        test_object.F(coords);

        EXPECT_EQ(coords, res);
    }

};

namespace TestSequenceContainers
{
    class ClassSequenceContainers : public MyClassTest {
    protected:

        // Объект класса для тестов
        HandbookSTL::SequenceContainers test_object;

        // Настройка перед каждым тестом
        void SetUp() override {
            // Инициализация объекта с параметрами
            test_object = HandbookSTL::SequenceContainers();
            MyClassTest::SetUp();

        }

        // Очистка после каждого теста
        void TearDown() override {
            MyClassTest::TearDown();
        }

    };

    TEST_F(ClassSequenceContainers, Print)
    {
        const std::string case_one = "hello";
        const std::string delimiter = ", ";

        const std::string res = "h, e, l, l, o\n";

        test_object.Print(case_one, delimiter);
        EXPECT_EQ(testOutputStream.str(), res);

        //// Очищаем буфер
        testOutputStream.str("");
        testOutputStream.clear();

        const std::vector<int> case_two = { 1, 2, 3, 4 };

        const std::string res_two = "1, 2, 3, 4\n";

        test_object.Print(case_two, delimiter);
        EXPECT_EQ(testOutputStream.str(), res_two);
    }

    TEST_F(ClassSequenceContainers, B)
    {
        const std::vector <std::pair<std::string, std::string>> students_entries = { {"Ivanov", "top"}, {"Petrov", "top"}, {"Sidorov", "bottom"} };
        const std::vector<int> students_order = { 1, 3 };
        const std::vector<std::string> result_case_one = { "Petrov", "Sidorov" };

        EXPECT_EQ(test_object.B(students_entries, students_order),
            result_case_one);

    }

    TEST_F(ClassSequenceContainers, MakeTrain)
    {
        const std::vector<std::string> input = { "+left 1",
                                                    "+right 2",
                                                    "+left 3",
                                                    "-right 1" };

        // Подготавливаем входные данные для std::cin
        for (const auto& val : input)
            testInputStream << val;

        // Вызываем логику программы, которая будет использовать перенаправленные потоки
        test_object.MakeTrain();

        // Получаем захваченный вывод из std::cout
        std::string actualOutput = testOutputStream.str();

        // Проверяем ожидаемый вывод
        // Обратите внимание на точные символы новой строки и пробелы
        const std::string expectedOutput = "3 1 \n";
        EXPECT_EQ(expectedOutput, actualOutput);
    }

    TEST_F(ClassSequenceContainers, CtrlXV)
    {
        const std::vector<std::string> case_one_text = { "program",
                                                            "is awesome",
                                                            "My",
                                                            "is awful" };
        const std::vector<std::string> case_one_commands = { "Down",
                                                                "Down",
                                                                "Down",
                                                                "Ctrl+X",
                                                                "Up",
                                                                "Ctrl+X",
                                                                "Up",
                                                                "Up",
                                                                "Ctrl+V" };

        const std::list<std::string> case_one_result = { "My",
                                                            "program",
                                                            "is awesome" };


        EXPECT_EQ(test_object.CtrlXV(case_one_text, case_one_commands),
            case_one_result);

        const std::vector<std::string> case_two_text = { "copy",
                                                            "paste" };
        const std::vector<std::string> case_two_commands = { "Ctrl+X",
                                                                "Ctrl+V",
                                                                "Ctrl+V",
                                                                "Ctrl+V",
                                                                "Ctrl+X",
                                                                "Ctrl+V",
                                                                "Ctrl+V",
                                                                "Ctrl+V" };

        const std::list<std::string> case_two_result = { "copy",
                                                            "copy",
                                                            "copy",
                                                            "paste",
                                                            "paste",
                                                            "paste" };


        EXPECT_EQ(test_object.CtrlXV(case_two_text, case_two_commands),
            case_two_result);
    }

    TEST_F(ClassSequenceContainers, CtrlXV2)
    {

        typedef struct test_case
        {
            std::vector<std::string> text;
            std::vector<std::string> commands;
            std::list<std::string> result;
        }test_case_t;

        std::vector<test_case_t> cases =
        {
            {
                .text = {
                    "My",
                    "program",
                    "is",
                    "awful",
                    "bad",
                    "poor",
                    "wrong",
                    "awesome" 
                },
                .commands = {
                    "Down",
                    "Down",
                    "Down",
                    "Shift",
                    "Down",
                    "Down",
                    "Down",
                    "Down",
                    "Ctrl+X" 
                },
                .result = { 
                    "My",
                    "program",
                    "is",
                    "awesome" 
                }
            },
            {
                .text = {   
                    "program",
                    "is awesome",
                    "My",
                    "is awful" 
                },
                .commands = {  
                    "Down",
                    "Down",
                    "Down",
                    "Ctrl+X",
                    "Up",
                    "Ctrl+X",
                    "Up",
                    "Up",
                    "Ctrl+V" 
                },
                .result = {
                    "My",
                    "program",
                    "is awesome"
                },
            },
            {
                .text = {  
                    "a",
                    "b",
                    "c",
                    "d",
                    "e",
                    "f",
                    "g"
                },
                .commands = {  
                    "Down",
                    "Shift",
                    "Down",
                    "Down",
                    "Ctrl+X",
                    "Down",
                    "Shift",
                    "Down",
                    "Down",
                    "Down",
                    "Ctrl+V" 
                },
                .result = {
                    "a",
                    "d",
                    "b",
                    "c"
                },
            }
        };
        size_t counter = 0;
        for(const auto &test_case : cases)
        {
            EXPECT_EQ(test_object.CtrlXV2(test_case.text, test_case.commands),
                test_case.result) << "Data set number: " << counter << std::endl;
            counter++;
        }

    }
}

namespace TestAssociationContainers
{
    class ClassAssociationContainers : public MyClassTest
    {
    protected:

        // Объект класса для тестов
        HandbookSTL::AssociationContainers test_object;

        // Настройка перед каждым тестом
        void SetUp() override {
            // Инициализация объекта с параметрами
            test_object = HandbookSTL::AssociationContainers();
            MyClassTest::SetUp();

        }

        // Очистка после каждого теста
        void TearDown() override {
            MyClassTest::TearDown();
        }
    };

    TEST_F(ClassAssociationContainers, A)
    {
        const std::vector<int> case_one = { 1, 2, 1, 2, 2, 1, 6 };
        const std::vector<std::string> expected_one = { "NO", "NO", "YES", "YES", "YES", "YES", "NO" };
        EXPECT_EQ(test_object.A(case_one), expected_one);
    }

    TEST_F(ClassAssociationContainers, B)
    {
        const std::vector<std::string> case_one = { "apple", "peach" };
        
        EXPECT_EQ(test_object.B(case_one), "aep");
    }

    TEST_F(ClassAssociationContainers, C)
    {
        const std::vector<std::string> case_one = { "/docs/README.txt",
                                                    "/docs/LICENSE.txt",
                                                    "/boot/grub",
                                                    "/init" };

        std::set<std::string> answer_one = {  "/",
                                                    "/boot/",
                                                    "/docs/" };

        EXPECT_EQ(test_object.C(case_one), answer_one);
    }

    TEST_F(ClassAssociationContainers, D)
    {
        const std::vector<std::pair<int, std::string>> case_one = { {10, "derivative"},
                                                    {2, "function"},
                                                    {10, "function"},
                                                    {10, "function"},
                                                    {7, "limit"} 
        };

        const std::map<int, std::set<std::string>> answer_one = { {2, {"function"} },
                                                        {7, {"limit"}},
                                                        {10, {"derivative", "function"} }
        };

        EXPECT_EQ(test_object.D(case_one), answer_one);
    }

    TEST_F(ClassAssociationContainers, E)
    {
        const std::vector<std::string> case_one = { "to", "be", "or", "not", "to", "be"};

        const int NUMBER = 2;

        const std::vector<std::pair<std::string, int>> answer_one = { {"be", 2},
                                                        {"to", 2},
                                                        { "no", 1 },
                                                        { "or", 1 },
                                                        { "ot", 1 } 
        };

        EXPECT_EQ(test_object.E(case_one, NUMBER), answer_one);
    }
}

namespace TestAlgorithms
{
    class ClassAlgorithms : public MyClassTest
    {
    protected:

        // Объект класса для тестов
        HandbookSTL::Algorithms test_object;

        // Настройка перед каждым тестом
        void SetUp() override {
            // Инициализация объекта с параметрами
            test_object = HandbookSTL::Algorithms();
            MyClassTest::SetUp();

        }

        // Очистка после каждого теста
        void TearDown() override {
            MyClassTest::TearDown();
        }
    };

    TEST_F(ClassAlgorithms, Unique)
    {
        std::vector<int> example    = { 5, 5, 3, 2, 2, 5, 9, 1 };
        std::vector<int> reference  = { 5, 3, 2, 5, 9, 1, 9, 1 };
        auto it = test_object.Unique(example.begin(), example.end());

        EXPECT_EQ(*it, *(reference.cend() - 2));
    };


    TEST_F(ClassAlgorithms, D)
    {
        // First test from examples
        {
            std::vector<int> sorted_arr = { 1, 3, 5, 7, 9 };
            std::vector<int> values = { 2, 4, 8, 1, 6 };

            std::vector<int> result;
            std::vector<int> reference = { 1, 3, 7, 1, 5 };

            for (auto value : values)
            {
                int res = test_object.D(sorted_arr.begin(), sorted_arr.end(), value);
                result.push_back(res);
            }

            EXPECT_EQ(result, reference);
        }
        
        // Modified first test
        {
            std::vector<int> sorted_arr = { 1, 3, 5, 7, 9 };
            std::vector<int> values = { 2, 4, 8, 1, 60 };

            std::vector<int> result;
            std::vector<int> reference = { 1, 3, 7, 1, 9 };

            for (auto value : values)
            {
                int res = test_object.D(sorted_arr.begin(), sorted_arr.end(), value);
                result.push_back(res);
            }

            EXPECT_EQ(result, reference);
        }

        // Second test from examples
        {
            std::vector<int> sorted_arr = { 1, 1, 4, 4, 8, 120 };
            std::vector<int> values = { 1, 2, 3, 4, 5, 6, 7, 8, 63, 64, 65 };

            std::vector<int> result;
            std::vector<int> reference = { 1, 1, 4, 4, 4, 4, 8, 8, 8, 8, 120 };

            for (auto value : values)
            {
                int res = test_object.D(sorted_arr.begin(), sorted_arr.end(), value);
                result.push_back(res);
            }

            EXPECT_EQ(result, reference);
        }

        // Third test
        {
            std::vector<int> sorted_arr = { -5, 1, 1, 3, 5, 5, 8, 12, 13, 16 };
            std::vector<int> values = { 0, 3, 7, -17, 23, 11, 0, 11, 15, 7 };

            std::vector<int> result;
            std::vector<int> reference = { 1, 3, 8, -5, 16, 12, 1, 12, 16, 8 };

            for (auto value : values)
            {
                int res = test_object.D(sorted_arr.begin(), sorted_arr.end(), value);
                result.push_back(res);
            }

            EXPECT_EQ(result, reference);
        }
        
    };
}

namespace TestAdapters
{
    class ClassAdapters : public MyClassTest
    {
    protected:

        // Объект класса для тестов
        HandbookSTL::Adapters test_object;

        // Настройка перед каждым тестом
        void SetUp() override {
            // Инициализация объекта с параметрами
            test_object = HandbookSTL::Adapters();
            MyClassTest::SetUp();

        }

        // Очистка после каждого теста
        void TearDown() override {
            MyClassTest::TearDown();
        }
    };

    TEST_F(ClassAdapters, A)
    {
        {
            const std::string line = "({{{[]})";
            EXPECT_EQ(test_object.A(line), "NO");
        }

        {
            const std::string line = "}()[]{";
            EXPECT_EQ(test_object.A(line), "NO");
        }

        {
            const std::string line = "{(())()}[]";
            EXPECT_EQ(test_object.A(line), "YES");
        }


    }

    TEST_F(ClassAdapters, B)
    {
        {
            const std::vector<int> values = { 1, 3, 2, 4, 5, 3, 1 };
            const size_t k = 3;
            const std::vector<int> result = { 1, 2, 2, 3, 1 };
            const std::vector<int> out = test_object.B(values, k);
            EXPECT_EQ(out.size(), values.size() - k + 1);
            EXPECT_EQ(out, result);
        }

        {
            const std::vector<int> values = { 1, 3, 2, 4, 5, 3, 1 };
            const size_t k = values.size();
            const std::vector<int> result = { 1 };
            const std::vector<int> out = test_object.B(values, k);
            EXPECT_EQ(out.size(), values.size() - k + 1);
            EXPECT_EQ(out, result);
        }

        {
            const std::vector<int> values = { 1, 3, 2, 4, 5, 3, 1 };
            const size_t k = 1;
            const std::vector<int> result = { 1, 3, 2, 4, 5, 3, 1 };
            const std::vector<int> out = test_object.B(values, k);
            EXPECT_EQ(out.size(), values.size() - k + 1);
            EXPECT_EQ(out, result);
        }

        {
            const std::vector<int> values = { 1, 3, 2, 4, 5, 3, 1 };
            const size_t k = 0;
            const std::vector<int> result = { };
            const std::vector<int> out = test_object.B(values, k);
            /*EXPECT_EQ(out.size(), values.size() - k + 1);*/
            EXPECT_EQ(out, result);
        }

        {
            const std::vector<int> values = { };
            const size_t k = 5;
            const std::vector<int> result = { };
            const std::vector<int> out = test_object.B(values, k);
            /*EXPECT_EQ(out.size(), values.size() - k + 1);*/
            EXPECT_EQ(out, result);
        }

        // Empty case
        {
            const std::vector<int> values = {};
            const size_t k = 0;
            const std::vector<int> result = { };
            EXPECT_EQ(test_object.B(values, k), result);
        }


    }

    TEST_F(ClassAdapters, C)
    {
        {
            const std::vector<std::string> lines = { "ADD 192168812",
                                                        "ADD 125",
                                                        "ADD 321",
                                                        "EXTRACT",
                                                        "EXTRACT",
                                                        "CLEAR",
                                                        "ADD 7",
                                                        "ADD 555",
                                                        "EXTRACT",
                                                        "EXTRACT",
                                                        "EXTRACT" };

            std::vector<std::string> results;

            for (const auto & line: lines)
            {
                std::string res = test_object.C(line);

                if (!res.empty())
                    results.push_back(res);

            }

            const std::vector<std::string> reference = { "192168812",
                                                            "321",
                                                            "555",
                                                            "7",
                                                            "CANNOT" };

            EXPECT_EQ(reference, results);
        }

    }

    TEST_F(ClassAdapters, D)
    {
        {
            std::string_view sv = "Hello world and good bye";

            std::vector<std::string_view> reference = { "Hello",
                                                        "world",
                                                        "and",
                                                        "good",
                                                        "bye" };

            std::vector<std::string_view> results;

            const char delimiter = ' ';
            std::string_view token;

            // Делим строку на токены по разделителю и перебираем эти токены:
            while (test_object.NextToken(sv, delimiter, token)) {
                // обрабатываем очередной token
                // например, печатаем его на экране:
                results.push_back(token);
            }

            EXPECT_EQ(reference, results);
        }

        {
            std::string_view sv = "";

            std::vector<std::string_view> reference = { };

            std::vector<std::string_view> results;

            const char delimiter = ' ';
            std::string_view token;

            // Делим строку на токены по разделителю и перебираем эти токены:
            while (test_object.NextToken(sv, delimiter, token)) {
                // обрабатываем очередной token
                // например, печатаем его на экране:
                results.push_back(token);
            }

            EXPECT_EQ(reference, results);
        }

    }

    TEST_F(ClassAdapters, E)
    {
        {
            const std::vector<std::string> words{ "to", "be", "or", "not", "to", "be",
                                                    "that", "is", "the", "question" };

            const int k = 3;

            std::vector<std::pair<int, std::string>> result = { {2, "be"},{2, "to"}, {1, "is"}};

            EXPECT_EQ(test_object.E(words, k), result);
        }
    }
}


namespace IdiomsCppTest
{
    // 4.1 Классы
    // Тестирование задач из раздела https://education.yandex.ru/handbook/cpp/article/classes
    namespace ClassesTest
    {
        // Тесты для задания А 
        namespace DateTest
        {
            // Определим структуру для хранения даты
            typedef struct
            {
                const int year;
                const int month;
                const int day;
                
            } date_test_t;

            // Определим структуру для работы с операциями сложения и вычитания
            typedef struct
            {
                const date_test_t start;
                const int days;
                const date_test_t result;
            } date_oper_test_t;

            class DateTest : public ::testing::Test { }; // End Fate Class

            // Starts Tests
            using namespace HandbookIdioms::TaskA;

            TEST(ConstructionFor1, ValidInit)
            {
                // Проверка, изменились ли дефолтные константы
                {
                    // День
                    ASSERT_EQ(Date::DAY_MIN, 1);
                    // Месяц
                    ASSERT_EQ(Date::JANUARY, 1);
                    // Год
                    ASSERT_EQ(Date::YEAR_MIN, 1970);
                }

                // Default construction
                {
                    Date date;

                    // Get day
                    ASSERT_EQ(date.GetDay(), 1);
                    // Get month
                    ASSERT_EQ(date.GetMonth(), 1);
                    // Get year
                    ASSERT_EQ(date.GetYear(), 1970);
                }

                const date_test_t dates[] = 
                {
                    // День создания теста
                    {.year = 2025,              .month = 12,                .day = 21},
                    // Most possible date
                    {.year = Date::YEAR_MAX,    .month = Date::DECEMBER,    .day = Date::DAY_MAX},
                    // Вискокосный год, февраль
                    {.year = 2024,              .month = Date::FEBRARY,     .day = Date::DAY_FEBRUARY_LEAP},
                    // Вискокосный год, январь
                    {.year = 2024,              .month = Date::JANUARY,     .day = Date::DAY_MAX},

                };

                for (const auto& d : dates)
                {
                    Date date(d.day, d.month, d.year);

                    // Get day
                    ASSERT_EQ(date.GetDay(),    d.day);
                    // Get month
                    ASSERT_EQ(date.GetMonth(),  d.month);
                    // Get year
                    ASSERT_EQ(date.GetYear(),   d.year);
                }
            }

            //
            TEST(ConstructionFor1, NoValidDate)
            {
                // Все даты должны быть данными значениями
                const int   day = Date::DAY_MIN,
                    month = Date::JANUARY,
                    year = Date::YEAR_MIN;

                const int MILENIUM_YEAR = 2000;

                // Зададим структуру для работы с датой
                const date_test_t unvalid_dates[] =
                {
                    // *** Проверяем установку года ***
                    // Год меньше минимального
                    {.year = 1095,                  .month = Date::MAY,             .day = 16},                  // В этот год начался первый крестовый поход
                    {.year = Date::YEAR_MIN - 1,    .month = Date::MAY,             .day = 16},
                    {.year = Date::YEAR_MIN - 32,   .month = Date::MAY,             .day = 16},
                    {.year = INT_MIN,               .month = Date::MAY,             .day = 16},
                    {.year = 0,                     .month = Date::MAY,             .day = 16},
                    {.year = -1,                    .month = Date::MAY,             .day = 16},
                    {.year = -3000,                 .month = Date::MAY,             .day = 16},
                    // Год больше максимально допустимого
                    {.year = Date::YEAR_MAX + 1,    .month = Date::MAY,             .day = 16},
                    {.year = Date::YEAR_MAX + 32,   .month = Date::MAY,             .day = 16},
                    {.year = Date::YEAR_MAX + 3200, .month = Date::MAY,             .day = 16},
                    {.year = INT_MAX,               .month = Date::MAY,             .day = 16},

                    // *** Проверяем установку месяца ***
                    // Маленькое значение месяца
                    {.year = MILENIUM_YEAR,         .month = 0,                     .day = 16},
                    {.year = MILENIUM_YEAR,         .month = Date::JANUARY - 1,     .day = 16},
                    {.year = MILENIUM_YEAR,         .month = Date::JANUARY - 100,   .day = 16},
                    {.year = MILENIUM_YEAR,         .month = -37,                   .day = 16},
                    {.year = MILENIUM_YEAR,         .month = INT_MIN,               .day = 16},
                    // Большое значения месяца
                    {.year = MILENIUM_YEAR,         .month = Date::DECEMBER + 1,    .day = 16},
                    {.year = MILENIUM_YEAR,         .month = Date::DECEMBER + 100,  .day = 16},
                    {.year = MILENIUM_YEAR,         .month = 100,                   .day = 16},
                    {.year = MILENIUM_YEAR,         .month = INT_MAX,               .day = 16},
                    // *** Проверяем установку дня ***
                    // Маленькое значение
                    {.year = MILENIUM_YEAR,         .month = Date::MAY,             .day = 0},
                    {.year = MILENIUM_YEAR,         .month = Date::MAY,             .day = Date::DAY_MIN - 1},
                    {.year = MILENIUM_YEAR,         .month = Date::MAY,             .day = Date::DAY_MIN - 32},
                    {.year = MILENIUM_YEAR,         .month = Date::MAY,             .day = Date::DAY_MIN - 1000},
                    {.year = MILENIUM_YEAR,         .month = Date::MAY,             .day = INT_MIN},
                    // Большое значение
                    {.year = MILENIUM_YEAR,         .month = Date::MAY,             .day = Date::DAY_MAX + 1},
                    // *** Все поля невалидные ***
                    {.year = Date::YEAR_MAX + 5,    .month = Date::DECEMBER + 5,    .day = Date::DAY_MAX + 1},
                    {.year = Date::YEAR_MIN - 5,    .month = Date::DECEMBER + 5,    .day = Date::DAY_MAX + 1},
                    {.year = 0,                     .month = 0,                     .day = 0},
                    {.year = -5,                    .month = -1,                    .day = Date::DAY_MAX},
                    {.year = -8,                    .month = Date::DECEMBER,        .day = -1},
                };

                // Не должен быть пустой этот массив
                assert(sizeof(unvalid_dates) / sizeof(unvalid_dates[0]) != 0);

                for (const auto& un : unvalid_dates)
                {
                    Date date(un.day, un.month, un.year);

                    // Get day
                    ASSERT_EQ(date.GetDay(), day);
                    // Get month
                    ASSERT_EQ(date.GetMonth(), month);
                    // Get year
                    ASSERT_EQ(date.GetYear(), year);
                }

            };

            // Данный тест нужен для проверки правильной установки данных в пределах одного месяца
            TEST(SumOperFor1, ValidSumChangeDay)
            {
                const date_oper_test_t dates[] =
                {
                    {
                        .start = {.year = Date::YEAR_MIN, .month = Date::JANUARY, .day = Date::DAY_MIN},
                        .days = 1,
                        .result = {.year = Date::YEAR_MIN, .month = Date::JANUARY, .day = Date::DAY_MIN + 1}
                    },
                    {
                        .start = {.year = Date::YEAR_MIN, .month = Date::JANUARY, .day = Date::DAY_MIN},
                        .days = 15,
                        .result = {.year = Date::YEAR_MIN, .month = Date::JANUARY, .day = Date::DAY_MIN + 15}
                    },
                    {
                        .start = {.year = Date::YEAR_MIN, .month = Date::JANUARY, .day = Date::DAY_MIN},
                        .days = 30,
                        .result = {.year = Date::YEAR_MIN, .month = Date::JANUARY, .day = Date::DAY_MIN + 30}
                    },
                    {
                        .start = {.year = Date::YEAR_MIN, .month = Date::FEBRARY, .day = Date::DAY_MIN},
                        .days = 1,
                        .result = {.year = Date::YEAR_MIN, .month = Date::FEBRARY, .day = Date::DAY_MIN + 1}
                    },
                    // Февраль (28 дней)
                    {
                        .start = {.year = Date::YEAR_MIN, .month = Date::FEBRARY, .day = Date::DAY_MIN},
                        .days = 27,
                        .result = {.year = Date::YEAR_MIN, .month = Date::FEBRARY, .day = Date::DAY_MIN + 27}
                    },
                    // Февраль (Високосый год)
                    {
                        .start = {.year = 2024, .month = Date::FEBRARY, .day = Date::DAY_MIN},
                        .days = 28,
                        .result = {.year = 2024, .month = Date::FEBRARY, .day = Date::DAY_MIN + 28}
                    },
                    // Апрель (30 дней)
                    {
                        .start = {.year = Date::YEAR_MIN, .month = Date::APRIL, .day = Date::DAY_MIN},
                        .days = 29,
                        .result = {.year = Date::YEAR_MIN, .month = Date::APRIL, .day = Date::DAY_MIN + 29}
                    },
                    // Последний год
                    {
                        .start = {.year = Date::YEAR_MAX, .month = Date::DECEMBER, .day = Date::DAY_MIN},
                        .days = 10,
                        .result = {.year = Date::YEAR_MAX, .month = Date::DECEMBER, .day = Date::DAY_MIN + 10}
                    },

                };

                for (const auto& d : dates)
                {
                    Date start(d.start.day, d.start.month, d.start.year);
                    const auto res = start + d.days;

                    // Проверка дня
                    ASSERT_EQ(res.GetDay(), d.result.day);

                    // Месяца
                    ASSERT_EQ(res.GetMonth(), d.result.month);

                    // Года
                    ASSERT_EQ(res.GetYear(), d.result.year);
                }
            };

            // *** Добавляем в пределах нескольких месяцев ***
            TEST(SumOperFor1, ValidSumChangeMonth)
            {
                const date_oper_test_t dates[] =
                {
                    {
                        .start = {.year = Date::YEAR_MIN, .month = Date::JANUARY, .day = 31},
                        .days = 1,
                        .result = {.year = Date::YEAR_MIN, .month = Date::FEBRARY, .day = Date::DAY_MIN}
                    },
                    {
                        .start = {.year = Date::YEAR_MIN, .month = Date::JANUARY, .day = Date::DAY_MIN},
                        .days = 31,
                        .result = {.year = Date::YEAR_MIN, .month = Date::FEBRARY, .day = Date::DAY_MIN}
                    },
                    {
                        .start = {.year = Date::YEAR_MIN, .month = Date::JANUARY, .day = Date::DAY_MIN},
                        .days = 89,
                        .result = {.year = Date::YEAR_MIN, .month = Date::MARCH, .day = 31}
                    },
                    {
                        .start = {.year = Date::YEAR_MIN, .month = Date::JANUARY, .day = Date::DAY_MIN},
                        .days = 69, // ^_~
                        .result = {.year = Date::YEAR_MIN, .month = Date::MARCH, .day = 11}
                    },


                };

                for (const auto& d : dates)
                {
                    Date start(d.start.day, d.start.month, d.start.year);
                    const auto res = start + d.days;

                    // Проверка дня
                    ASSERT_EQ(res.GetDay(), d.result.day);

                    // Месяца
                    ASSERT_EQ(res.GetMonth(), d.result.month);

                    // Года
                    ASSERT_EQ(res.GetYear(), d.result.year);
                }

            };

        }; // End Date namespace

        // Тесты для задания B 
        namespace DateTest2
        {
            // ИСпользуем пространство для второго задания
            using namespace HandbookIdioms::TaskB;

            // Определим структуру для хранения даты
            typedef struct
            {
                const int year;
                const int month;
                const int day;

            } date_test_t;

            // Определим структуру для работы с операциями сложения и вычитания
            typedef struct
            {
                const date_test_t start;
                const int days;
                const date_test_t result;
            } date_oper_test_t;

            class DateTest2 : public ::testing::Test { }; // End Date Class

            // Проверка, изменились ли дефолтные константы
            TEST(Constants, Valid)
            {
                // День
                EXPECT_EQ(Date::DAY_MIN, 1);
                // 
                EXPECT_EQ(Date::DAY_MAX, 31);
                // Месяц
                EXPECT_EQ(Date::JANUARY, 1);
                EXPECT_EQ(Date::DECEMBER, 12);
                // Год
                EXPECT_EQ(Date::YEAR_MIN, 1970);
                EXPECT_EQ(Date::YEAR_MAX, 2099);
            }

            TEST(Constants, NoValid)
            {
                // День
                EXPECT_NE(Date::DAY_MIN, 0);
                // Месяц
                EXPECT_NE(Date::JANUARY, 0);
                // Год
                EXPECT_NE(Date::YEAR_MIN, 2000);
            }

            // *** Конструкторы по умолчанию ***
            // Так написан тест на константы, 
            // можем ссылаться на константы тестируемого класса

            // Получаем из дефолтного объекта год
            TEST(DefaultConstruction, ValidGetterYear)
            {
                Date date;

                EXPECT_EQ(date.GetYear(), Date::YEAR_MIN);
            }

            // Получаем из дефолтного объекта месяц
            TEST(DefaultConstruction, ValidGetterMonth)
            {
                Date date;
                
                // Get month
                EXPECT_EQ(date.GetMonth(), Date::JANUARY);
            }

            // Получаем из дефолтного объекта день
            TEST(DefaultConstruction, ValidGetterDay)
            {
                Date date;

                EXPECT_EQ(date.GetDay(), Date::DAY_MIN);
            }

            // Протестируем геттер при фиксированных других значениях
            // Для года
            TEST(GetterWithFixedAnotherFields, Year)
            {
                const date_test_t d = { .year = 2025, .month = 12, .day = 21 };

                for (int i = Date::YEAR_MIN; i <= Date::YEAR_MAX; i++)
                {
                    Date date(d.day, d.month, i);
                    // Get year
                    EXPECT_EQ(date.GetYear(), i);
                }
            }

            // Для месяца
            TEST(GetterWithFixedAnotherFields, Month)
            {
                const date_test_t d = { .year = 2025, .month = 12, .day = 21 };

                for (int i = Date::JANUARY; i <= Date::DECEMBER; i++)
                {
                    Date date(d.day, i, d.year);
                    // Get month
                    EXPECT_EQ(date.GetMonth(), i);
                }
            }

            // Для дня
            TEST(GetterWithFixedAnotherFields, Day)
            {
                // В декабре точно все эти дни есть
                const date_test_t d = { .year = 2025, .month = Date::DECEMBER, .day = 21 };

                for (int i = Date::DAY_MIN; i <= Date::DAY_MAX; i++)
                {
                    Date date(i, d.month, d.year);
                    // Get month
                    EXPECT_EQ(date.GetDay(), i);
                }
            }

            // 
            TEST(ConstructionWithParams, ValidInit)
            {
                const date_test_t dates[] =
                {
                    // День создания теста
                    {.year = 2025,              .month = 12,                .day = 21},
                    // Most possible date
                    {.year = Date::YEAR_MAX,    .month = Date::DECEMBER,    .day = Date::DAY_MAX},
                    // Вискокосный год, февраль
                    {.year = 2024,              .month = Date::FEBRARY,     .day = Date::DAY_FEBRUARY_LEAP},
                    // Вискокосный год, март 31
                    {.year = 2024,              .month = Date::MARCH,       .day = Date::DAY_MAX},
                    // Вискокосный год, март 30
                    {.year = 2024,              .month = Date::MARCH,       .day = 30},
                    // Вискокосный год, январь
                    {.year = 2024,              .month = Date::JANUARY,     .day = Date::DAY_MAX},

                };

                for (const auto& d : dates)
                {
                    Date date(d.day, d.month, d.year);

                    // Get day
                    EXPECT_EQ(date.GetDay(), d.day);
                    // Get month
                    EXPECT_EQ(date.GetMonth(), d.month);
                    // Get year
                    EXPECT_EQ(date.GetYear(), d.year);
                }
            }

            // *** Проверки конструктора с невалидноыми датами

            // Невалидный год 
            TEST(ConstructionWithParams, NoValidYear)
            {
                // Зададим структуру для работы с датой
                const date_test_t unvalid_dates[] =
                {
                    // *** Проверяем установку года ***
                    // Год меньше минимального
                    {.year = 1095,                  .month = Date::MAY,             .day = 16},                  // В этот год начался первый крестовый поход
                    {.year = Date::YEAR_MIN - 1,    .month = Date::MAY,             .day = 16},
                    {.year = Date::YEAR_MIN - 32,   .month = Date::MAY,             .day = 16},
                    {.year = INT_MIN,               .month = Date::MAY,             .day = 16},
                    {.year = 0,                     .month = Date::MAY,             .day = 16},
                    {.year = -1,                    .month = Date::MAY,             .day = 16},
                    {.year = -3000,                 .month = Date::MAY,             .day = 16},
                    // Год больше максимально допустимого
                    {.year = Date::YEAR_MAX + 1,    .month = Date::MAY,             .day = 16},
                    {.year = Date::YEAR_MAX + 32,   .month = Date::MAY,             .day = 16},
                    {.year = Date::YEAR_MAX + 3200, .month = Date::MAY,             .day = 16},
                    {.year = INT_MAX,               .month = Date::MAY,             .day = 16},

                };

                // Не должен быть пустой этот массив
                EXPECT_NE(sizeof(unvalid_dates) / sizeof(unvalid_dates[0]), 0);

                // проитерируем по данным
                for (const auto& un : unvalid_dates)
                {
                    //Построим объект
                    Date date(un.day, un.month, un.year);

                    // Get day
                    EXPECT_EQ(date.GetDay(), Date::DAY_MIN);
                    // Get month
                    EXPECT_EQ(date.GetMonth(), Date::JANUARY);
                    // Get year
                    EXPECT_EQ(date.GetYear(), Date::YEAR_MIN);
                }

            }

            // Итерируем по месяцам
            TEST(ConstructionWithParams, NoValidMonth)
            {
                // Некий дефолтный год
                const int MILENIUM_YEAR = 2000;

                // Зададим структуру для работы с датой
                const date_test_t unvalid_dates[] =
                {

                    // *** Проверяем установку месяца ***
                    // Маленькое значение месяца
                    {.year = MILENIUM_YEAR,         .month = 0,                     .day = 16},
                    {.year = MILENIUM_YEAR,         .month = Date::JANUARY - 1,     .day = 16},
                    {.year = MILENIUM_YEAR,         .month = Date::JANUARY - 100,   .day = 16},
                    {.year = MILENIUM_YEAR,         .month = -37,                   .day = 16},
                    {.year = MILENIUM_YEAR,         .month = INT_MIN,               .day = 16},
                    // Большое значения месяца
                    {.year = MILENIUM_YEAR,         .month = Date::DECEMBER + 1,    .day = 16},
                    {.year = MILENIUM_YEAR,         .month = Date::DECEMBER + 100,  .day = 16},
                    {.year = MILENIUM_YEAR,         .month = 100,                   .day = 16},
                    {.year = MILENIUM_YEAR,         .month = INT_MAX,               .day = 16},
                };

                // Не должен быть пустой этот массив
                EXPECT_NE(sizeof(unvalid_dates) / sizeof(unvalid_dates[0]), 0);

                // проитерируем по данным
                for (const auto& un : unvalid_dates)
                {
                    Date date(un.day, un.month, un.year);

                    // Get day
                    EXPECT_EQ(date.GetDay(), Date::DAY_MIN);
                    // Get month
                    EXPECT_EQ(date.GetMonth(), Date::JANUARY);
                    // Get year
                    EXPECT_EQ(date.GetYear(), Date::YEAR_MIN);
                }

            }

            // Итерируем по дням
            TEST(ConstructionWithParams, NoValidDay)
            {
                // Некий дефолтный год
                const int MILENIUM_YEAR = 2000;

                // Зададим структуру для работы с датой
                const date_test_t unvalid_dates[] =
                {
                    // *** Проверяем установку дня ***
                    // Маленькое значение
                    {.year = MILENIUM_YEAR, .month = Date::MAY, .day = 0 },
                    {.year = MILENIUM_YEAR,         .month = Date::MAY,             .day = Date::DAY_MIN - 1 },
                    {.year = MILENIUM_YEAR,         .month = Date::MAY,             .day = Date::DAY_MIN - 32 },
                    {.year = MILENIUM_YEAR,         .month = Date::MAY,             .day = Date::DAY_MIN - 1000 },
                    {.year = MILENIUM_YEAR,         .month = Date::MAY,             .day = INT_MIN },
                    // Большое значение
                    {.year = MILENIUM_YEAR,         .month = Date::MAY,             .day = Date::DAY_MAX + 1 },
                    // *** Все поля невалидные ***
                    {.year = Date::YEAR_MAX + 5,    .month = Date::DECEMBER + 5,    .day = Date::DAY_MAX + 1 },
                    {.year = Date::YEAR_MIN - 5,    .month = Date::DECEMBER + 5,    .day = Date::DAY_MAX + 1 },
                    {.year = 0,                     .month = 0,                     .day = 0 },
                    {.year = -5,                    .month = -1,                    .day = Date::DAY_MAX },
                    {.year = -8,                    .month = Date::DECEMBER},
                };

                // Не должен быть пустой этот массив
                EXPECT_NE(sizeof(unvalid_dates) / sizeof(unvalid_dates[0]), 0);

                // проитерируем по данным
                for (const auto& un : unvalid_dates)
                {
                    Date date(un.day, un.month, un.year);

                    // Get day
                    EXPECT_EQ(date.GetDay(), Date::DAY_MIN);
                    // Get month
                    EXPECT_EQ(date.GetMonth(), Date::JANUARY);
                    // Get year
                    EXPECT_EQ(date.GetYear(), Date::YEAR_MIN);
                }

            }

            // Все поля невалидные
            TEST(ConstructionWithParams, NoValidAllFields)
            {
                // Некий дефолтный год
                const int MILENIUM_YEAR = 2000;

                // Зададим структуру для работы с датой
                const date_test_t unvalid_dates[] =
                {
                    // *** Все поля невалидные ***
                    {.year = Date::YEAR_MAX + 5,    .month = Date::DECEMBER + 5,    .day = Date::DAY_MAX + 1 },
                    {.year = Date::YEAR_MIN - 5,    .month = Date::DECEMBER + 5,    .day = Date::DAY_MAX + 1 },
                    {.year = 0,                     .month = 0,                     .day = 0 },
                    {.year = -5,                    .month = -1,                    .day = Date::DAY_MAX },
                    {.year = -8,                    .month = Date::DECEMBER},
                };

                // Не должен быть пустой этот массив
                EXPECT_NE(sizeof(unvalid_dates) / sizeof(unvalid_dates[0]), 0);

                // проитерируем по данным
                for (const auto& un : unvalid_dates)
                {
                    Date date(un.day, un.month, un.year);

                    // Get day
                    EXPECT_EQ(date.GetDay(), Date::DAY_MIN);
                    // Get month
                    EXPECT_EQ(date.GetMonth(), Date::JANUARY);
                    // Get year
                    EXPECT_EQ(date.GetYear(), Date::YEAR_MIN);
                }

            }

            // Данный тест нужен для проверки правильной установки данных в пределах одного месяца
            TEST(SumOperForDateB, ValidChangeDay)
            {
                const date_oper_test_t validSumsChangeDay[] =
                {
                    {
                        .start = {.year = Date::YEAR_MIN, .month = Date::JANUARY, .day = Date::DAY_MIN},
                        .days = 1,
                        .result = {.year = Date::YEAR_MIN, .month = Date::JANUARY, .day = Date::DAY_MIN + 1}
                    },
                    {
                        .start = {.year = Date::YEAR_MIN, .month = Date::JANUARY, .day = Date::DAY_MIN},
                        .days = 15,
                        .result = {.year = Date::YEAR_MIN, .month = Date::JANUARY, .day = Date::DAY_MIN + 15}
                    },
                    {
                        .start = {.year = Date::YEAR_MIN, .month = Date::JANUARY, .day = Date::DAY_MIN},
                        .days = 30,
                        .result = {.year = Date::YEAR_MIN, .month = Date::JANUARY, .day = Date::DAY_MIN + 30}
                    },
                    {
                        .start = {.year = Date::YEAR_MIN, .month = Date::FEBRARY, .day = Date::DAY_MIN},
                        .days = 1,
                        .result = {.year = Date::YEAR_MIN, .month = Date::FEBRARY, .day = Date::DAY_MIN + 1}
                    },
                    // Февраль (28 дней)
                    {
                        .start = {.year = Date::YEAR_MIN, .month = Date::FEBRARY, .day = Date::DAY_MIN},
                        .days = 27,
                        .result = {.year = Date::YEAR_MIN, .month = Date::FEBRARY, .day = Date::DAY_MIN + 27}
                    },
                    // Февраль (Високосый год)
                    {
                        .start = {.year = 2024, .month = Date::FEBRARY, .day = Date::DAY_MIN},
                        .days = 28,
                        .result = {.year = 2024, .month = Date::FEBRARY, .day = Date::DAY_MIN + 28}
                    },
                    // Апрель (30 дней)
                    {
                        .start = {.year = Date::YEAR_MIN, .month = Date::APRIL, .day = Date::DAY_MIN},
                        .days = 29,
                        .result = {.year = Date::YEAR_MIN, .month = Date::APRIL, .day = Date::DAY_MIN + 29}
                    },
                    // Последний год
                    {
                        .start = {.year = Date::YEAR_MAX, .month = Date::DECEMBER, .day = Date::DAY_MIN},
                        .days = 10,
                        .result = {.year = Date::YEAR_MAX, .month = Date::DECEMBER, .day = Date::DAY_MIN + 10}
                    },

                };

                for (const auto& d : validSumsChangeDay)
                {
                    Date start(d.start.day, d.start.month, d.start.year);
                    const auto res = start + d.days;

                    // Проверка дня
                    EXPECT_EQ(res.GetDay(), d.result.day);

                    EXPECT_EQ(res.GetMonth(), d.result.month);

                    EXPECT_EQ(res.GetYear(), d.result.year);
                } //end for

            }

            // *** Добавляем в пределах нескольких месяцев ***
            TEST(SumOperForDateB, ValidChangeMonth)
            {
                const date_oper_test_t dates[] =
                {
                    {
                        .start = {.year = Date::YEAR_MIN, .month = Date::JANUARY, .day = 31},
                        .days = 1,
                        .result = {.year = Date::YEAR_MIN, .month = Date::FEBRARY, .day = Date::DAY_MIN}
                    },
                    {
                        .start = {.year = Date::YEAR_MIN, .month = Date::JANUARY, .day = Date::DAY_MIN},
                        .days = 31,
                        .result = {.year = Date::YEAR_MIN, .month = Date::FEBRARY, .day = Date::DAY_MIN}
                    },
                    {
                        .start = {.year = Date::YEAR_MIN, .month = Date::JANUARY, .day = Date::DAY_MIN},
                        .days = 89,
                        .result = {.year = Date::YEAR_MIN, .month = Date::MARCH, .day = 31}
                    },
                    {
                        .start = {.year = Date::YEAR_MIN, .month = Date::JANUARY, .day = Date::DAY_MIN},
                        .days = 69, // ^_~
                        .result = {.year = Date::YEAR_MIN, .month = Date::MARCH, .day = 11}
                    },

                }; // end dates

                for (const auto& d : dates)
                {
                    Date start(d.start.day, d.start.month, d.start.year);
                    const auto res = start + d.days;

                    // Проверка дня
                    ASSERT_EQ(res.GetDay(), d.result.day);

                    // Месяца
                    ASSERT_EQ(res.GetMonth(), d.result.month);

                    // Года
                    ASSERT_EQ(res.GetYear(), d.result.year);
                } // end for

            } // End test ValidSumChangeMonth

             // TODO: сделать тесты для отрицательных чисел 

        }; // End Date namespace
       
         // *** Тесты для C: Rational ***
        namespace TaskC
        {
            // подключим тестируем объект
            using namespace HandbookIdioms;

            TEST(constructor_default, create_object)
            {
                // Объект должен сгенерироваться
                ASSERT_NO_THROW(Rational rational);
            }

            TEST(constructor_default, get_numerator)
            {
                Rational rational;

                EXPECT_EQ(rational.Numerator(), 0);
            }

            TEST(constructor_default, get_denominator)
            {
                Rational rational;

                EXPECT_EQ(rational.Denominator(), 1);
            }

            // Передадимв числитель все числа от минимума до максимума,
            // ответ должен быть один и тот же для нулевого делителя
            TEST(constructor_params, pass_0_to_denominator)
            {
                // Зададим число итераций (что бы тест был не слишком долгим)
                const int half_count = 10000;
               
                for(int i = -half_count; i <= half_count; i++)
                {
                    Rational rational(i, 0);

                    EXPECT_EQ(rational.Numerator(), 0);

                    EXPECT_EQ(rational.Denominator(), 1);
                }
            }

            TEST(constructor_params, pass_0_to_denom_and_boundary_num)
            {
                // Зададим число итераций (что бы тест был не слишком долгим)
                const auto values = std::to_array<int>({ 0, INT_MIN, INT_MAX});

                for (const auto val : values)
                {
                    Rational rational(val, 0);

                    EXPECT_EQ(rational.Numerator(), 0);

                    EXPECT_EQ(rational.Denominator(), 1);
                }
            }

            TEST(constructor_params, pass_0_to_numerator)
            {
                const int start = -1000;
                const int end = 1000;

                for (int i = start; i != end; i++)
                {
                    Rational rational(0, i);

                    EXPECT_EQ(rational.Numerator(), 0);

                    EXPECT_EQ(rational.Denominator(), 1);
                }
            }

            TEST(constructor_params, pass_0_to_numerator_and_boundary_denom)
            {
                // Зададим число итераций (что бы тест был не слишком долгим)
                const auto values = std::to_array<int>({ 0, INT_MIN, INT_MAX });

                for (const auto &val: values)
                {
                    Rational rational(0, val);

                    EXPECT_EQ(rational.Numerator(), 0);

                    EXPECT_EQ(rational.Denominator(), 1);
                }
            }


            // TODO: Далее можно было воспользоваться параметризованными тестами,
            // но моя VS Studio не хочет с ними работать и генерит ошибки

            // Далее: простые тесты на создание объекта. 
            // Передадим числитель и знаменатель в конструктор,
            // должны получить те же самые значения


            TEST(constructor_params, no_reduced_fractional_positive_numbers)
            {
                // Зададим числитель и значенатель
                const std::pair<int, int> values[] =
                { 
                    {1, 2},
                    {2, 17},
                    {3, 4},
                    {5, 6},
                    {7, 8},
                    {2, 137},
                    {2, 17},
                    {5, 7},
                    {0, 1},
                    {1, INT_MAX}
                };

                for (const auto& val : values)
                {
                    Rational rational(val.first, val.second);

                    EXPECT_EQ(rational.Numerator(), val.first);

                    EXPECT_EQ(rational.Denominator(), val.second);
                }
            }

            // Проверим построение объекта с числителем больше чем знаменатель
            TEST(constructor_params, mixed_no_reduced_positive)
            {
                // Зададим числитель и значенатель
                const std::pair<int, int> values[] =
                {
                    // 
                    { 3, 1 },
                    { INT_MAX, 1 },
                    { 3, 2 },
                    { 17, 3 },
                    { 14, 3 },
                    { 4, 3 },
                    { 7, 4 },
                    { 7, 5 },
                    { 11, 2 },
                };

                for (const auto& val : values)
                {
                    Rational rational(val.first, val.second);

                    EXPECT_EQ(rational.Numerator(), val.first);

                    EXPECT_EQ(rational.Denominator(), val.second);
                }
            }



            //  *** Далее: проверка создание объекта с отрицательными числами. ***

            //  Проверка с отрицательными числителями 
            TEST(constructor_params, no_reduced_and_negative_numerator)
            {
                // Зададим числитель и значенатель
                const std::pair<int, int> values[] =
                {
                    {-1, 2},
                    {-2, 17},
                    {-3, 4},
                    {-5, 6},
                    {-7, 8},
                    {-2, 137},
                    {-2, 17},
                    {-5, 7},
                    {-4, 137},
                    {-1, INT_MAX},
                    {INT_MIN, 1}
                };

                for (const auto & value : values)
                {
                    Rational rational(value.first, value.second);

                    EXPECT_EQ(rational.Numerator(), value.first);

                    EXPECT_EQ(rational.Denominator(), value.second);
                }
            }

            //  Проверка с отрицательными знаменателями  
            TEST(constructor_params, no_reduced_and_negative_denominator)
            {
                // Зададим числитель и значенатель
                const std::pair<int, int> values[] =
                {
                    {1, -2},
                    {2, -17},
                    {3, -4},
                    {5, -6},
                    {7, -8},
                    {2, -137},
                    {2, -17},
                    {5, -7},
                    {4, -137},
                    {1, INT_MIN},
                    {INT_MAX, -1},
                    {3, -1},
                    {13, -2},
                    {15, -7}
                };

                for (const auto& value : values)
                {
                    Rational rational(value.first, value.second);

                    EXPECT_EQ(rational.Numerator(), -value.first);

                    EXPECT_EQ(rational.Denominator(), -value.second);
                }
            }

            // Проверка с отрицательными числителями и знаменателями  
            TEST(constructor_params, no_reduced_and_negative_both_numbers)
            {
                // Зададим числитель и значенатель
                const std::pair<int, int> values[] =
                {
                    {-1, -2},
                    {-2, -17},
                    {-3, -4},
                    {-5, -6},
                    {-7, -8},
                    {-2, -137},
                    {-2, -17},
                    {-5, -7},
                    {-4, -137},
                    {-1, INT_MIN},
                    {INT_MIN, -1},
                    {-3, -1},
                    {-13, -2},
                    {-15, -7}
                };

                for (const auto& value : values)
                {
                    Rational rational(value.first, value.second);

                    EXPECT_EQ(rational.Numerator(), -value.first);

                    EXPECT_EQ(rational.Denominator(), -value.second);
                }
            }

            // *** Проверка сокращения дробей ***
            
            // Для положительных чисел
            TEST(reduce, positive_numbers)
            {
                // Зададим числитель и значенатель
                const struct
                {
                    std::pair<int, int> input;
                    std::pair<int, int> res;
                } values[] =
                {
                    // .5
                    {{2 ,4}, {1, 2}},
                    {{3 ,6}, {1, 2}},
                    {{4 ,8}, {1, 2}},

                    {{3 ,9}, {1, 3}},
                    {{4 ,16}, {1, 4}},
                    {{5 ,25}, {1, 5}},
                    {{11 ,121}, {1, 11}},
                    {{12 ,144}, {1, 12}},
                    {{6 ,8}, {3, 4}},

                    // Целые числа
                    {{6 ,2}, {3, 1}},
                    {{25 ,5}, {5, 1}},

                };

                for (const auto value : values)
                {
                    const auto input = value.input;

                    Rational rational = Rational(input.first, input.second);

                    const auto res = value.res;

                    EXPECT_EQ(rational.Numerator(), res.first);

                    EXPECT_EQ(rational.Denominator(), res.second);

                }
               

            }

            // Для отрицательных чисел
            TEST(reduce, negative_numbers)
            {
                // Зададим числитель и значенатель
                const struct
                {
                    std::pair<int, int> input;
                    std::pair<int, int> res;
                } values[] =
                {
                    // .5
                    {{-2 ,4}, {-1, 2}},
                    {{-3 ,6}, {-1, 2}},
                    {{-4 ,8}, {-1, 2}},

                    {{3 ,-9}, {-1, 3}},
                    {{4 ,-16}, {-1, 4}},
                    {{5 ,-25}, {-1, 5}},
                    {{-11 ,121}, {-1, 11}},
                    {{12 ,-144}, {-1, 12}},
                    {{-6 ,8}, {-3, 4}},

                    // Целые числа
                    {{-6 ,2}, {-3, 1}},
                    {{25 ,-5}, {-5, 1}},

                };

                for (const auto value : values)
                {
                    const auto input = value.input;

                    Rational rational = Rational(input.first, input.second);

                    const auto res = value.res;

                    EXPECT_EQ(rational.Numerator(), res.first);

                    EXPECT_EQ(rational.Denominator(), res.second);

                }
            }

            // *** Унарные операторы

            TEST(unary_operator, minus_usual)
            {
                // Зададим числитель и значенатель
                const struct
                {
                    std::pair<int, int> input;
                    std::pair<int, int> res;
                } values[] =
                {
                    // .5
                    {{-2 ,4}, {1, 2}},
                    {{-3 ,6}, {1, 2}},
                    {{4 ,8}, {-1, 2}},

                    {{3 ,-9}, {1, 3}},
                    {{4 ,16}, {-1, 4}},
                    {{5 ,-25}, {1, 5}},
                    {{-11 ,121}, {1, 11}},
                    {{12 ,-144}, {1, 12}},
                    {{-6 ,8}, {3, 4}},

                    // Целые числа
                    {{-6 ,2}, {3, 1}},
                    {{25 ,-5}, {5, 1}},

                };

                for (const auto value : values)
                {
                    const auto input = value.input;

                    Rational rational = -Rational(input.first, input.second);

                    const auto res = value.res;

                    EXPECT_EQ(rational.Numerator(), res.first);

                    EXPECT_EQ(rational.Denominator(), res.second);

                }
            }

            TEST(unary_operator, minus_and_boundary)
            {
                // Зададим числитель и значенатель
                const struct
                {
                    std::pair<int, int> input;
                    std::pair<int, int> res;
                } values[] =
                {
                    {{0 ,1}, {0, 1}},
                    {{INT_MAX ,1}, {-INT_MAX, 1}},
                    {{1 ,INT_MIN}, {1, -INT_MIN}},

                };

                for (const auto value : values)
                {
                    const auto input = value.input;

                    Rational rational = -Rational(input.first, input.second);

                    const auto res = value.res;

                    EXPECT_EQ(rational.Numerator(), res.first);

                    EXPECT_EQ(rational.Denominator(), res.second);

                }
            } // unary_operator, minus_and_boundary

            TEST(unary_operator, plus)
            {
                // Зададим числитель и значенатель

                    std::pair<int, int> values[] =
                {
                    {0 ,1},
                    {INT_MAX ,1},
                    {1 ,INT_MAX},
                    {2 ,3},
                    {-2 ,3},
                    {-2 ,17},
                    {5, 3}
                };

                for (const auto value : values)
                {
                    Rational rational = +Rational(value.first, value.second);

                    EXPECT_EQ(rational.Numerator(), value.first);

                    EXPECT_EQ(rational.Denominator(), value.second);

                }
            } // unary_operator, plus

            // *** Блок проверки операторов сравнения
            
            // Положительный результат сравнения
            TEST(EqualityOperator, Equals)
            {
                const struct
                {
                    std::pair<int, int> left;
                    std::pair<int, int> right;
                    bool expected;
                } values[] =
                {
                    // Секция нулевых знаменателей
                    {{0, 1}, {0, 1}, true},
                    {{0, 1}, {0, 4}, true},
                    {{0, 1}, {0, 6}, true},
                    {{0, 1}, {0, -1}, true},
                    {{0, 1}, {0, INT_MIN}, true},
                    // Правильные положительные дроби
                    {{1, 2}, {1, 2}, true},
                    {{1, 2}, {2, 4}, true},
                    {{1, 2}, {4, 8}, true},
                    {{2, 3}, {2, 3}, true},
                    {{2, 5}, {2, 5}, true},
                    {{2, 5}, {4, 10}, true},
                    // Правильные отрицательные дроби
                    {{-1, 2}, {-1, 2}, true},
                    {{1, -2}, {-2, 4}, true},
                    {{-1, 2}, {4, -8}, true},
                    {{-2, 3}, {-2, 3}, true},
                    {{-2, 5}, {-2, 5}, true},
                    {{-2, 5}, {4, -10}, true},
                    // Неправильные положительные дроби
                    {{3, 1}, {3, 1}, true},
                    {{3, 1}, {6, 2}, true},
                    {{2, 1}, {10, 5}, true},
                    // Неправильные отрицательные дроби
                    {{-3, 1}, {3, -1}, true},
                    {{-3, 1}, {-6, 2}, true},
                    {{-2, 1}, {-10, 5}, true},
                    {{-2, 1}, {10, -5}, true},
                };

                for (const auto& value : values)
                {
                    Rational left = Rational(value.left.first, value.left.second);
                    Rational right = Rational(value.right.first, value.right.second);

                    EXPECT_EQ(left == right, value.expected);
                }
            }

            // Все дроби не равны
            TEST(EqualityOperator, NotEquals)
            {
                const struct
                {
                    std::pair<int, int> left;
                    std::pair<int, int> right;
                    bool expected;
                } values[] =
                {
                    // Секция нулевых знаменателей
                    {{0, 1}, {2, 1}, false},
                    {{0, 1}, {3, 4}, false},
                    {{0, 1}, {-1, 6}, false},
                    {{0, 1}, {INT_MAX, -1}, false},
                    {{0, 1}, {12345, INT_MIN}, false},
                    // Правильные положительные дроби
                    {{1, 22}, {12, 2}, false},
                    {{1, 2}, {2, 44}, false},
                    {{761, 2}, {4, 8}, false},
                    {{22, 333}, {2, 3}, false},
                    {{3, 5}, {4, 5}, false},
                    {{3, 4}, {2, 3}, false},
                    // Правильные отрицательные дроби
                    {{1, 2}, {-1, 2}, false},
                    {{1, 2}, {-2, 4}, false},
                    {{1, 2}, {4, -8}, false},
                    {{2, 3}, {-2, 3}, false},
                    {{2, 5}, {-2, 5}, false},
                    {{2, 5}, {4, -10}, false},
                    // Неправильные положительные дроби
                    {{5, 1}, {3, 1}, false},
                    {{21, 3}, {7, 2}, false},
                    {{2, 1}, {11, 5}, false},
                    // Неправильные отрицательные дроби
                    {{3, 1}, {3, -1}, false},
                    {{3, 1}, {-6, 2}, false},
                    {{2, 1}, {-10, 5}, false},
                    {{2, 1}, {10, -5}, false},
                };

                for (const auto& value : values)
                {
                    Rational left = Rational(value.left.first, value.left.second);
                    Rational right = Rational(value.right.first, value.right.second);

                    EXPECT_EQ(left == right, value.expected);
                }
            }

            
            // Тестирование оператора неравенства с кейсами, где все дроби не равны
            TEST(InequalityOperator, NotEquals)
            {
                // Все дроби не равны
                const struct
                {
                    std::pair<int, int> left;
                    std::pair<int, int> right;
                } values[] =
                {
                    // Секция нулевых знаменателей
                    {{0, 1}, {2, 1}},
                    {{0, 1}, {3, 4}},
                    {{0, 1}, {-1, 6}},
                    {{0, 1}, {INT_MAX, -1}},
                    {{0, 1}, {12345, INT_MIN}},
                    // Правильные положительные дроби
                    {{1, 22}, {12, 2}},
                    {{1, 2}, {2, 44}},
                    {{761, 2}, {4, 8}},
                    {{22, 333}, {2, 3}},
                    {{3, 5}, {4, 5}},
                    {{3, 4}, {2, 3}},
                    // Правильные отрицательные дроби
                    {{1, 2}, {-1, 2}},
                    {{1, 2}, {-2, 4}},
                    {{1, 2}, {4, -8}},
                    {{2, 3}, {-2, 3}},
                    {{2, 5}, {-2, 5}},
                    {{2, 5}, {4, -10}},
                    // Неправильные положительные дроби
                    {{5, 1}, {3, 1}},
                    {{21, 3}, {7, 2}},
                    {{2, 1}, {11, 5}},
                    // Неправильные отрицательные дроби
                    {{3, 1}, {3, -1}},
                    {{3, 1}, {-6, 2}},
                    {{2, 1}, {-10, 5}},
                    {{2, 1}, {10, -5}}
                };

                for (const auto& value : values)
                {
                    Rational left = Rational(value.left.first, value.left.second);
                    Rational right = Rational(value.right.first, value.right.second);

                    EXPECT_EQ(left != right, true);
                }
            }

            // Тестирование оператора неравенства с кейсами, где все дроби равны
            TEST(InequalityOperator, Equals)
            {
                const struct
                {
                    std::pair<int, int> left;
                    std::pair<int, int> right;
                } values[] =
                {
                    // Секция нулевых знаменателей
                    {{0, 1}, {0, 1}},
                    {{0, 1}, {0, 4}},
                    {{0, 1}, {0, 6}},
                    {{0, 1}, {0, -1}},
                    {{0, 1}, {0, INT_MIN}},
                    // Правильные положительные дроби
                    {{1, 2}, {1, 2}},
                    {{1, 2}, {2, 4}},
                    {{1, 2}, {4, 8}},
                    {{2, 3}, {2, 3}},
                    {{2, 5}, {2, 5}},
                    {{2, 5}, {4, 10}},
                    // Правильные отрицательные дроби
                    {{-1, 2}, {-1, 2}},
                    {{1, -2}, {-2, 4}},
                    {{-1, 2}, {4, -8}},
                    {{-2, 3}, {-2, 3}},
                    {{-2, 5}, {-2, 5}},
                    {{-2, 5}, {4, -10}},
                    // Неправильные положительные дроби
                    {{3, 1}, {3, 1}},
                    {{3, 1}, {6, 2}},
                    {{2, 1}, {10, 5}},
                    // Неправильные отрицательные дроби
                    {{-3, 1}, {3, -1}},
                    {{-3, 1}, {-6, 2}},
                    {{-2, 1}, {-10, 5}},
                    {{-2, 1}, {10, -5}},
                };

                for (const auto& value : values)
                {
                    Rational left = Rational(value.left.first, value.left.second);
                    Rational right = Rational(value.right.first, value.right.second);

                    EXPECT_EQ(left != right, false);
                }
            }



            // Операторы умножения

            TEST(operators_multiply, other_integer)
            {
                // Зададим числитель и значенатель
                const struct
                {
                    std::pair<int, int> init;
                    int multiplier;
                    std::pair<int, int> res;
                } values[] =
                {
                    // Нулевой числитель
                    {{0, 1}, 1, {0, 1}},
                    {{0, 1}, -1, {0, 1}},
                    {{0, 1}, 2, {0, 1}},
                    {{0, 1}, -2, {0, 1}},
                    // Не нулевой числитель
                    {{1, 2}, 1, {1, 2}},
                    {{1, 2}, -1, {-1, 2}},
                    {{2, 7}, 3, {6, 7}},
                    {{2, 7}, -3, {-6, 7}},
                    {{3, 11}, 2, {6, 11}},
                    {{3, 11}, -2, {-6, 11}},
                    // Сокращаемая дробь после умножения
                    {{2, 9}, 3, {2, 3}},
                    {{2, 9}, -3, {-2, 3}},
                    {{1, 16}, 4, {1, 4}},
                    {{1, 16}, -4, {-1, 4}},
                };

                for (const auto &value : values)
                {
                    const std::pair<int, int> init = value.init;

                    Rational rational = Rational(init.first, init.second) * value.multiplier;

                    const std::pair<int, int> res = value.res;

                    EXPECT_EQ(rational.Numerator(), res.first);

                    EXPECT_EQ(rational.Denominator(), res.second);

                }
            }

            TEST(operators_multiply, other_rational)
            {
                // Зададим числитель и значенатель
                const struct
                {
                    std::pair<int, int> left;
                    std::pair<int, int> right;
                    std::pair<int, int> res;
                } values[] =
                {
                    // Нулевой числитель
                    {{0, 1}, {0, 1}, {0, 1}},
                    {{0, 1}, {1, 2}, {0, 1}},
                    {{0, 1}, {-1, 2}, {0, 1}},
                    {{0, 1}, {4, 5}, {0, 1}},
                    {{0, 1}, {-4, 5}, {0, 1}},
                    {{0, 1}, {5, 1}, {0, 1}},
                    {{0, 1}, {-5, 1}, {0, 1}},
                    {{0, 1}, {5, 7}, {0, 1}},
                    {{0, 1}, {-5, 7}, {0, 1}},
                    // Не нулевой числитель
                    {{1, 1}, {1, 1}, {1, 1}},
                    {{1, 1}, {-1, 1}, {-1, 1}},
                    {{1, 2}, {1, 2}, {1, 4}},
                    {{1, 2}, {-1, 2}, {-1, 4}},
                    {{2, 3}, {1, 4}, {1, 6}},
                    {{2, 3}, {-1, 4}, {-1, 6}},
                    {{7, 2}, {1, 4}, {7, 8}},
                    {{7, 2}, {-1, 4}, {-7, 8}},
                    {{1, 1}, {4, 1}, {4, 1}},
                    {{1, 1}, {-4, 1}, {-4, 1}},
                    {{3, 8}, {2, 1}, {3, 4}},
                    {{3, 8}, {-2, 1}, {-3, 4}},
                    {{3, 5}, {2, 1}, {6, 5}},
                    {{3, 5}, {-2, 1}, {-6, 5}},
                    {{3, 5}, {1, 2}, {3, 10}},
                    {{3, 5}, {-1, 2}, {-3, 10}},
                };

                for (const auto& value : values)
                {
                    Rational left = Rational(value.left.first, value.left.second);
                    Rational right = Rational(value.right.first, value.right.second);

                    Rational res = left * right;

                    EXPECT_EQ(res.Numerator(), value.res.first);

                    EXPECT_EQ(res.Denominator(), value.res.second);

                }
            }


            TEST(operators_multiply, and_assign_other_int)
            {
                // Зададим числитель и значенатель
                const struct
                {
                    std::pair<int, int> init;
                    int multiplier;
                    std::pair<int, int> res;
                } values[] =
                {
                    // Нулевой числитель
                    {{0, 1}, 1, {0, 1}},
                    {{0, 1}, -1, {0, 1}},
                    {{0, 1}, 2, {0, 1}},
                    {{0, 1}, -2, {0, 1}},
                    // Не нулевой числитель
                    {{1, 2}, 1, {1, 2}},
                    {{1, 2}, -1, {-1, 2}},
                    {{2, 7}, 3, {6, 7}},
                    {{2, 7}, -3, {-6, 7}},
                    {{3, 11}, 2, {6, 11}},
                    {{3, 11}, -2, {-6, 11}},
                    // Сокращаемая дробь после умножения
                    {{2, 9}, 3, {2, 3}},
                    {{2, 9}, -3, {-2, 3}},
                    {{1, 16}, 4, {1, 4}},
                    {{1, 16}, -4, {-1, 4}},
                };

                for (const auto& value : values)
                {
                    const std::pair<int, int> init = value.init;

                    Rational rational(init.first, init.second);

                    rational *= value.multiplier;

                    const std::pair<int, int> res = value.res;

                    EXPECT_EQ(rational.Numerator(), res.first);

                    EXPECT_EQ(rational.Denominator(), res.second);
                }
            }

            TEST(operators_multiply, and_assign_other_rational)
            {
                // Зададим числитель и значенатель
                const struct
                {
                    std::pair<int, int> left;
                    std::pair<int, int> right;
                    std::pair<int, int> res;
                } values[] =
                {
                    // Нулевой числитель
                    {{0, 1}, {0, 1}, {0, 1}},
                    {{0, 1}, {1, 2}, {0, 1}},
                    {{0, 1}, {-1, 2}, {0, 1}},
                    {{0, 1}, {4, 5}, {0, 1}},
                    {{0, 1}, {-4, 5}, {0, 1}},
                    {{0, 1}, {5, 1}, {0, 1}},
                    {{0, 1}, {-5, 1}, {0, 1}},
                    {{0, 1}, {5, 7}, {0, 1}},
                    {{0, 1}, {-5, 7}, {0, 1}},
                    // Не нулевой числитель
                    {{1, 1}, {1, 1}, {1, 1}},
                    {{1, 1}, {-1, 1}, {-1, 1}},
                    {{1, 2}, {1, 2}, {1, 4}},
                    {{1, 2}, {-1, 2}, {-1, 4}},
                    {{2, 3}, {1, 4}, {1, 6}},
                    {{2, 3}, {-1, 4}, {-1, 6}},
                    {{7, 2}, {1, 4}, {7, 8}},
                    {{7, 2}, {-1, 4}, {-7, 8}},
                    {{1, 1}, {4, 1}, {4, 1}},
                    {{1, 1}, {-4, 1}, {-4, 1}},
                    {{3, 8}, {2, 1}, {3, 4}},
                    {{3, 8}, {-2, 1}, {-3, 4}},
                    {{3, 5}, {2, 1}, {6, 5}},
                    {{3, 5}, {-2, 1}, {-6, 5}},
                    {{3, 5}, {1, 2}, {3, 10}},
                    {{3, 5}, {-1, 2}, {-3, 10}},
                };

                for (const auto& value : values)
                {
                    Rational left = Rational(value.left.first, value.left.second);
                    Rational right = Rational(value.right.first, value.right.second);

                    left *= right;

                    EXPECT_EQ(left.Numerator(), value.res.first);

                    EXPECT_EQ(left.Denominator(), value.res.second);
                }
            }


        }

       

    }; // End ClassesTest namespace

}; // End IdiomsCpp namespace
