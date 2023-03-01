#pragma once
#include <iostream>

class NegativeNumberException : public std::exception {

public:
    using _Mybase = std::exception;
    explicit NegativeNumberException(const std::string& _Message) : _Mybase(_Message.c_str()) {}
};
