#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    char filename[]="hi.txt";
    int result=remove(filename);
    cout<<result;
}