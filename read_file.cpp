#include <iostream>
#include <string>
#include <fstream> // Required for file stream operations
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
                 cout<<"path: "<<itemPath<<endl; //it has been sent to print properties. (whole path)
                 cout<<"name: "<<itemName<<endl;//only file name.
            }
        }
    }
    closedir(dir);
}
void readcontentInInteger(string fileName)
{
    ifstream inputFile(fileName);

    if (!inputFile.is_open())
    {
        cerr << "Failed to open the file." << endl;
    }

    char readData;

    bool flag = false;

    // to read data and represent it in Int form
    cout << "data represented in Int format:\n";
    while (inputFile.read(&readData, sizeof(readData)))
    {
        cout << static_cast<int>(readData) << " ";
        flag = true;
    }
    if (flag)
        cout << "\nFile " << fileName << " read successfully." << endl;
}

int main()
{
    directoryPath = "/home/muntaha/Desktop/SPL-new/dummy"; 

    listOfFilesInDirectory(directoryPath, directoryItems, directoryNames);

    printProperties(directoryItems,directoryNames);
    //similarityChecking(directoryItems,fcb,directoryNames);
    checkEquality(directoryItems,fcb,directoryNames);
}