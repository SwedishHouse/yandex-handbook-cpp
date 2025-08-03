#include "handbook_tasks.h"

int main()
{
	//throw "Use test for launch!!!";

    struct test_case
    {
        std::vector<std::string> text;
        std::vector<std::string> commands;
        std::list<std::string> result;
    };

    test_case t;

    std::string input;
    while (true)
    {
        std::getline(std::cin, input);

        if (input.empty())
            break;

        t.text.push_back(input);
    }

    while (std::cin >> input)
    {
        if (input.empty())
            break;

        t.commands.push_back(input);
    }

    t.result = HandbookSTL::SequenceContainers::CtrlXV2(t.text, t.commands);

    for (const auto &val : t.result)
        std::cout << val << std::endl;


	return 0;
}