#include <bits/stdc++.h>
using namespace std;

/*
Q1
Given a number n, find the smallest number that has same set of digits as n and is greater than n. If n is the
greatest possible number with its set of digits, then print “not possible”.

Examples:
For simplicity of implementation, we have considered input number as a string.
Input:  n = "218765"
Output: "251678"

Input:  n = "1234"
Output: "1243"

Input: n = "4321"
Output: "Not Possible"

Input: n = "534976"
Output: "536479"
*/

string nextPermutation(int n, string nums)
{
    // base case:-
    if (nums.size() <= 1)
        return nums;
    
   

    string temp = nums;

    // step1: next permutation:-

    // find break point where curve start decreasing
    int i = n - 2;
    while (nums[i] >= nums[i + 1] and i >= 0)
        i--;

    if (i >= 0)
    {
        // find the strictly greater number than break point
        int j = n - 1;
        while (nums[i] >= nums[j])
            j--;

        // swap the both point
        swap(nums[i], nums[j]);
    }
    reverse(nums.begin() + i + 1, nums.end());
    return nums;
}

int main()
{
    int n = 6;
    string s="534976";
    string res;
    res = nextPermutation(n, s);
    cout<<res;
    return 0;
}
