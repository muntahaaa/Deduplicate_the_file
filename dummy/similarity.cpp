#include <iostream>
#include <fstream>
<<<<<<< HEAD
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;


void readCharactersFromFile(const string& filename, vector<char>& charVector) {
    ifstream file(filename);

    if (file.is_open()) {
        char c;
        while (file.get(c)) {
            charVector.push_back(c);
        }
        file.close();
    } else {
        cerr << "Error opening file: " << filename << endl;
    }
}


void displayVector(const vector<char>& charVector, const string& vectorName) {
    cout << vectorName << ": ";
    for (const char& c : charVector) {
        cout << c;
    }
    cout << endl;
}


void unionVectors(const vector<char>& vec1, const vector<char>& vec2, vector<char>& result) {
    unordered_set<char> resultSet(vec1.begin(), vec1.end());

    for (const char& c : vec2) {
        resultSet.insert(c);
    }

    result.assign(resultSet.begin(), resultSet.end());
}


void intersectionVectors(const vector<char>& vec1, const vector<char>& vec2, vector<char>& result) {
    unordered_set<char> set1(vec1.begin(), vec1.end());
    unordered_set<char> set2(vec2.begin(), vec2.end());

    for (const char& c : set1) {
        if (set2.count(c) > 0) {
            result.push_back(c);
        }
    }
}

void printNotMatchedCharacters(const vector<char>& vec1, const vector<char>& vec2) {
    unordered_set<char> set1(vec1.begin(), vec1.end());
    unordered_set<char> set2(vec2.begin(), vec2.end());

    cout << "Unmatched characters: ";
    for (const char& c : set1) {
        if (set2.count(c) <= 0) {
            cout << c;
        }
    }
}

int main() {
   
    string filename1 = "text.txt";
    string filename2 = "text2.txt";

   
    vector<char> charVector1;
    vector<char> charVector2;

    readCharactersFromFile(filename1, charVector1);
    readCharactersFromFile(filename2, charVector2);

    
    displayVector(charVector1, "File 1");
    displayVector(charVector2, "File 2");

   
    vector<char> unionVector;
    unionVectors(charVector1, charVector2, unionVector);
    cout << endl;
    displayVector(unionVector, "Union");

   
    vector<char> intersectionVector;
    intersectionVectors(charVector1, charVector2, intersectionVector);
    cout << endl;
    displayVector(intersectionVector, "Intersection");

    printNotMatchedCharacters(charVector1, intersectionVector);
    cout << endl;

    double jaccardSimilarity = static_cast<double>(intersectionVector.size()) / unionVector.size();
    cout << "Jaccard similarity: " << jaccardSimilarity * 100 << "%" << endl;
=======
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
    std::string file1Path = "text_file1.txt";  // Replace with the path to your first text file
    std::string file2Path = "text_file2.txt";  // Replace with the path to your second text file

    double jaccardSimilarity = calculateJaccardSimilarity(file1Path, file2Path);

    std::cout << "Jaccard Similarity: " << jaccardSimilarity << std::endl;
>>>>>>> 7cb80e9cf977b2d04aef368cb23f8878338f1754

    return 0;
}
