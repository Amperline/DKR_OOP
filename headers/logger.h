#ifndef M_LOGGER
#define M_LOGGER
#include <string>

inline unsigned int m_number_of_logs = 0;

class Logger
{
private:
    inline static bool global_logger_active = false;
    bool first_log_create = false;
    std::string m_filename;
    std::fstream* file = nullptr;

public:
    Logger(std::string filename);
    ~Logger();

    void log(std::string data);
};

inline Logger static_logger("static_log");
#endif