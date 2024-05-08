#pragma once

#include <exception>
#include <string>

class CircleException : public std::exception {
private:
    std::string message; // エラーメッセージ
    
public:
    CircleException(const std::string& msg) : message(msg) {};
    virtual ~CircleException() throw() {};
    void printStackTrace() const {
        std::cerr << "Error in generating Circle : " << message << std::endl;
    }
}
