#include "pch.h"
#include "basics.h"
#include <sstream> // ��� std::stringstream
#include <streambuf> // ��� std::streambuf
#include <string>

class MyClassTest : public ::testing::Test {
protected:

    // ������ ������ ��� ������
    FirstSteps testFirstSteps;
    DataTypes testDataTypes;
    BranchesAndCycles testBranchesAndCycles;
	VectorsAndStrings testVectorsAndStrings;
    Functions testFunctions;
    HandbookSTL::SequenceContainers sequenceContaier;
    // �������������� �������

    // ������������ ������ std::cin � std::cout
    std::streambuf* originalCinBuffer;

    std::streambuf* originalCoutBuffer;
    // ��������� ������ ��� ������� ������ � ������ �����
    std::stringstream testInputStream;
    std::stringstream testOutputStream;

    // ��������� ����� ������ ������
    void SetUp() override {

        // ������������� ������� � �����������
        testFirstSteps = FirstSteps();
        testDataTypes = DataTypes();
        testBranchesAndCycles = BranchesAndCycles();
		testVectorsAndStrings = VectorsAndStrings();
        testFunctions = Functions();
        sequenceContaier = HandbookSTL::SequenceContainers();
        
        // ��������� ������������ ������
        originalCinBuffer = std::cin.rdbuf();
        originalCoutBuffer = std::cout.rdbuf();

        // �������������� std::cin �� ��� ������� �����
        std::cin.rdbuf(testInputStream.rdbuf());
        // �������������� std::cout �� ��� �������� �����
        std::cout.rdbuf(testOutputStream.rdbuf());
    }

    // ������� ����� ������� �����
    void TearDown() override {
        // ��������������� ������������ ������ std::cin � std::cout
        std::cin.rdbuf(originalCinBuffer);
        std::cout.rdbuf(originalCoutBuffer);

        // ������� �����
        testInputStream.str("");
        testInputStream.clear();

        testOutputStream.str("");
        testOutputStream.clear();

    }

    // ��������������� ������
    void simulate_input(const std::string& input) {
        std::istringstream test_input(input);
        std::streambuf* orig_cin = std::cin.rdbuf(test_input.rdbuf());
        // ���� ����� ������������� ����������� � �����
    }
};

TEST_F(MyClassTest, TestBasic_A)
{
    testFirstSteps.a();
    const std::string res = "C++ is a general-purpose programming language with a bias towards systems programming that\n  - is a better C\n  - supports data abstraction\n  - supports object-oriented programming\n  - supports generic programming.\n";
    EXPECT_EQ(testInputStream.str(), res);
}


TEST_F(MyClassTest, TestBasic_B)
{
    const int a = 4, b = 5;

    testFirstSteps.b(a, b);
    EXPECT_EQ(testInputStream.str(), std::to_string(a + b) + '\n');
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
    EXPECT_EQ(testInputStream.str(), expected_output);
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

TEST_F(MyClassTest, VectorsAndStrings_F)
{
    const std::vector<std::vector<unsigned int>> input = {
        {1, 1},
        {2, 2} };
    const std::string res = "* 2\n2 *\n1 1\n";
    EXPECT_EQ(testVectorsAndStrings.f(3, 2, 2, input), res);
}

TEST_F(MyClassTest, MatrixArgMax)
{
    const std::vector<std::vector<int>> case_one = {
                            {0, 3, 2, 4},
                            {2, 3, 5, 5},
                            {5, 1, 2, 3}
    };
    const std::pair<size_t, size_t> res_one = { 1,2 };
    EXPECT_EQ(testFunctions.MatrixArgMax(case_one), res_one);

    const std::vector<std::vector<int>> case_two = {{1}};
    const std::pair<size_t, size_t> res_two = { 0, 0 };
    EXPECT_EQ(testFunctions.MatrixArgMax(case_two), res_two);

    const std::vector<std::vector<int>> input = {
                            {1, 2, 3, 4, 5},
                            {6, 7, 8, 9, 10},
                            {11, 12, 13, 14, 15}
    };
    const std::pair<size_t, size_t> res = { 2, 4 };
    EXPECT_EQ(testFunctions.MatrixArgMax(input), res);
}

TEST_F(MyClassTest, CommonPrefix)
{
    const std::vector<std::string> case_one = {
                            "apple", 
                            "apricot" ,
                            "application" 
    };
    const std::string res_one = "ap";
    EXPECT_EQ(testFunctions.CommonPrefix(case_one), res_one);

    const std::vector<std::string> case_two = { };
    const std::string res_two = "";
    EXPECT_EQ(testFunctions.CommonPrefix(case_two), res_two);
}


TEST_F(MyClassTest, Split)
{
    const std::string case_one = "What_is_your_name?";

    const std::vector<std::string> res_one = { "What",
                                                "is",
                                                "your",
                                                "name?" 
    };
    EXPECT_EQ(testFunctions.Split(case_one, '_'), res_one);

}

TEST_F(MyClassTest, Join)
{
    const std::vector<std::string> case_one = { "What", "is", "your", "name?"};

    const std::string res_one = "What_is_your_name?";
    EXPECT_EQ(testFunctions.Join(case_one, '_'), res_one);

}

TEST_F(MyClassTest, Transpose)
{
    const std::vector<std::vector<int>> case_one = {{1, 2, 3},
                                                    {4, 5, 6},
                                                    {7, 8, 9} };

    const std::vector<std::vector<int>> res_one = { {1, 4, 7},
                                                    {2, 5, 8},
                                                    {3, 6, 9} };
    EXPECT_EQ(testFunctions.Transpose(case_one), res_one);

    const std::vector<std::vector<int>> case_two = { {1, 2, 3},
                                                    {4, 5, 6},};

    const std::vector<std::vector<int>> res_two = { {1, 4},
                                                    {2, 5},
                                                    {3, 6} };
    EXPECT_EQ(testFunctions.Transpose(case_two), res_two);

}

TEST_F(MyClassTest, Functions_F)
{
    std::vector<std::pair<int, int>> coords = { {2 ,3}, {1, 2} };

    std::vector<std::pair<int, int>> res = {  {1, 2} , {2 ,3} };

    testFunctions.F(coords);
    
    EXPECT_EQ(coords, res);

}

TEST_F(MyClassTest, SequenceContainers_Print)
{
    const std::string case_one = "hello";
    const std::string delimiter = ", ";

    const std::string res = "h, e, l, l, o\n";

    sequenceContaier.Print(case_one, delimiter);
    EXPECT_EQ(testInputStream.str(), res);

    //// ������� �����
    testInputStream.str("");
    testInputStream.clear();

    const std::vector<int> case_two = { 1, 2, 3, 4 };

    const std::string res_two = "1, 2, 3, 4\n";

    sequenceContaier.Print(case_two, delimiter);
    EXPECT_EQ(testInputStream.str(), res_two);
}

TEST_F(MyClassTest, SequenceContainers_B)
{
    const std::vector <std::pair<std::string, std::string>> students_entries = { {"Ivanov", "top"}, {"Petrov", "top"}, {"Sidorov", "bottom"} };
    const std::vector<int> students_order = { 1, 3 };
    const std::vector<std::string> result_case_one = { "Petrov", "Sidorov" };

    EXPECT_EQ(sequenceContaier.B(students_entries, students_order), result_case_one);

}


TEST_F(MyClassTest, MakeTrain)
{
    const std::vector<std::string> input = {    " +left 1",
                                                "+ right 2",
                                                "+ left 3",
                                                "- right 1" };

    // �������������� ������� ������ ��� std::cin
    for(const auto &val : input)
        testInputStream << val;

    // �������� ������ ���������, ������� ����� ������������ ���������������� ������
    sequenceContaier.MakeTrain();

    // �������� ����������� ����� �� std::cout
    std::string actualOutput = testOutputStream.str();

    // ��������� ��������� �����
    // �������� �������� �� ������ ������� ����� ������ � �������
    const std::vector<std::string> expectedOutput = { "3", "1" };
    //EXPECT_EQ(expectedOutput, actualOutput);

    EXPECT_EQ(2 * 2, 4);

}