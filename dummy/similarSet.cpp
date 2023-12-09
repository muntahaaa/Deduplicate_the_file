#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
using namespace std;

// Function to read characters from a file and store them in a set
void readCharactersFromFile(const string& filename, set<char>& charSet) {
    ifstream file(filename);
    
    if (file.is_open()) {
        char c;
        while (file.get(c)) {
            charSet.insert(c);
        }
        file.close();
    } else {
        cerr << "Error opening file: " << filename << endl;
    }
}

// Function to display the contents of a set
void displaySet(const set<char>& charSet, const string& setName) {
    cout << setName << ": ";
    for (const char& c : charSet) {
        cout << c;
    }
    cout << endl;
}

// Function to perform union of two sets
void unionSets(const set<char>& set1, const set<char>& set2, set<char>& result) {
    result = set1;
    result.insert(set2.begin(), set2.end());
}

// Function to perform intersection of two sets
void intersectionSets(const set<char>& set1, const set<char>& set2, set<char>& result) {
    for (const char& c : set1) {
        if (set2.count(c) > 0) {
            result.insert(c);
        }
    }
}

int main() {
    // Specify the paths to the text files
    string filename1 = "text.txt";
    string filename2 = "text2.txt";

    // Read characters from both files and store them in sets
    set<char> charSet1;
    set<char> charSet2;

    readCharactersFromFile(filename1, charSet1);
    readCharactersFromFile(filename2, charSet2);

    // Display the contents of both sets
    displaySet(charSet1, "File 1");
    displaySet(charSet2, "File 2");

    // Create and display the union set
    set<char> unionSet;
    unionSets(charSet1, charSet2, unionSet);
    cout << endl;
    displaySet(unionSet, "Union");

    // Create and display the intersection set
    set<char> intersectionSet;
    intersectionSets(charSet1, charSet2, intersectionSet);
    cout << endl;
    displaySet(intersectionSet, "Intersection");

    return 0;
}
