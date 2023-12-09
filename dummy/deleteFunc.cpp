#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    char filename[]="hi.txt";
    int result=remove(filename);
    if(result==0)
    cout<<"deleted";
    else cout<<"did not";
}