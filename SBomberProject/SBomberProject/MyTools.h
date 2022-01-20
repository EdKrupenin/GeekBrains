#pragma once

#include <stdint.h>
#include <string>
#include <thread>
#include <conio.h>
#include <windows.h>
#include <stdint.h>
#include <time.h> 

#include <string>
#include <iostream>
#include <fstream>
#include <chrono>
#include <mutex>

namespace MyTools {

    static std::mutex m_singletone;
	
    // Палитра цветов от 0 до 15
    enum ConsoleColor
    {
        CC_Black = 0,
        CC_Blue,
        CC_Green,
        CC_Cyan,
        CC_Red,
        CC_Magenta,
        CC_Brown,
        CC_LightGray,
        CC_DarkGray,
        CC_LightBlue,
        CC_LightGreen,
        CC_LightCyan,
        CC_LightRed,
        CC_LightMagenta,
        CC_Yellow,
        CC_White
    };
	
    //=============================================================================================
	/// <summary>
	/// Singletone класс для управления логами игры
	/// </summary>
    class FileLoggerSingletone
    {
    private:
        /// <summary>
        /// Конструктор по умолчаию
        /// </summary>
        FileLoggerSingletone() {}

        //Delete copy and assignment constructor
        FileLoggerSingletone(const FileLoggerSingletone& logfile) = delete;
        FileLoggerSingletone& operator=(const FileLoggerSingletone&) = delete;
        static FileLoggerSingletone* _initLoger;
        std::ofstream logOut;
    public:
        /// <summary>
        /// Getter singletone class. Use lock guard for multithread
        /// </summary>
        /// <returns></returns>
        static FileLoggerSingletone& GetInstance()
        {
             std::lock_guard<std::mutex> lock(m_singletone);
             return *(_initLoger ? _initLoger : new FileLoggerSingletone());
        }

        /// <summary>
        /// Open log file for write
        /// </summary>
        /// <param name="FN">Name logFile</param>
        /// <returns></returns>
        void __fastcall OpenLogFile(const std::string& FN);

        void CloseLogFile();

        void __fastcall WriteToLog(const std::string& str);

        void __fastcall WriteToLog(const std::string& str, int n);

        void __fastcall WriteToLog(const std::string& str, double d);

        void ClrScr();

        void __fastcall GotoXY(double x, double y);

        uint16_t GetMaxX();

        uint16_t GetMaxY();

        void SetColor(ConsoleColor color);
    	
        std::string GetCurDateTime();
    };
	//=============================================================================================

};