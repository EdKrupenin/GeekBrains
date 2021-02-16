#include <iostream>
#include <clocale>

int main()
{
    setlocale(LC_CTYPE, "Russian"); // Адаптация консоли к русскому языку
    std::cout<<"Привет мир!!!"<<std::endl; //Вывод в консоль Привет мир
    return 0;
}