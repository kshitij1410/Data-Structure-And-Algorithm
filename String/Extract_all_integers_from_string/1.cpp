#include<bits/stdc++.h>
using namespace std;

void extractIntegerWords( string str)
{
 int n=str.length();
 string temp="";
 for(int i=0;i<n;i++)
 {
     if(str[i]>='0' and str[i]<='9') temp+=str[i];
     else{
          if(temp!="")
          {
              cout<<temp<<" ";
              temp="";
          }
     }
 }
  

}

int main()
{
    string str = "1: Prakhar Agrawal, 2: Manish Kumar Rai, 3: Rishabh Gupta";
    extractIntegerWords(str);
    return 0;
}