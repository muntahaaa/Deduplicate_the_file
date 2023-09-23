#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<string.h>
using namespace std;

int main() {
    const char* filename = "readonly.txt";

    // Create or open the file
    int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0664); // 0664 sets read and write permissions for owner, read-only for group and others

    if (fd == -1) {
        cerr << "Error: Unable to create/open the file." << endl;
        return 1;
    }

    // Write some content to the file (optional)
    const char* content = "This is a read-only file.";
    write(fd, content, strlen(content));

    // Close the file
    close(fd);

    // Change the file permissions to make it read-only
    if (chmod(filename, S_IRUSR | S_IRGRP | S_IROTH) == -1) {
        cerr << "Error: Unable to change file permissions." << endl;
        return 1;
    }

    cout << "Read-only file created: " << filename << endl;

    return 0;
}
