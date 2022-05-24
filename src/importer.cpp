#include "importer.h"
#include <fstream>

bool fileToVector(const std::string &fileName, std::vector<std::string> &allLines)
{
    bool success = false;
    std::ifstream file(fileName);
    if (file.is_open())
    {
        std::string str;
        while (std::getline(file, str))
        {
            allLines.push_back(str);
        }
        file.close();
        success = true;
    }
    return success;
};