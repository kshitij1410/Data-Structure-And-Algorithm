#include <bits/stdc++.h>
using namespace std;

/*

Given string str, the task is to find the minimum number of characters to be inserted to convert it to a palindrome.

Before we go further, let us understand with a few examples:

ab: Number of insertions required is 1 i.e. bab
aa: Number of insertions required is 0 i.e. aa
abcd: Number of insertions required is 3 i.e. dcbabcd
abcda: Number of insertions required is 2 i.e. adcbcda which is the same as the number of insertions in the substring bcd(Why?).
abcde: Number of insertions required is 4 i.e. edcbabcde

*/
//recursion

int findMinInsertionsLCS(string str, int i,int j)
{

    //base case
    if(i==j or i>j)
    return 0;

    if(str[i]==str[j])
    {
        return findMinInsertionsLCS(str,i+1,j-1);
    }
    else{
        int a=1+findMinInsertionsLCS(str,i,j-1);
        int b=1+findMinInsertionsLCS(str,i+1,j);
        return min(a,b);

    }
}



int main()
{
    string str = "abcde";
    int n=str.size();
    cout << findMinInsertionsLCS(str,0,n-1);
    return 0;
}