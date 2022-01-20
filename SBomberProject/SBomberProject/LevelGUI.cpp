#include <iostream>

#include "LevelGUI.h"
#include "MyTools.h"

using namespace std;
using namespace MyTools;

void LevelGUI::Draw() const
{
    MyTools::FileLoggerSingletone::GetInstance().SetColor(CC_White);

    FileLoggerSingletone::GetInstance().GotoXY(x, y);
    char* buf = new (nothrow) char[width + 1];
    if (buf == nullptr)
    {
        return;
    }
    memset(buf, '+', width);
    buf[width] = '\0';
    cout << buf;
    FileLoggerSingletone::GetInstance().GotoXY(x, y + height);
    cout << buf;
    delete [] buf;
    buf = nullptr;
    
    for (size_t i = size_t(y); i < height + y; i++)
    {
        FileLoggerSingletone::GetInstance().GotoXY(x, (double)i);
        cout << "+";
        FileLoggerSingletone::GetInstance().GotoXY(x + width - 1, (double)i);
        cout << "+";
    }

    FileLoggerSingletone::GetInstance().GotoXY(3, 1);
    cout << "FramePerSecond: " << static_cast<int>(fps / (passedTime / 1000.0));
    FileLoggerSingletone::GetInstance().GotoXY(25, 1);
    cout << "PassedTime: " << static_cast<int>(passedTime / 1000.0) << " sec";
    FileLoggerSingletone::GetInstance().GotoXY(46, 1);
    cout << "BombsNum: " << bombsNumber;
    FileLoggerSingletone::GetInstance().GotoXY(62, 1);
    cout << "Score: " << score;
}

void __fastcall LevelGUI::SetParam(uint64_t passedTimeNew, uint64_t fpsNew, uint16_t bombsNumberNew, int16_t scoreNew)
{
    passedTime = passedTimeNew;
    fps = fpsNew;
    bombsNumber = bombsNumberNew;
    score = scoreNew;
}
