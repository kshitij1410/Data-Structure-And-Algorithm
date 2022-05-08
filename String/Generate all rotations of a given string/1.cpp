#include <bits/stdc++.h>
using namespace std;

/*
Q1
Given a string S. The task is to print all the possible rotated strings of the given string.

Examples: 

Input : S = "geeks"
Output : geeks
         eeksg
         eksge
         ksgee
         sgeek

Input : S = "abc" 
Output : abc
         bca
         cab
         
         
*/

void printRotatedString(string str)
{
    int n=str.size();
    string s=str+str;

    for(int i=0;i<n;i++)
    {
        string temp=s.substr(i,n);
        cout<<temp<<endl;
    }

}




int main()
{
    char str[] = "geeks";
    printRotatedString(str);
    return 0;
}
