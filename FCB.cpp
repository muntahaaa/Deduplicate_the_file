#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sstream>
#include <set>
#include "FCB.h"
#include "Hash.cpp"

#define ANSI_RESET "\033[0m"
#define ANSI_BOLD "\033[1m"
#define ANSI_ITALIC "\033[3m"

FileControlBlock fcb;
struct stat fileInfo;
string concatenedPermission;
using namespace std;
ostringstream oss;

bool loadFile(const string &filename, FileControlBlock &fcb, const string files)
{
    string Hashvalue;
    ifstream file(filename, ios::binary);
    if (!file.is_open())
    {
        cerr << "Error: Unable to open file '" << filename << "'" << endl;
        return false;
    }
    else
    {
    }

    file.seekg(0, ios::end);
    fcb.size = static_cast<size_t>(file.tellg());
    file.seekg(0, ios::beg);

    fcb.content.resize(fcb.size);

    content.assign((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());

    Hashvalue = SHA512(content);
    fcb.hash = Hashvalue;

    fcb.filename = filename;
    fcb.name = files;

    FileStatus fs = displayStatus(fcb);

    file.close();

    return true;
}

FileStatus displayStatus(const FileControlBlock &fcb)
{

    string status;

    if (fcb.status == FileStatus::Closed)
    {

        status = "Closed";
    }
    else if (fcb.status == FileStatus::Open)
    {

        status = "Open";
    }
    else if (fcb.status == FileStatus::ReadOnly)
    {

        status = "Read-Only";
    }
    else if (fcb.status == FileStatus::ReadWrite)
    {

        status = "Read-Write";
    }
    else
    {

        status = "Unknown";
    }
    return fcb.status;
}
string fileStatusToString(FileStatus status)
{
    switch (status)
    {
    case FileStatus::Closed:
        return "Closed";
    case FileStatus::Open:
        return "Open";
    case FileStatus::ReadOnly:
        return "Read-Only";
    case FileStatus::ReadWrite:
        return "Read-Write";
    default:
        return "Unknown";
    }
}

FileType displaytype(const FileControlBlock &fcb, struct stat fileInfo)
{
    if (stat(fcb.filename.c_str(), &fileInfo) != 0)
        cerr << "Unable to detect file type " << endl;

    cout << "File Type: ";

    if ((fileInfo.st_mode & S_IFMT) == __S_IFDIR)
        cout << "Directory" << endl;

    else
        cout << "Regular" << endl;

    return fcb.type;
}
string fileTypeToString(FileType type)
{
    switch (type)
    {
    case FileType::Directory:
        return "Directory";
    case FileType::Regular:
        return "Regular";
    default:
        return "Unknown";
    }
}

vector<CombinedPermission> displayPermission(const FileControlBlock &fcb, struct stat fileInfo)
{
    vector<CombinedPermission> permissionsVector;
    if (stat(fcb.filename.c_str(), &fileInfo) != 0)
        cerr << "Unable to detect file type " << endl;

    mode_t permissions = fileInfo.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO);
    if (permissions & S_IRUSR)
    {

        permissionsVector.push_back(CombinedPermission::OwnerRead);
    }
    if (permissions & S_IWUSR)
    {

        permissionsVector.push_back(CombinedPermission::OwnerWrite);
    }
    if (permissions & S_IXUSR)
    {

        permissionsVector.push_back(CombinedPermission::OwnerExecute);
    }
    if (permissions & S_IRGRP)
    {

        permissionsVector.push_back(CombinedPermission::GroupRead);
    }
    if (permissions & S_IWGRP)
    {

        permissionsVector.push_back(CombinedPermission::GroupWrite);
    }
    if (permissions & S_IXGRP)
    {

        permissionsVector.push_back(CombinedPermission::GroupExecute);
    }
    if (permissions & S_IROTH)
    {

        permissionsVector.push_back(CombinedPermission::OthersRead);
    }
    if (permissions & S_IWOTH)
    {

        permissionsVector.push_back(CombinedPermission::OthersWrite);
    }
    if (permissions & S_IXOTH)
    {

        permissionsVector.push_back(CombinedPermission::OthersExecute);
    }

    return permissionsVector;
}
string combinedPermissionToString(CombinedPermission permission)
{
    switch (permission)
    {
    case CombinedPermission::OwnerRead:
        return "OwnerRead";
    case CombinedPermission::OwnerWrite:
        return "OwnerWrite";
    case CombinedPermission::OwnerExecute:
        return "OwnerExecute";
    case CombinedPermission::GroupRead:
        return "GroupRead";
    case CombinedPermission::GroupWrite:
        return "GroupWrite";
    case CombinedPermission::GroupExecute:
        return "GroupExecute";
    case CombinedPermission::OthersRead:
        return "OthersRead";
    case CombinedPermission::OthersWrite:
        return "OthersWrite";
    case CombinedPermission::OthersExecute:
        return "OthersExecute";
    default:
        return "Unknown";
    }
}

void displayFileInformation(const FileControlBlock &fcb)
{
    set<string> uniquePermissions;
    struct stat fileInfo;
    string permit;

    cout << ANSI_BOLD << "File Name: " << ANSI_RESET
         << ANSI_ITALIC << fcb.name
         << ANSI_RESET << endl;

    cout << ANSI_BOLD << "File Size: " << ANSI_RESET
         << ANSI_ITALIC << fcb.size << " bytes"
         << ANSI_RESET << endl;

    cout << ANSI_BOLD << "Hash Value: " << ANSI_RESET
         << ANSI_ITALIC << fcb.hash
         << ANSI_RESET << endl;

    cout << ANSI_BOLD << "File status: " << ANSI_RESET
         << ANSI_ITALIC << fileStatusToString(fcb.status)
         << ANSI_RESET << endl;

    cout << ANSI_BOLD << "File Type: " << ANSI_RESET
         << ANSI_ITALIC << fileTypeToString(fcb.type)
         << ANSI_RESET << endl;

    vector<CombinedPermission> permissionsVector = displayPermission(fcb, fileInfo);

    cout << ANSI_BOLD << "File Permissions: "
         << ANSI_RESET << endl;

    for (const CombinedPermission &permission : permissionsVector)
    {
        cout << ANSI_ITALIC << combinedPermissionToString(permission) << " "
             << ANSI_RESET << endl;
    }

    for (const CombinedPermission &permission : permissionsVector)
    {

        permit = combinedPermissionToString(permission) + " ";
        uniquePermissions.insert(permit);
    }

    stringstream ss;
    for (const string &uniquePermission : uniquePermissions)
    {
        ss << uniquePermission << " ";
    }
    concatenedPermission = ss.str();

    cout << ANSI_BOLD << "File contents: \n"
         << ANSI_RESET
         << content << endl;

    cout << endl;
}

string returnPermission(const FileControlBlock &fcb)
{
    return concatenedPermission;
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
    cout << "data represented in Int format:\n";
    while (inputFile.read(&readData, sizeof(readData)))
    {
        cout << static_cast<int>(readData) << " ";
        flag = true;
    }
    if (flag)
        cout << "\nFile " << fileName 
        << " read successfully." << endl;
}