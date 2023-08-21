#include <iostream>
#include <string>
#include <fstream> // Required for file stream operations
#include <string.h>
#include <vector>
#include <dirent.h>
#include <sys/stat.h>
using namespace std;
vector<string> fileContents;
void listOfFilesInDirectory(const char *directorypath, vector<string> &paths)
{
    DIR *dir;
    struct dirent *entry;
    dir = opendir(directorypath);
    if (!dir)
    {
        cerr << "Error in opening directory " << directorypath << endl;
    }
    cout << "File and Directory names are: ";
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
    const char *directoryPath = "/home/muntaha/Desktop/SPL-01"; // Current directory
    vector<string> directoryItems;
    listOfFilesInDirectory(directoryPath, directoryItems);

    // creating a vector to store file contents

    for (const string &itemPath : directoryItems)
    {
        string content;
        read_file(itemPath, content);
        fileContents.push_back(content);
    }
}
