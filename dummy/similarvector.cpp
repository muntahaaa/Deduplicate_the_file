#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

// Function to read words from a file and store them in a vector
void readWordsFromFile(const string& filename, vector<string>& wordVector) {
    ifstream file(filename);
    
    if (file.is_open()) {
        string word;
        while (file >> word) {
            wordVector.push_back(word);
        }
        file.close();
    } else {
        cerr << "Error opening file: " << filename << endl;
    }
}

// Function to display the contents of a vector
void displayVector(const vector<string>& wordVector, const string& vectorName) {
    cout << vectorName << ": ";
    for (const string& word : wordVector) {
        cout << word << " ";
    }
    cout << endl;
}

// Function to perform union of two vectors
void unionVectors(const vector<string>& vec1, const vector<string>& vec2, vector<string>& result) {
    unordered_set<string> resultSet(vec1.begin(), vec1.end());

    for (const string& word : vec2) {
        resultSet.insert(word);
    }

    result.assign(resultSet.begin(), resultSet.end());
}

// Function to perform intersection of two vectors
void intersectionVectors(const vector<string>& vec1, const vector<string>& vec2, vector<string>& result) {
    unordered_set<string> set1(vec1.begin(), vec1.end());
    unordered_set<string> set2(vec2.begin(), vec2.end());

    for (const string& word : set1) {
        // Compare words in a case-insensitive manner
        string lowercaseWord = word;
        transform(lowercaseWord.begin(), lowercaseWord.end(), lowercaseWord.begin(), ::tolower);

        if (set2.count(lowercaseWord) > 0) {
            result.push_back(word);
        }
    }
}

int main() {
    // Specify the paths to the text files
    string filename1 = "text.txt";
    string filename2 = "text2.txt";

    // Read words from both files and store them in vectors
    vector<string> wordVector1;
    vector<string> wordVector2;

    readWordsFromFile(filename1, wordVector1);
    readWordsFromFile(filename2, wordVector2);

    // Display the contents of both vectors
    displayVector(wordVector1, "File 1");
    displayVector(wordVector2, "File 2");

    // Create and display the union vector
    vector<string> unionVector;
    unionVectors(wordVector1, wordVector2, unionVector);
    cout << endl;
    displayVector(unionVector, "Union");

    // Create and display the intersection vector
    vector<string> intersectionVector;
    intersectionVectors(wordVector1, wordVector2, intersectionVector);
    cout << endl;
    displayVector(intersectionVector, "Intersection");

    double jaccardSimilarity = static_cast<double>(intersectionVector.size()) / unionVector.size();
    cout << "Jaccard similarity: " << jaccardSimilarity * 100 << "%" << endl;

    return 0;
}
