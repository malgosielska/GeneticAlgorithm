#pragma once
#include <iostream>

class InvalidProbabilityValueException : public std::exception {

public:
    using _Mybase = std::exception;

    explicit InvalidProbabilityValueException(const std::string& _Message) : _Mybase(_Message.c_str()) {}

    //explicit NegativeNumberException(const char* _Message) : _Mybase(_Message) {}
};

