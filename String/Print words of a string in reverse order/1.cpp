#include <bits/stdc++.h>
using namespace std;

/*

Q1 Let there be a string say “I AM A GEEK”. So, the output should be “GEEK A AM I” . This can done in many ways. One of the solutions is given in Reverse words in a string .

Examples:

Input : I AM A GEEK
Output : GEEK A AM I

Input : GfG IS THE BEST
Output : BEST THE IS GfG

*/

/*  O(len(str))  space -O(n)  */
void wordReverse(string str)
{
  vector<string> ans;
  int n = str.size();
  int len = 0;

  for (int i = n - 1; i >= 0; i--)
  {
    if (str[i] == ' ')
    {
      if (len == 0)
        continue;
      ans.push_back(str.substr(i + 1, len));
      len = 0;
    }
    else
    {

      len++;
    }
  }

  if (str[0] != ' ' or len == 0)
    ans.push_back(str.substr(0, len));

  for (auto ele : ans)
    cout << ele << " ";
}


/*  O(len(str))  space -O(1)   Modify in the same string*/

/*
-->I AM A GEEKS
-->I MA A SKEEG  (REVERSE A WORD)
-->GEEKS A AM I  (REVERSE WHOLE STRING)

*/
void wordReverse1(string &str)
{
  /* suppose ' ' ' ' I AM */
  // move forward all the spaces at starting
  int i = 0;
  int n=str.size();

  while (str[i] == ' ')
    i++;

  int start = i;
  int end = n;

  for (int i = start; i < n; i++)
  {

    if (i + 1 == n or str[i] == ' ')
    {
      /// swapping
      if (i + 1 == n)
        end = i;
      else
        end = i - 1;

      while (start < end)
      {
        swap(str[start], str[end]);
        start++;
        end--;
      }
      start=i+1;
    }


  }

  reverse(str.begin(),str.end());


}

// Drivers code
int main()
{
  string str = "1234567 I AM A GEEKS";
  wordReverse1(str);
  cout<<str;
  return 0;
}