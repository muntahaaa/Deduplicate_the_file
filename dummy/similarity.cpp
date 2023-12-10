#include <iostream>
#include <fstream>
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

    return 0;
}
