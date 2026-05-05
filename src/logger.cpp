#include "logger.h"
#include <fstream>


Logger::Logger(std::string file_name)
{
    if(file_name.empty())
    {
        file_name = "log" + m_number_of_logs;
        m_number_of_logs++;
    }
    file = new std::fstream(file_name + ".txt");
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

void Logger::log(std::string data)
{
    *file << data << std::endl;
}

