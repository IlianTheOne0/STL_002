#ifndef LIB_H
#define LIB_H

#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::cin;

using std::string;
using std::to_string;

using std::vector;
using std::min_element;
using std::max_element;
using std::sort;
using std::for_each;
using std::find;

#define CREATE_INFO(message) Logger::log(message, InfoADD)
#define INFO(message) Logger::log(message, Info)
#define ERROR(message) Logger::log(message, Error)
#define WARNING(message) Logger::log(message, Warning)
#define LOG_DEFAULT(message) Logger::log(message, DefaultLogger)
#define LOG_OWN(message, color) Logger::log(message, Own, color)

#endif