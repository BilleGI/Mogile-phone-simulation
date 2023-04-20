#include<iostream>
#include <map>
#include<vector>
#include<algorithm>
#include"telephone.h"

void checkName(std::string& name)
{
    while(true)
    {
        auto it = std::find_if(name.begin(), name.end(), [](const char &c)
        {
            return !std::isalpha(c);
        });

        if(name.end() == it)
            break;

        std::cout << "Enter the correct mean: ";
        std::cin >> name;
    }
}

void checkNum(std::string& num)
{
    while(true)
    {
        auto it = std::find_if(num.begin(), num.end(), [](const char &c)
        {
            return !std::isdigit(c);
        });

        if(num.end() == it)
            break;

        std::cout << "Enter the correct number: +7";
        while(num.size() != 10)
            getline(std::cin, num);
    }
}

void PhoneBook::add()
{
    std::string phoneNum;
    std::string contactName;
    std::cout << "Enter the phone number: +7";
    do
    {
        getline(std::cin, phoneNum);
        if(phoneNum.size() == 10)
            break;
        std::cout << "Enter the 10 characers: +7";
    }while(true);
    checkNum(phoneNum);
    phoneNum = "+7"+phoneNum;

    std::cout << "Enter the name of the contact: ";
    getline(std::cin, contactName);
    checkName(contactName);

    number[phoneNum] = contactName;

    std::map<std::string, std::string>::iterator it;
    it = name.find(contactName);
    if(it == name.end())
        name[contactName] = phoneNum;
    else
        name[contactName] += " " + phoneNum;
}

bool check(std::map<std::string, std::string>& name, std::map<std::string, std::string>& num)
{
    std::string nameOrNum;
    std::cout << "Input the name or number of the contact: ";
    getline(std::cin, nameOrNum);
    std::map<std::string, std::string>::iterator it;
    it = name.find(nameOrNum);
    if(it == name.end())
    {
        it = num.find(nameOrNum);
        if(it == num.end())
        {
            std::cout << "The contact will not find." << std::endl;;
            return false;
        }

        return true;
    }
    else
        return true;
}

void PhoneBook::call()
{
    if(check(name, number))
        std::cout << "CALL" << std::endl;
}

void PhoneBook::sms()
{
    if(check(name,number))
        std::cout << "SMS" << std::endl;
}

void key()
{
    PhoneBook book;
    std::string command;
    std::cout << "List of command: " << std::endl;
    std::cout << "add - add a new number to the address book," << std::endl;
    std::cout << "call - requests information for call," << std::endl;
    std::cout << "sms - requests information for sms," << std::endl;
    std::cout << "exit - exiting the program." << std::endl;

    while(true)
    {
        std::cout << "Enter the command: " << std::endl;
        getline(std::cin, command);

        checkName(command);
        if(command == "exit")
            break;
        else if(command == "add")
            book.add();
        else if(command == "call")
            book.call();
        else if(command == "sms")
            book.sms();
    }
}
