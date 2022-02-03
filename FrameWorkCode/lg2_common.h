#pragma once
#include <git2.h>
#include <string>
#include <QString>
class lg2_common
{
public:
    void PostError(QString errorMessage);
    int check_lg2(int error, std::string message, std::string extra);
};

