#include <iostream>
#include <string>
#include <fstream> // Required for file stream operations
#include <vector>
#include <dirent.h>
#include <sys/stat.h>
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
    while (entry = readdir(dir))
    {

        if (entry->d_type == DT_REG)
        {
            /*{
                // regular file
                cout << "File: " << entry->d_name << endl;
            }
            else if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0)
            {
                cout << "Directory: " << entry->d_name << endl;
            }*/
            string itemName = entry->d_name;
            if (itemName != "." && itemName != "..")
            {
                names.push_back(itemName);
                string itemPath = string(directorypath) + "/" + itemName;
                paths.push_back(itemPath);
            }
        }
    }
    closedir(dir);
}

void read_file(string fileName, string &fileContent)
{

    ifstream inputFile(fileName); // Replace with file's name, ifstream for input function

    if (!inputFile.is_open())
    {
        cerr << "Failed to open the file." << endl;
    }

    char readData;
    bool flag = false;

    // to read data and represent it in Int form
    while (inputFile.read(&readData, sizeof(readData)))
    {
        // cout << static_cast<int>(readData) << " ";
        //  cout<<byte<<" ";
        flag = true;
    }
    if (flag)
        cout << "\nFile " << fileName << " read successfully." << endl;
    // storing contents in the vector
    while (inputFile.get(readData))
    {
        fileContent += readData;
    }
    cout << "\n"
         << fileName << " content loaded successfully";

    inputFile.close();
}

int main()
{
    directoryPath = "/home/muntaha/Desktop/SPL-01"; // Current directory

    listOfFilesInDirectory(directoryPath, directoryItems, directoryNames);

    printProperties();
}
