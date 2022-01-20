
#include <iostream>

#include "Plane.h"
#include "MyTools.h"

using namespace std;
using namespace MyTools;

void Plane::Draw() const
{
    MyTools::FileLoggerSingletone::GetInstance().SetColor(CC_LightBlue);
    FileLoggerSingletone::GetInstance().GotoXY(x, y);
    cout << "=========>";
    FileLoggerSingletone::GetInstance().GotoXY(x - 2, y - 1);
    cout << "===";
    FileLoggerSingletone::GetInstance().GotoXY(x + 3, y - 1);
    cout << "\\\\\\\\";
    FileLoggerSingletone::GetInstance().GotoXY(x + 3, y + 1);
    cout << "////";
}
