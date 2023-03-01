#pragma once

#include <iostream>

class IncompleteFileException : public std::exception
{
public:
    using _Mybase = std::exception;
    explicit IncompleteFileException(const std::string& _Message) : _Mybase(_Message.c_str()) {}
};



