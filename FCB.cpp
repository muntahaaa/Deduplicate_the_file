#include <iostream>
#include <fstream>
#include <vector>

struct FileControlBlock {
    std::string filename;
    std::vector<char> content;
    std::size_t size;
};

bool loadFile(const std::string& filename, FileControlBlock& fcb) {
    std::ifstream file(filename, std::ios::binary);
    
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file '" << filename << "'" << std::endl;
        return false;
    }

    file.seekg(0, std::ios::end);
    fcb.size = static_cast<std::size_t>(file.tellg());
    file.seekg(0, std::ios::beg);

    fcb.content.resize(fcb.size);
    file.read(fcb.content.data(), fcb.size);

    fcb.filename = filename;

    file.close();

    return true;
}

void displayFileInformation(const FileControlBlock& fcb) {
    std::cout << "File Name: " << fcb.filename << std::endl;
    std::cout << "File Size: " << fcb.size << " bytes" << std::endl;
}

int main() {
    FileControlBlock fcb;

    // Replace 'example.txt' with the path to your file
    if (loadFile("searched websites (copy).txt", fcb)) {
        displayFileInformation(fcb);
    }

    return 0;
}
