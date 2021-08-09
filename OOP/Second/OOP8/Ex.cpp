#include "Ex.h"



Ex::Ex(int input) : x{input}
{
}

char const* Ex::what() const
{
    static std::string message{};
    message = CreateMessage();
    return message.c_str();
}

std::string Ex::CreateMessage() const
{
    std::strstream message;
    message << "Parametr = " << x;
    message << "; Exception !!! Bar::y + input a > 100 \0";
    return message.str();
}
