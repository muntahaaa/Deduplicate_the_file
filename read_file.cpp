#include <iostream>
#include <fstream> // Required for file stream operations

int main() {
    std::ifstream inputFile("SPL1 Project Proposal Final 1450.pdf"); // Replace with your file's name

    if (!inputFile.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::cout << line << std::endl;
    }

    inputFile.close();

    return 0;
}
