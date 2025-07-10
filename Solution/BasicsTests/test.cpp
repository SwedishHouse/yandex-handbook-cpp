#include "pch.h"
#include "basics.h"

#include <string>

class MyClassTest : public ::testing::Test {
protected:

    // Объект класса для тестов
    FirstSteps testFirstSteps;
    DataTypes testDataTypes;
    BranchesAndCycles testBranchesAndCycles;
	VectorsAndStrings testVectorsAndStrings;

    // Дополнительные ресурсы
    std::streambuf* original_cout_buf;
    std::stringstream captured_output;

    // Настройка перед каждым тестом
    void SetUp() override {

        // Инициализация объекта с параметрами
        testFirstSteps = FirstSteps();
        testDataTypes = DataTypes();
        testBranchesAndCycles = BranchesAndCycles();
		testVectorsAndStrings = VectorsAndStrings();
        // Перенаправляем вывод cout
        original_cout_buf = std::cout.rdbuf();
        std::cout.rdbuf(captured_output.rdbuf());
    }

    // Очистка после каждого теста
    void TearDown() override {
        // Восстанавливаем стандартный вывод
        std::cout.rdbuf(original_cout_buf);

        // Очищаем буфер
        captured_output.str("");
        captured_output.clear();
    }

    // Вспомогательные методы
    void simulate_input(const std::string& input) {
        std::istringstream test_input(input);
        std::streambuf* orig_cin = std::cin.rdbuf(test_input.rdbuf());
        // Ввод будет автоматически использован в тесте
    }
};

TEST_F(MyClassTest, TestBasic_A)
{
    testFirstSteps.a();
    const std::string res = "C++ is a general-purpose programming language with a bias towards systems programming that\n  - is a better C\n  - supports data abstraction\n  - supports object-oriented programming\n  - supports generic programming.\n";
    EXPECT_EQ(captured_output.str(), res);
}


TEST_F(MyClassTest, TestBasic_B)
{
    const int a = 4, b = 5;

    testFirstSteps.b(a, b);
    EXPECT_EQ(captured_output.str(), std::to_string(a + b) + '\n');
}

TEST_F(MyClassTest, TestDataTypes_A)
{
    ASSERT_NEAR(testDataTypes.a(1.1), 0.433071, 0.0001);
}

TEST_F(MyClassTest, TestDataTypes_B)
{
    EXPECT_EQ(testDataTypes.b(10), 55);
    EXPECT_EQ(testDataTypes.b(100), 5050);
}


TEST_F(MyClassTest, BranchesAndCycles_A)
{
    EXPECT_EQ(testBranchesAndCycles.a(1, 1, 2, 2), "YES");
    EXPECT_EQ(testBranchesAndCycles.a(1, 1, 2, 3), "NO");
    EXPECT_EQ(testBranchesAndCycles.a(5, 6, 3, 3), "NO");
}

TEST_F(MyClassTest, BranchesAndCycles_B)
{
    EXPECT_EQ(testBranchesAndCycles.b(3, 4, 10), "UNDEFINED");
    EXPECT_EQ(testBranchesAndCycles.b(3, 4, 5), "YES");
}

TEST_F(MyClassTest, BranchesAndCycles_C)
{
    EXPECT_EQ(testBranchesAndCycles.c(2003), "NO");
    EXPECT_EQ(testBranchesAndCycles.c(2004), "YES");
    EXPECT_EQ(testBranchesAndCycles.c(3000), "NO");
}

TEST_F(MyClassTest, BranchesAndCycles_D)
{
    EXPECT_EQ(testBranchesAndCycles.d(1, 2001), 31);
    EXPECT_EQ(testBranchesAndCycles.d(2 ,2001), 28);
}

TEST_F(MyClassTest, BranchesAndCycles_E)
{
    testBranchesAndCycles.e(7, 31);
	const std::string expected_output = "                   1 \n 2  3  4  5  6  7  8 \n 9 10 11 12 13 14 15 \n16 17 18 19 20 21 22 \n23 24 25 26 27 28 29 \n30 31 ";
    EXPECT_EQ(captured_output.str(), expected_output);
}

TEST_F(MyClassTest, BranchesAndCycles_F)
{
    EXPECT_EQ(testBranchesAndCycles.f(59), 14);
    EXPECT_EQ(testBranchesAndCycles.f(11), 2);
}

TEST_F(MyClassTest, BranchesAndCycles_G)
{
    ASSERT_NEAR(testBranchesAndCycles.g(3), 0.833333, 0.0001);
    ASSERT_NEAR(testBranchesAndCycles.g(2), 0.5, 0.0001);
    ASSERT_NEAR(testBranchesAndCycles.g(1), 1.0, 0.0001);
}

TEST_F(MyClassTest, VectorsAndStrings_A)
{
    const std::string password = "Vasya123";
    EXPECT_EQ(testVectorsAndStrings.a(password), "YES");

    const std::string password_no = "Vasya123\n";
    EXPECT_EQ(testVectorsAndStrings.a(password_no), "NO");
}

TEST_F(MyClassTest, VectorsAndStrings_B)
{
    const std::string word_one = "ammonium";
    EXPECT_EQ(testVectorsAndStrings.b(word_one), "a500");

    const std::string word_two = "implementation";
    EXPECT_EQ(testVectorsAndStrings.b(word_two), "i514");
}

TEST_F(MyClassTest, VectorsAndStrings_C)
{
	std::vector<unsigned int> vec = { 1, 2, 3, 5, 4 };
    std::vector<unsigned int> res = { 1, 2, 3, 5, 4 };
    EXPECT_EQ(testVectorsAndStrings.c(vec), res);

    vec = { 11, 6, 8, 2, 10, 9, 4, 7, 3, 1, 5 };
    res = { 10, 4, 9, 7, 11, 2, 8, 3, 6, 5, 1 };
    EXPECT_EQ(testVectorsAndStrings.c(vec), res);
}

TEST_F(MyClassTest, VectorsAndStrings_D)
{
    std::vector<std::string> vec = { "one", "two", "three"};
    std::vector<std::string> res = { "two", "three", "one" };
    EXPECT_EQ(testVectorsAndStrings.d(vec), res);
}

TEST_F(MyClassTest, VectorsAndStrings_E)
{
	std::string input = "hello world";
    EXPECT_EQ(testVectorsAndStrings.e(input), "NO");

    input = "never odd or even";
    EXPECT_EQ(testVectorsAndStrings.e(input), "YES");
}