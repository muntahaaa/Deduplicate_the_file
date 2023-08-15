#include <iostream>
#include<string>
#include <fstream> // Required for file stream operations
#include<filesystem>
using namespace std;
using namespace filesystem;

void read_file(string fileName){
   
    ifstream inputFile(fileName); // Replace with file's name

    if (!inputFile.is_open()) {
       cerr << "Failed to open the file." << endl;
       
    }
    char byte;
    bool flag=false;
    while (inputFile.read(&byte, sizeof(byte))) {
        //std::cout << static_cast<int>(byte) << " ";
        flag=true;
    }
    if(flag) 
    cout << "File " << fileName << " read successfully." << endl;

    inputFile.close();
}

int main() {
    string directoryPath = "/home/muntaha/Desktop/SPL-01"; // Current directory
    for (const auto &entry : directory_iterator(directoryPath)) {
        if (is_regular_file(entry)) {
            read_file(entry.path().string());
        }
    }

}
