#include <bits/stdc++.h>
using namespace std;

/*
Q1
Given an encoded string where repetitions of substrings are represented as substring followed by count of substrings. For example, if encrypted string is “ab2cd2” 
and k=4 , so output will be ‘b’ because decrypted string is “ababcdcd” and 4th character is ‘b’.
Note: Frequency of encrypted substring can be of more than one digit. For example, in “ab12c3”, 
ab is repeated 12 times. No leading 0 is present in frequency of substring.
Examples:


Input: "a2b2c3", k = 5
Output: c
Decrypted string is "aabbccc"

Input : "ab4c2ed3", k = 9
Output : c
Decrypted string is "ababababccededed"

Input: "ab4c12ed3", k = 21
Output: e
Decrypted string is "ababababccccccccccccededed"

*/
/* O(N)  */

char encodedChar(string s, int k)
{
    int n = s.size();
    string str = "";
    int sum = 0;
    char ans = 'a';
    string nums = "";
    int ansInd = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (s[i] >= '0' and s[i] <= '9')
        {
            // its number
            nums += s[i];
            int len2 = nums.size();

            /* i+1==n bcz the last digit is always number so we can't implement that further bcz loops its break*/

            if (i + 1 == n or (s[i + 1] >= 'a' and s[i + 1] <= 'z'))
            {
                stringstream ss;
                ss << nums;
                int number;
                ss >> number;
                int len1 = str.size();
                sum += number * len1;

                if (k <= sum)
                {

                    int diff = sum - k;
                    int index = diff % len1; /* index indicate remainder its help to calculate the index of the char*/

                    if (index == 0)
                        index = len1;

                    ansInd = i + index - (len1 + len2); /* this willl help to find the index of required character*/
                    break;
                }

                str = "";
                nums = "";
            }

            if (s[i + 1] >= '0' and s[i + 1] <= '9')
                continue;
        }
        else
        {
            str += s[i];
        }
    }

  /* why i am using this condition bcz the user input no number ,only char theN this case handle it*/
    if (ansInd != INT_MIN)
        return s[ansInd];
    else
    {
        return s[k-1];
    }
}

int main()
{
    string str = "ab4c12ed3";
    int k = 9;
    cout << encodedChar(str, k) << endl;
     str = "abced";
     k = 4;
 
    cout << encodedChar(str, k) << endl;
    return 0;
}