// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <string>

// BOOST
#define BOOST_PYTHON_STATIC_LIB
/*
g++ main.cpp -lboost_system -lboost_thread -lpthread -o main
*/

#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <iostream>

// TODO: reference additional headers your program requires here
