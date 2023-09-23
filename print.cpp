#include <iostream>
#include <vector>
#include <string>
// #include "read_file.cpp"
//#include "FCB.h"
#include "FCB.cpp"
using namespace std;
vector<string> directoryNames;
string files;

void printProperties()
{   

    cout<<"File properties are: "<<endl;
    for (const string &itemPath : directoryNames)
    {
        
        
        files = itemPath;
       
        if (loadFile(files, fcb))
    {
        displayFileInformation(fcb);
        displaytype(fcb, fileInfo);
        displayPermission(fcb, fileInfo);
        cout<< endl;
    }
        
    }  

   
}
