#include "pch.h"
#include "handbook_tasks.h"

#include <sstream> // Для std::stringstream
#include <streambuf> // Для std::streambuf

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
            {.text = {      "My",
                            "program",
                            "is",
                            "awful",
                            "bad",
                            "poor",
                            "wrong",
                            "awesome" },

            .commands = {   "Down",
                            "Down",
                            "Down",
                            "Shift",
                            "Down",
                            "Down",
                            "Down",
                            "Down",
                            "Ctrl+X" },

            . result = {    "My",
                            "program",
                            "is",
                            "awesome" }
            },
            {.text = {      "program",
                            "is awesome",
                            "My",
                            "is awful" },

            .commands = {  "Down",
                            "Down",
                            "Down",
                            "Ctrl+X",
                            "Up",
                            "Ctrl+X",
                            "Up",
                            "Up",
                            "Ctrl+V" },

            . result = {   "My",
                            "program",
                            "is awesome" },
            },
            {.text = {      "a",
                            "b",
                            "c",
                            "d",
                            "e",
                            "f",
                            "g"},

            .commands = {   "Down",
                            "Shift",
                            "Down",
                            "Down",
                            "Ctrl+X",
                            "Down",
                            "Shift",
                            "Down",
                            "Down",
                            "Down",
                            "Ctrl+V" },

            . result = {    "a",
                            "d",
                            "b",
                            "c",},
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