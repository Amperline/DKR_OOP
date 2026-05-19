#include "logger.h"
#include <fstream>
#include <chrono>
#include <filesystem>
#include <sstream>

Logger::Logger(std::string file_name)
{
    if (!std::filesystem::exists("logs")) {
        std::filesystem::create_directory("logs");
    }
    if(file_name.empty())
    {
        file_name = "log" + std::to_string(m_number_of_logs);
        m_number_of_logs++;
    }
    file = new std::fstream("logs/" + file_name + ".txt", std::ios::out);
    *file << "START LOG" << std::endl;
}

Logger::~Logger()
{
    if(file != nullptr)
    {
        *file << "END LOG";
        file->close();
        delete file;
    }
}

static std::chrono::steady_clock::time_point start_time;
void Logger::log(std::string data)
{
    auto now = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - start_time).count();
    //[154 ms] lalala.
    std::stringstream stream;
    if(!global_logger_active)
    {
        stream << "[" << elapsed << " ms from start] ";
    }
    stream << data;
    std::string str_to_log = stream.str();
    *file << str_to_log << std::endl;

    //only data
    stream.str("");
    stream << data;
    str_to_log = stream.str();

    if(!global_logger_active)
    {
        global_logger_active = true;

        stream.str("");
        stream << "(Adress: " << this << ") " << str_to_log; 
        str_to_log = stream.str();
        static_logger.log(str_to_log);

        global_logger_active = false;
    }
}