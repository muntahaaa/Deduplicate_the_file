# SPL-01

read_file.cpp contains main funtion. To the main function, we need to provide abs path of directory to access all the files in between it. 
FCB.cpp calculates all meta Data (gets hash value using Hash.cpp)
print.cpp firstly prints all the meta data, then using JaccardSimilarity.cpp it it gets (nxn) similarity matrix and prints it. 
Then it checks if all the attributes (contents, hash, type, status, permission, extension) are same or not. If same then 1 one will be kept and the other will be deleted. 
