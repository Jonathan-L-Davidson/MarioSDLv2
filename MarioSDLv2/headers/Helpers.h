#pragma once
#include "Global.h"

// Code by Martin Broadhurst, code is used for level management to get list of files within a directory. Sourced from http://www.martinbroadhurst.com/list-the-files-in-a-directory-in-c.html
// Personally, I would've liked to program my own, I would've used the boost library, however, boost isn't installed on the university computers and it doesn't have C++17 libraries.
// This would've took too much time to make using fstream, so I sourced this instead.

// Referenced - START

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

typedef std::vector<std::string> stringvec;

#include <windows.h>

void read_directory(const std::string& name, stringvec& v)
{
    std::string pattern(name);
    pattern.append("\\*");
    WIN32_FIND_DATA data;
    HANDLE hFind;
    if ((hFind = FindFirstFile(pattern.c_str(), &data)) != INVALID_HANDLE_VALUE) {
        do {
            v.push_back(data.cFileName);
        } while (FindNextFile(hFind, &data) != 0);
        FindClose(hFind);
    }
}

// Reference - END