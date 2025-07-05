#include "pch.h"
#include "basics.h"

#include <string>

class MyClassTest : public ::testing::Test {
protected:
    // Объект класса для тестов
    FirstSteps test_object;

    // Дополнительные ресурсы
    std::streambuf* original_cout_buf;
    std::stringstream captured_output;

    // Настройка перед каждым тестом
    void SetUp() override {
        // Инициализация объекта с параметрами
        test_object = FirstSteps(/* параметры конструктора */);

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

TEST_F(MyClassTest, TestBasicA)
{
    test_object.a();
    const std::string res = "C++ is a general-purpose programming language with a bias towards systems programming that\n  - is a better C\n  - supports data abstraction\n  - supports object-oriented programming\n  - supports generic programming.\n";
    EXPECT_EQ(captured_output.str(), res);
}


TEST_F(MyClassTest, TestBasicB)
{
    const int a = 4, b = 5;

    test_object.b(a, b);
    EXPECT_EQ(captured_output.str(), std::to_string(a + b) + '\n');
}
