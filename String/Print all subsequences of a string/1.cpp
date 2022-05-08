#include <bits/stdc++.h>
using namespace std;

void printSubsequence(string input, string output)
{
    if (input.size() == 0)
    {
        cout << output << " ";
        return ;
    }

    int n = input.size();
  
    string temp = input.substr(0, 1);

    // inc
    printSubsequence(input.substr(1), output + temp);

    // exc
    printSubsequence(input.substr(1), output);
    
}

int main()
{

    string output = "";
    string input = "abc";

    printSubsequence(input, output);

    return 0;
}