
#include <conio.h>
#include "SBomber.h"
#include "MyTools.h"

using namespace std;

//========================================================================================================================

int main(void)
{
	MyTools::FileLoggerSingletone::GetInstance().OpenLogFile("log.txt");

    SBomber game;

    do {
        game.TimeStart();

        if (_kbhit())
        {
            game.ProcessKBHit();
        }

        MyTools::FileLoggerSingletone::GetInstance().ClrScr();

        game.DrawFrame();
        game.MoveObjects();
        game.CheckObjects();

        game.TimeFinish();

    } while (!game.GetExitFlag());

    MyTools::FileLoggerSingletone::GetInstance().CloseLogFile();

    return 0;
}
