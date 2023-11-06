#include <iostream>
#include <vector>
#include <string>

// #include "read_file.cpp"
// #include "FCB.h"
#include "FCB.cpp"
using namespace std;
vector<string> directoryNames;
string files;

void printProperties(vector<string> directoryItems)
{

    cout << "File properties are: " << endl;
    for (const string &itemPath : directoryItems)
    {

        files = itemPath;

        if (loadFile(files, fcb))
        {
            displayFileInformation(fcb);

            cout << endl;
        }
    }
}
//undone!!!
void checkEquality(vector<string> directoryItems,FileControlBlock &fcb){
    // vector<string>file1;
    // vector<string>file2;
    vector<pair<string, string>> files;
    string filePath;
    
    for(size_t i=0;i<directoryItems.size();i++){
        filePath=directoryItems[i];
            loadFile(filePath,fcb);
           
            files.push_back(make_pair(fcb.filename, fcb.hash));
            
        
    }

    bool similarityFound = false;
    string fileNametoDelete;

    for(size_t i=0;i<directoryItems.size();i++){
        for(size_t j=i+1;j<directoryItems.size();j++){
            if(files[i].second==files[j].second){
                similarityFound = true;
                cout<<"similarity found"<<endl;
               cout << files[i].first << " and " << files[j].first << endl;
               fileNametoDelete=files[i].first;
               int result=remove("fileNametoDelete");
               
               
               if(result==0){
                 cout << files[i].first << " and " << endl<<files[j].first <<" has been deleted"<<endl;
               }
               else cout<<"Error in deleting";  //need to use file name instead of file path

               
    
            }
            
        }
    }

    if (!similarityFound) {
        cout << "No similarity found" << endl;
    }
    
}
