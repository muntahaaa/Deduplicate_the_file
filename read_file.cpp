#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <dirent.h>
#include <sys/stat.h>
#include <cerrno>
#include "read_file.h"
#include "print.cpp"
using namespace std;
vector<string> directoryItems;
vector<string> fileContents;
const char *directoryPath;

void listOfFilesInDirectory(const char *directorypath, vector<string> &paths, vector<string> &names)
{
    DIR *dir;
    struct dirent *entry;
    dir = opendir(directorypath);
    if (!dir)
    {
        cerr << "Error in opening directory " << directorypath << endl;
    }
    else
        cout << "directory opened" << endl;
    while (entry = readdir(dir))
    {

        if (entry->d_type == DT_REG)
        {

            string itemName = entry->d_name;
            if (itemName != "." && itemName != "..")
            {
                names.push_back(itemName);
                string itemPath = string(directorypath) + "/" + itemName;
                paths.push_back(itemPath);
                cout << "path: " << itemPath << endl;
                cout << "name: " << itemName << endl;
            }
        }
    }
    closedir(dir);
}

int main()
{
    directoryPath = "/home/muntaha/Desktop/SPL-new/dummy2";

    listOfFilesInDirectory(directoryPath, directoryItems, directoryNames);

    printProperties(directoryItems, directoryNames);
    similarityChecking(directoryItems, fcb, directoryNames);
    checkEqualities(directoryItems, fcb, directoryNames,directoryPath);
}