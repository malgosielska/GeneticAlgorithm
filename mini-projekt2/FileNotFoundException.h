#pragma once
#include <iostream>

class FileNotFoundException : public std::runtime_error
{
public:
    using _Mybase = std::runtime_error;
    explicit FileNotFoundException(const std::string& _Message) : _Mybase(_Message.c_str()) {}
};

