#include <vector>
#include <string>
#include <unordered_map>
#include <unistd.h>
using namespace std;

enum class FileStatus
{
    Open,
    Closed,
    ReadOnly,
    ReadWrite,
    Unknown
};

enum class FileType
{
    Regular,
    Directory
};
enum class PermissionType
{
    Read,
    Write,
    Execute
};

enum class PermissionScope
{
    Owner,
    Group,
    Others
};

enum class CombinedPermission
{
    OwnerRead = static_cast<int>(PermissionType::Read) << 2 | static_cast<int>(PermissionScope::Owner),
    OwnerWrite = static_cast<int>(PermissionType::Write) << 2 | static_cast<int>(PermissionScope::Owner),
    OwnerExecute = static_cast<int>(PermissionType::Execute) << 2 | static_cast<int>(PermissionScope::Owner),
    GroupRead = static_cast<int>(PermissionType::Read) << 2 | static_cast<int>(PermissionScope::Group),
    GroupWrite = static_cast<int>(PermissionType::Write) << 2 | static_cast<int>(PermissionScope::Group),
    GroupExecute = static_cast<int>(PermissionType::Execute) << 2 | static_cast<int>(PermissionScope::Group),
    OthersRead = static_cast<int>(PermissionType::Read) << 2 | static_cast<int>(PermissionScope::Others),
    OthersWrite = static_cast<int>(PermissionType::Write) << 2 | static_cast<int>(PermissionScope::Others),
    OthersExecute = static_cast<int>(PermissionType::Execute) << 2 | static_cast<int>(PermissionScope::Others)
};

string content;
struct FileControlBlock
{
    string filename;
    vector<string> content;
    string hash;
    size_t size;
    FileType type;
    CombinedPermission permissions;
    FileStatus status;
};

bool loadFile(const string &filename, FileControlBlock &fcb);
FileStatus displayStatus(const FileControlBlock &fcb);
FileType displaytype(const FileControlBlock &fcb, struct stat fileInfo);
vector<CombinedPermission> displayPermission(const FileControlBlock &fcb, struct stat fileInfo);
void displayFileInformation(const FileControlBlock &fcb);
