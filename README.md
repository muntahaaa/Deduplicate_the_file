# SPL-01
read_file.cpp includes print.cpp and print.cpp includes FCB.cpp

eventually read_file.cpp has main function and running it will be able to run all the three cpp files.

void displayFileInformation(const FileControlBlock &fcb) function of FCB.cpp contains contents of each file

FCB.cpp includes Hash.cpp and void displayFileInformation(const FileControlBlock &fcb) function of FCB.cpp can generate Hash value for every file

duplicate files have same hash value

print.cpp contains check equality function which can identify similar files using hash value
jaccard similarity can measure % of similarity between 2 string contents 
