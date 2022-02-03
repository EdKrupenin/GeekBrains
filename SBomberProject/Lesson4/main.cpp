#include <iostream>
#include "Bridge.h"

int main() {
    DrawingImplementor* implementor = new drawBrush(new Rectangle(5));
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
