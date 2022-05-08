#include <bits/stdc++.h>
using namespace std;

/*
Q1
Given a number n, the task is to find the remainder when n is divided by 11. The input of number may be very large.
Examples:

Input : str = 13589234356546756
Output : 6

Input : str = 3435346456547566345436457867978
Output : 4
*/

/* If you have to find remainder of any number you can use this trick*/
int remainder(string str)
{ 
    int n=str.size();
    int rem=0;
    int num=0;
    for(int i=0;i<n;i++)
    {
        num=rem*10+(str[i]-'0');
        rem=num%11;
    }

    return rem;
    
}

int main()
{
    string str = "3435346456547566345436457867978";
    cout << remainder(str);
    return 0;
}