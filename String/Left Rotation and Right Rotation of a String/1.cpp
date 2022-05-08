#include <bits/stdc++.h>
using namespace std;

/*
Q1
Given a string of size n, write functions to perform the following operations on a string-

Left (Or anticlockwise) rotate the given string by d elements (where d <= n)
Right (Or clockwise) rotate the given string by d elements (where d <= n).
Examples: 

Input : s = "GeeksforGeeks"
        d = 2
Output : Left Rotation  : "eksforGeeksGe" 
         Right Rotation : "ksGeeksforGee"  


Input : s = "qwertyu" 
        d = 2
Output : Left rotation : "ertyuqw"
         Right rotation : "yuqwert"
         
*/

void leftrotate(string &str, int d)
{
    int n=str.size();
    string ans="";

    for(int i=0;i<n;i++)
    {
        int index=(i+d)%n;
       ans+=str[index];
    }
     str=ans;
}

void rightrotate(string &str, int d)
{
    int n=str.size();
    string ans="";

    for(int i=0;i<n;i++)
    {
        int index=(n-d+i)%n;
       ans+=str[index];
    }
   
   str=ans;

}


int main()
{
    string str1 = "Geeks";
    leftrotate(str1, 2);
    cout << str1 << endl;
    string str2 = "Geeks";
    rightrotate(str2, 2);
    cout << str2 << endl;
    return 0;
}
