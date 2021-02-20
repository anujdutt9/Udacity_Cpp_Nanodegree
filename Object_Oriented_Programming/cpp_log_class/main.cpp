#include <iostream>
#include <string>

class Log{

// Public Variables
public:
    const int LogLevelError = 0;
    const int LogLevelWarning = 1;
    const int LogLevelInfo = 2;

// Private Variables
private:
    // using "m_" tells that this is a class member variable
    // helps to differentiate between local and class member variables
    int m_LogLevel = LogLevelInfo;

// Public Methods
public:
    void SetLevel(int level){
        m_LogLevel = level;
    }

    void Error(const char* message){
        if (m_LogLevel >= LogLevelError)
            std::cout << "[ERROR]: " << message << std::endl;
    }

    void Warn(const char* message){
        if (m_LogLevel >= LogLevelWarning)
            std::cout << "[WARNING]: " << message << std::endl;
    }

    void Info(const char* message){
        if (m_LogLevel >= LogLevelInfo)
            std::cout << "[INFO]: " << message << std::endl;
    }

};

int main(){
    // Instantiate Log class
    Log log;

    // set logging level
    log.SetLevel(log.LogLevelWarning);
    
    // set error message
    log.Error("error!!");

    // set warning message
    log.Warn("warning!!");

    // set info message
    log.Info("info!!");


    return 0;
}