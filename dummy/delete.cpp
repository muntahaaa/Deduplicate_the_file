#include <iostream>
#include <cstdio>

int main() {
    const char* directoryPath = "/home/muntaha/Desktop/SPL-new/dummy";
    const char* fileName = "hi.txt";

    // Construct the full path to the file
    char fullPath[256]; // Adjust the size accordingly
    snprintf(fullPath, sizeof(fullPath), "%s/%s", directoryPath, fileName);

    // Use remove to delete the file
    int result = remove(fullPath);

    if (result == 0) {
        std::cout << "File deleted successfully." << std::endl;
    } else {
        perror("Error deleting file");
    }

    return 0;
}
