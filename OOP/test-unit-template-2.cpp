#include "tests/test-common.hpp"
#include <iostream>
#include "default.hpp"

void inputInt(int& value) {
    std::cout << "Enter int : ";
    std::cin >> value;
    while (std::cin.fail() || (std::cin.peek() != '\n') || (std::isdigit(std::cin.peek()))) {
        std::cout << "IDIOT !! Enter again !\n";
        std::cin.clear();  // сбрасывает все биты потока, тоесть поток становится "хорошим"
        std::cin.ignore(); // будет пропускаться до следующей новой строки
        std::cin.sync();   //Удалим данные из буффера
        std::cout << "Enter int : ";
        std::cin >> value;
    }
    std::cout << std::endl;
}

TEST(HomeWork6, Ex1) {
    int value{};
    inputInt(value);
    ASSERT_EQ(value, 10);
}

std::ostream& endl (std::ostream& out) {
    out <<"\n\n";
    out.flush();
    return out;
}

TEST(HomeWork6, Ex2) {
    std::string str{ "This is new endl" };
    std::cout << str << endl;
}