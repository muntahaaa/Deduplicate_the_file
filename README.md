# SPL-01
**PROJECT DESCRIPTION**
>>This project takes directory path as input and accesses all the files of that directory and prints metadata of all the files. If any 2 files are found duplicate (meta data are same) then any one of them will be deleted. Simulataneously it will also print text similarity between 2 files for all the files of that directory and will express it through a matrix <<

read_file.cpp contains main funtion. To the main function, we need to provide abs path of directory to access all the files in between it. 
FCB.cpp calculates all meta Data (gets hash value using Hash.cpp)
print.cpp firstly prints all the meta data, then using JaccardSimilarity.cpp it it gets (nxn) similarity matrix and prints it. 
Then it checks if all the attributes (contents, hash, type, status, permission, extension) are same or not. If same then 1 one will be kept and the other will be deleted. 
