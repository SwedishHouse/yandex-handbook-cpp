#include "handbook_tasks.h"
#include <iostream>
#include <vector>
#include <memory>


class Animal {
public:
    virtual std::string Voice() const {
        return "Not implemented yet";
    }
    virtual ~Animal() {}
};

class Tiger : public Animal {
    std::string Voice() const override {
        return "Rrrr";
    }
};

class Wolf : public Animal {
    std::string Voice() const override {
        return "Wooo";
    }
};

class Fox : public Animal {
    std::string Voice() const override {
        return "Tyaf";
    }
};

using Zoo = std::vector<std::unique_ptr<Animal>>;

Zoo CreateZoo() {
    Zoo zoo;
    std::string word;
    while (std::cin >> word) {
        if (word == "Tiger") {
            auto t = std::make_unique<Tiger>();
            zoo.push_back(std::move(t));
        }
        else if (word == "Wolf") {
            auto w = std::make_unique<Wolf>();
            zoo.push_back(std::move(w));
        }
        else if (word == "Fox") {
            auto f = std::make_unique<Fox>();
            zoo.push_back(std::move(f));
        }
        else
            throw std::runtime_error("Unknown animal!");
    }
    return zoo;
}

void Process(const Zoo& zoo) {
    for (const auto& animal : zoo) {
        std::cout << animal.get()->Voice() << "\n";
    }
}

int main()
{
    auto z = CreateZoo();
    Process(z);


    return 0;
}