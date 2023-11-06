#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include<algorithm>
#include <iterator>
// Function to calculate the Jaccard similarity between two text files
double calculateJaccardSimilarity(const std::string& file1Path, const std::string& file2Path) {
    // Read and preprocess the text from the two files
    std::set<std::string> text1;
    std::set<std::string> text2;

    // Read and preprocess text from the first file
    std::ifstream file1(file1Path);
    if (file1.is_open()) {
        std::string word;
        while (file1 >> word) {
            // Convert to lowercase and add to the set
            std::transform(word.begin(), word.end(), word.begin(), ::tolower);
            text1.insert(word);
        }
        file1.close();
    } else {
        std::cerr << "Error opening file: " << file1Path << std::endl;
        return 0.0;
    }

    // Read and preprocess text from the second file
    std::ifstream file2(file2Path);
    if (file2.is_open()) {
        std::string word;
        while (file2 >> word) {
            // Convert to lowercase and add to the set
            std::transform(word.begin(), word.end(), word.begin(), ::tolower);
            text2.insert(word);
        }
        file2.close();
    } else {
        std::cerr << "Error opening file: " << file2Path << std::endl;
        return 0.0;
    }

    // Calculate Jaccard similarity
    std::set<std::string> intersection;
    std::set_intersection(text1.begin(), text1.end(), text2.begin(), text2.end(),
                          std::inserter(intersection, intersection.begin()));

    std::set<std::string> unionSet;
    std::set_union(text1.begin(), text1.end(), text2.begin(), text2.end(),
                   std::inserter(unionSet, unionSet.begin()));

    double jaccardSimilarity = static_cast<double>(intersection.size()) / unionSet.size();

    return jaccardSimilarity;
}

int main() {
    std::string file1Path ="/home/muntaha/Desktop/SPL-01/FCB.cpp";  // Replace with the path to your first text file
    std::string file2Path = "/home/muntaha/Desktop/SPL-01/FCB.h";  // Replace with the path to your second text file

    double jaccardSimilarity = calculateJaccardSimilarity(file1Path, file2Path);

    std::cout << "Jaccard Similarity: " << jaccardSimilarity*100<<"% " << std::endl;

    return 0;
}
