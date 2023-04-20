#pragma once
#include <string>
#include <map>

struct PhoneBook
{
    private:
        std::map<std::string, std::string> number;
        std::map<std::string, std::string> name;
    public:
        void add();
        void call();
        void sms();
};

void key();
