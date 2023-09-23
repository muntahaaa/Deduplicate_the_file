#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include "FCB.h"
#include "Hash.cpp"
FileControlBlock fcb;
struct stat fileInfo;
using namespace std;

bool loadFile(const string &filename, FileControlBlock &fcb)
{
    ifstream file(filename, ios::binary);

    if (!file.is_open())
    {
        cerr << "Error: Unable to open file '" << filename << "'" << endl;
        return false;
    }

    // moving from the beginning of the file upto end will help to get file size
    file.seekg(0, ios::end); // move to the end of file
    fcb.size = static_cast<size_t>(file.tellg());
    file.seekg(0, ios::beg); // move to the beg of file

    fcb.content.resize(fcb.size);

    content.assign((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());

    fcb.filename = filename;

    file.close();

    return true;
}

void displayStatus(const FileControlBlock &fcb)
{
    cout << "File Status: ";

    if (fcb.status == FileStatus::Closed)
    {
        cout << "Closed" << endl;
    }
    else if (fcb.status == FileStatus::Open)
    {
        cout << "Open" << endl;
    }
    else if (fcb.status == FileStatus::ReadOnly)
    {
        cout << "Read-Only" << endl;
    }
    else if (fcb.status == FileStatus::ReadWrite)
    {
        cout << "Read-Write" << endl;
    }
    else
    {
        cout << "Unknown" << endl;
    }
}

void displaytype(const FileControlBlock &fcb, struct stat fileInfo)
{
    if (stat(fcb.filename.c_str(), &fileInfo) != 0)
        cerr << "Unable to detect file type " << endl;
    cout << "File Type: ";

    if ((fileInfo.st_mode & S_IFMT) == __S_IFDIR)
        cout << "Directory" << endl;

    else
        cout << "Regular" << endl;
}

void displayPermission(const FileControlBlock &fcb, struct stat fileInfo)
{
    if (stat(fcb.filename.c_str(), &fileInfo) != 0)
        cerr << "Unable to detect file type " << endl;
    cout << "File Permissions: ";
    mode_t permissions = fileInfo.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO);
    if (permissions & S_IRUSR)
    {
        cout << "Owner Read ";
    }
    if (permissions & S_IWUSR)
    {
        cout << "Owner Write ";
    }
    if (permissions & S_IXUSR)
    {
        cout << "Owner Execute ";
    }
    if (permissions & S_IRGRP)
    {
        cout << "Group Read ";
    }
    if (permissions & S_IWGRP)
    {
        cout << "Group Write ";
    }
    if (permissions & S_IXGRP)
    {
        cout << "Group Execute ";
    }
    if (permissions & S_IROTH)
    {
        cout << "Others Read ";
    }
    if (permissions & S_IWOTH)
    {
        cout << "Others Write ";
    }
    if (permissions & S_IXOTH)
    {
        cout << "Others Execute ";
    }

    std::cout << std::endl;
}
void displayFileInformation(const FileControlBlock &fcb)
{
    cout << "File Name: " << fcb.filename << endl;
    cout << "File Size: " << fcb.size << " bytes" << endl;
    //cout<<"File contents: \n"<<content<<endl;
    cout<<"generated Hash: "<<SHA512(content)<<endl;
    displayStatus(fcb);
}