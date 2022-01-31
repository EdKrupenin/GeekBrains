#pragma once

#include <stdint.h>
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
    static std::mutex m_loger;
    static std::mutex m_screen;
	
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
    class ScreenSingleton
    {
        ScreenSingleton() { }
        //Delete copy and assignment constructor
        ScreenSingleton(const ScreenSingleton& root) = delete;
        ScreenSingleton& operator=(const ScreenSingleton&) = delete;
        static ScreenSingleton* _initScreenSing;
    public:
        
        static ScreenSingleton& getInstance()
        {
            std::lock_guard<std::mutex> lock(m_screen);
            return *(_initScreenSing ? _initScreenSing : new ScreenSingleton());
        }

        void ClrScr();

        void __fastcall GotoXY(double x, double y);

        uint16_t GetMaxX();

        uint16_t GetMaxY();

        void SetColor(ConsoleColor color);

    	~ScreenSingleton()
    	{
            delete _initScreenSing;
    	}
    };

	class IFileLigger
	{
	public:
        virtual void __fastcall OpenLogFile(const std::string& FN) = 0;

        virtual void CloseLogFile() = 0;

        virtual void __fastcall WriteToLog(const std::string& str) = 0;

        virtual void __fastcall WriteToLog(const std::string& str, int n) = 0;

        virtual void __fastcall WriteToLog(const std::string& str, double d) = 0;
	};
	
	//=============================================================================================
    class FileLoggerSingletone : public IFileLigger
    {
        FileLoggerSingletone() {}
        //Delete copy and assignment constructor
        FileLoggerSingletone(const FileLoggerSingletone& logfile) = delete;
        FileLoggerSingletone& operator=(const FileLoggerSingletone&) = delete;
        static FileLoggerSingletone* _initLoger;
        std::ofstream logOut{};
    public:
        ~FileLoggerSingletone()
        {
            delete _initLoger;
        }
    	/// <summary>
        /// Getter singletone class. Use lock guard for multithread
        /// </summary>
        /// <returns></returns>
        static FileLoggerSingletone& getInstance()
        {
            std::lock_guard<std::mutex> lock(m_loger);
            _initLoger = (_initLoger ? _initLoger : new FileLoggerSingletone());
            return *_initLoger;
        }
            	
        void __fastcall OpenLogFile(const std::string& FN) override;

        void CloseLogFile() override;

        void __fastcall WriteToLog(const std::string& str) override;

        void __fastcall WriteToLog(const std::string& str, int n) override;

        void __fastcall WriteToLog(const std::string& str, double d) override;
    };
	//=============================================================================================

    class proxy_loger : public IFileLigger
    {
        FileLoggerSingletone& _initLoger;
        int logCounter{};
    public:
       proxy_loger() : _initLoger(FileLoggerSingletone::getInstance()), logCounter(1)
       {       }

       ~proxy_loger()
       {
       }
    	
       void __fastcall OpenLogFile(const std::string& FN) override;

       void CloseLogFile() override;

       void __fastcall WriteToLog(const std::string& str) override;

       void __fastcall WriteToLog(const std::string& str, int n) override;

       void __fastcall WriteToLog(const std::string& str, double d) override;
    };

   
};