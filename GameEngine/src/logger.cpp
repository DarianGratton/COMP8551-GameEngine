#include "logger.h"
#include <iostream>

Logger::Logger() {
    file = ofstream(FILE_NAME, fstream::trunc | fstream::out);
    file.close();
}

Logger::~Logger() {
}

Logger& Logger::operator<<(string text) {
    file = ofstream(FILE_NAME, ofstream::app);
    file << text;
    file.close();
    return *this;
}

Logger& Logger::operator<<(int num) {
    file = ofstream(FILE_NAME, ofstream::app);
    file << num;
    file.close();
    return *this;
}

Logger& Logger::operator<<(uint64_t num) {
    file = ofstream(FILE_NAME, ofstream::app);
    file << num;
    file.close();
    return *this;
}

Logger& Logger::operator<<(float num) {
    file = ofstream(FILE_NAME, ofstream::app);
    file << num;
    file.close();
    return *this;
}

Logger& Logger::operator<<(double num) {
    file = ofstream(FILE_NAME, ofstream::app);
    file << num;
    file.close();
    return *this;
}

Logger& Logger::operator<<(char c) {
    file = ofstream(FILE_NAME, ofstream::app);
    file << c;
    file.close();
    return *this;
}