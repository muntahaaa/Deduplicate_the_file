#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include "FCB.cpp"
#include "JaccardSimilarity.cpp"
using namespace std;
vector<string> directoryNames;
string files, nameOfFile;

vector<char> charVector1;
vector<char> charVector2;

vector<char> convertToChar(vector<string> contents)
{
    vector<char> charVector;

    for (const string &str : contents)
    {
        charVector.insert(charVector.end(), str.begin(), str.end());
    }
    return charVector;
}
void printProperties(vector<string> directoryItems, vector<string> &names)
{
    int count = 0;
    cout << "File properties are: " << endl;
    for (const string &itemPath : directoryItems)
    {

        files = itemPath;
        nameOfFile = names[count++];

        if (loadFile(files, fcb, nameOfFile))
        {
            displayFileInformation(fcb);

            cout << endl;
        }
    }
}

void similarityChecking(vector<string> directoryItems, FileControlBlock &fcb, vector<string> &names)
{

    for (size_t i = 0; i < directoryItems.size() - 1; i++)
    {

        string filename1 = directoryNames[i];
        string path1 = directoryItems[i];
        loadFile(path1, fcb, filename1);

        vector<char> charVector1(content.begin(), content.end());
        cout << "fcb.content1: " << content << endl;

        string filename2 = directoryNames[i + 1];
        string path2 = directoryItems[i + 1];
        loadFile(path2, fcb, filename2);

        vector<char> charVector2(content.begin(), content.end());
        cout << "fcb.content2: " << content << endl;

        cout << "path1 " << path1 << endl;
        cout << "file1 " << filename1 << endl;

        displayVector(charVector1, "File 1");
        displayVector(charVector2, "File 2");

        vector<char> unionVector;
        unionVectors(charVector1, charVector2, unionVector);

        vector<char> intersectionVector;
        intersectionVectors(charVector1, charVector2, intersectionVector);

        printNotMatchedCharacters(charVector1, intersectionVector);

        double jaccardSimilarity = static_cast<double>(intersectionVector.size()) / unionVector.size();
        cout << "\nJaccard similarity: " << jaccardSimilarity * 100 << "%" << endl
             << endl;
    }
}

void checkEquality(vector<string> directoryItems, FileControlBlock &fcb, vector<string> &names)
{

    vector<pair<string, string>> files;
    string filePath, fname;

    for (size_t i = 0; i < directoryItems.size(); i++)
    {
        filePath = directoryItems[i];
        fname = directoryNames[i];
        loadFile(filePath, fcb, fname);

        files.push_back(make_pair(fcb.name, fcb.hash));
    }

    bool similarityFound = false;
    string fileNametoDelete;

    for (size_t i = 0; i < directoryItems.size(); i++)
    {
        for (size_t j = i + 1; j < directoryItems.size(); j++)
        {
            if (files[i].second == files[j].second)
            {
                similarityFound = true;
                cout << "similarity found in ";
                cout << files[i].first << " and " << files[j].first << endl;
                fileNametoDelete = files[i].first;
                const char *directoryPath = "/home/muntaha/Desktop/SPL-new/dummy2";

                const char *fileName = files[i].first.c_str();
                char fullPath[256];
                snprintf(fullPath, sizeof(fullPath), "%s/%s", directoryPath, fileName);

                int result = remove(fullPath);

                if (result == 0)
                {

                    cout << "duplicate file " << fileNametoDelete << " has been deleted";
                }
                else
                    cout << "Error in deleting";
            }
        }
    }

    if (!similarityFound)
    {
        cout << "No similarity found" << endl;
    }
}
