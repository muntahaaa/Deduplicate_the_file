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
//undone function
void similarityChecking(vector<string> directoryItems, FileControlBlock &fcb, vector<string> &names)
{
    vector<char> charVector1;
    vector<char> charVector2;
    for (size_t i = 0; i < directoryItems.size()-1; i++)
    {
        
            string filename1 = directoryNames[i];
            string path1 = directoryItems[i];
            //loadFile(path1, fcb, filename1);
            readCharactersFromFile(path1, charVector1);
            string filename2 = directoryNames[i+1];
            string path2 = directoryItems[i+1];
            //loadFile(path2, fcb, filename2);
            readCharactersFromFile(path2, charVector2);

            cout<<"path1 "<<path1;
            cout<<" file1"<<filename1<<endl;

            displayVector(charVector1, "File 1");
            displayVector(charVector2, "File 2");

            // Create and display the union vector
            vector<char> unionVector;
            unionVectors(charVector1, charVector2, unionVector);
            cout << endl;
            //displayVector(unionVector, "Union");

            // Create and display the intersection vector
            vector<char> intersectionVector;
            intersectionVectors(charVector1, charVector2, intersectionVector);
            cout << endl;
            //displayVector(intersectionVector, "Intersection");

            printNotMatchedCharacters(charVector1, intersectionVector);
            cout << endl;

            double jaccardSimilarity = static_cast<double>(intersectionVector.size()) / unionVector.size();
            //cout << "Jaccard similarity: " << jaccardSimilarity * 100 << "%" << endl;
        
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
                const char *directoryPath = "/home/muntaha/Desktop/SPL-new/dummy";

                const char *fileName = files[i].first.c_str();

                // Construct the full path to the file
                char fullPath[256]; // Adjust the size accordingly
                snprintf(fullPath, sizeof(fullPath), "%s/%s", directoryPath, fileName);

                int result = remove(fullPath);

                if (result == 0)
                {

                    cout << "duplicate file " << fileNametoDelete << " has been deleted";
                }
                else
                    cout << "Error in deleting"; // need to use file name instead of file path

               
            }
        }
    }

    if (!similarityFound)
    {
        cout << "No similarity found" << endl;
    }

    /*void printSimilarity(FileControlBlock &fcb, vector<string> directoryItems){
         for (size_t i = 0; i < directoryItems.size()-1; i++){
            string filePath1 = directoryItems[i];
            fname1 = directoryNames[i];
            loadFile(filePath1, fcb, fname1);
            string name1=fcb.name;

            string filePath2 = directoryItems[i+1];
            fname2=directoryNames[i+1];
            loadFile(filePath2, fcb, fname2);
            string name2=fcb.name;

            const char *directoryPath = "/home/muntaha/Desktop/SPL-new/dummy";
            const char *fileName = fcb.name.c_str();

                    // Construct the full path to the file
                    char fullPath[256]; // Adjust the size accordingly
                    snprintf(fullPath, sizeof(fullPath), "%s/%s", directoryPath, fileName);

         }
    }  */
}
