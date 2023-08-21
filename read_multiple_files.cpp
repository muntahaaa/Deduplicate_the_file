#include <iostream>
#include<string>
#include <fstream> // Required for file stream operations
#include<filesystem>
using namespace std;
using namespace filesystem;

void read_file(string fileName){
   
    ifstream inputFile(fileName); // Replace with file's name, ifstream for input function

    if (!inputFile.is_open()) {
       cerr << "Failed to open the file." << endl;
       
    }
    //to read data and represent it in Int form
    char readData;
    bool flag=false;
    while (inputFile.read(&readData, sizeof(readData))) {  //sizeof(readData)=1
        //cout << static_cast<int>(readData) << " ";
        //cout<<byte<<" ";
        flag=true;
    }
    if(flag) 
    cout << "File " << fileName << " read successfully." << endl;

    inputFile.close();
}

int main() {
    string directoryPath = "/home/muntaha/Desktop/SPL-01"; // Current directory
//using const will prevent the entry variable to modify any content of the file
//directory_iterator class will iterate through directory     
    for (const auto &entry : directory_iterator(directoryPath)) {
        if (is_regular_file(entry)) {
            read_file(entry.path().string());
        }
    }

}
