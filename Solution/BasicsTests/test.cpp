#include "pch.h"
#include "basics.h"

#include <string>

class MyClassTest : public ::testing::Test {
protected:
    // ������ ������ ��� ������
    FirstSteps test_object;

    // �������������� �������
    std::streambuf* original_cout_buf;
    std::stringstream captured_output;

    // ��������� ����� ������ ������
    void SetUp() override {
        // ������������� ������� � �����������
        test_object = FirstSteps(/* ��������� ������������ */);

        // �������������� ����� cout
        original_cout_buf = std::cout.rdbuf();
        std::cout.rdbuf(captured_output.rdbuf());
    }

    // ������� ����� ������� �����
    void TearDown() override {
        // ��������������� ����������� �����
        std::cout.rdbuf(original_cout_buf);

        // ������� �����
        captured_output.str("");
        captured_output.clear();
    }

    // ��������������� ������
    void simulate_input(const std::string& input) {
        std::istringstream test_input(input);
        std::streambuf* orig_cin = std::cin.rdbuf(test_input.rdbuf());
        // ���� ����� ������������� ����������� � �����
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
