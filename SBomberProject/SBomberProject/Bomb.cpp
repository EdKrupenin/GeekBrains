
#include <iostream>

#include "Bomb.h"
#include "MyTools.h"

using namespace std;
using namespace MyTools;

void Bomb::Draw() const
{
    FileLoggerSingletone::GetInstance().SetColor(CC_LightMagenta);
    FileLoggerSingletone::GetInstance().GotoXY(x, y);
    cout << "*";
}