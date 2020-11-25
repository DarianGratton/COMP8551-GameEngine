#pragma once

#include <string>
#include <fstream>

using namespace std;
class Logger {
    public:
        static Logger& getInstance();

        //remove other constructors
        Logger(Logger const&) = delete;
        void operator=(Logger const&) = delete;

        Logger& operator<<(string text);
        Logger& operator<<(int num);
        Logger& operator<<(uint64_t num);
        Logger& operator<<(float num);
        Logger& operator<<(double num);
        Logger& operator<<(char c);
    private:
        Logger();
        ~Logger();
        ofstream file;
        const string FILE_NAME = "log.txt";
};

inline Logger& Logger::getInstance() {
    static Logger instance;
    return instance;
}