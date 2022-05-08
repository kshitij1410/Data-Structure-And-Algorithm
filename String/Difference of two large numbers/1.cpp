#include <bits/stdc++.h>
using namespace std;

/*

Given two numbers as strings. The numbers may be very large (may not fit in long long int), the task is to find the difference between these two numbers.

Examples:

Input : str1 = "11443333311111111100",
        str2 =     "1144422222221111"
Output : 11442188888888889989

Input :str1 = "122387876566565674",
       str2 =     "31435454654554"
Output : 122356441111911120



*/


/*
logic:---- 

example:    91
           -07
           = 
           if(1<7)
           (1+10)-7=4  1st digit  carry=1;
           2nd digit (9-carry)==(9-1)=8
           if(8>0) 
           8-0=8

           ans 84

   step1: if s1[i] > s2[i] then simply subtract it and append in answer
          else{
              add 10 to s1 and generate carry of 1
              append in result ->  s1[i]+10-s2[i]
              carry=1;
          }  
*/

void findDiff(string s1, string s2)
{
    int n1 = s1.size();
    int n2 = s2.size();
    int diff = n2 - n1;
    string s = "";

    // make length of string are equal
    while (diff--)
    {
        s += "0";
    }
    s1 = s + s1;

    // cout<<"s1"<<s1<<endl;
    // cout<<"s2"<<s2<<endl;

    int *result = new int[n2];
    int carry = 0;
    int k = n2 - 1;
    for (int i = n2 - 1; i >= 0; i--)
    {
        int s2val = (s2[i] - '0') - carry;
        int s1val = (s1[i] - '0');

        if (s2val >= s1val)
        {
            result[k] = s2val - s1val;
            carry = 0;
        }
        else
        {
            s2val = s2val + 10;
            result[k] = s2val - s1val;
            carry = 1;
        }

        k--;
    }

    int flag = 0;
    for (int i = 0; i < n2; i++)
    {
        if (result[i] == 0 and flag == 0)
            continue;
        else
        {
            flag = 1;
            cout << result[i];
        }
    }
}

void isSmaller(string s1, string s2)
{

    int n1 = s1.size();
    int n2 = s2.size();

    if (n1 > n2)
    {
        swap(s1, s2);
    }
    if (n1 == n2)
    {
        if (s1 > s2)
            swap(s1, s2);
    }

    return findDiff(s1, s2);
}

int main()
{
    string str1 = "122387876566565674";
    string str2 = "31435454654554";
    isSmaller(str1, str2);


    return 0;
}