#include<vector>
#include<string>
using namespace std;

enum class FileStatus{
    Open,
    Closed,
    ReadOnly,
    ReadWrite
};
/*
enum class FileType{
    Regular,
    Directory
};
struct FilePermissions {
    bool read;
    bool write;
    bool execute;
    
};
struct LockStatus {
    bool locked;
    
};
*/
string content;
struct FileControlBlock
{
    string filename;
    vector<string> content;
    size_t size;
    /*FileType type;
    FilePermissions permissions;
   
    LockStatus lock_status;*/
     FileStatus status;
};

bool loadFile(const string &filename, FileControlBlock &fcb);
void displayStatus(const FileControlBlock &fcb);
void displaytype(const FileControlBlock &fcb,struct stat fileInfo);
void displayPermission(const FileControlBlock &fcb,struct stat fileInfo);
void displayFileInformation(const FileControlBlock &fcb);
