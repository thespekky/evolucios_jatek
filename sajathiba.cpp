#include <string>
#include <iostream>
using namespace std;
class sajathiba : public exception
{
    string message;

public:
    sajathiba(const string &message) : message(message) {}
    const char *what() const noexcept override
    {
        return message.c_str();
    }
};