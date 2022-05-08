#include <bits/stdc++.h>
using namespace std;

/*
Divisibility Rules:------------------------------------


a) of 2 :---- even number
b) of 3 :----- sum of all digit is divisibvle by 3
c) of 4 :----- last 2 digit is divisible by 4
d) of 5 :--- last digit is either 0 or 5
e) of 6 :---- number is divisible by 2 or 3
f) of 7:---
    step1: remove the last digit from number( which is greater than 100 i.e 3 digit number)
    step2: subtract the remaining digit by 2*remove number
    step3: if the number is either 0 or 2 digit multiple of 7
    step4: No then repetate this steps
    or yes then it is divisible by 7

    ex- Is 1073 divisible by 7?

     From the rule stated remove 3 from the number and double it, which becomes 6.
     Remaining number becomes 107, so 107-6 = 101.
     Repeating the process one more time, we have 1 x 2 = 2.
     Remaining number 10 – 2 = 8.
     As 8 is not divisible by 7, hence the number 1073 is not divisible by 7.

g) of 8: -- last three digit is divisible by 8
h) of 9 :--- similarily as 3
i) of 10 : -- last digit is 0
j) of 11: ----
        If the number of digits of a number is even, then add the first digit and subtract the last digit from the rest of the number.
        Example: 3784
        Number of digits = 4
        Now, 78 + 3 – 4 = 77 = 7 × 11
        Thus, 3784 is divisible by 11.


      If the number of digits of a number is odd, then subtract the first and the last digits from the rest of the number.
      Example: 82907
      Number of digits = 5
      Now, 290 – 8 – 7 = 275
      =7-2-5=0
      Thus, 82907 is divisible by 11.


k) of 12: --- divisible by 3 or 4

l) of 13: little bit similar to the 7

    For any given number, to check if it is divisible by 13, we have to add four times of the last digit of the number to the remaining number
    and repeat the process until you get a two-digit number.  Now check if that two-digit number is divisible by 13 or not. If it is divisible,
    then the given number is divisible by 13.

    For example: 2795 → 279 + (5 x 4)
    → 279 + (20)
    → 299
    → 29 + (9 x 4)
    → 29 + 36
    →65
    Number 65 is divisible by 13, 13 x 5 = 65.



*/

/*
Q1
You are given an n-digit large number, you have to check whether it is divisible by 999 without dividing or finding modulo of number by 999.
Examples:


Input : 235764
Output : Yes

Input : 23576
Output : No


*/

// idea is make a group of three digits and add them untill we 3 digit number
//  and check it is divisible by 999 or not

bool isDivisible999(string str)
{
   int n=str.size();
   //base case
   if(n==1 and str[0]=='0') return true;

   if(n%3==1)
   {
       str="00"+str;
   }
   if(n%3==2)
   {
       str="0"+str;
   }
   int gtotal=0;
   for(int i=0;i<n;i++)
   {
       int gnum=0;
       gnum+=(str[i++]-'0')*100;
       gnum+=(str[i++]-'0')*10;
       gnum+=(str[i]-'0');

       gtotal+=gnum;
   }

   if(gtotal>1000)
   {
       string temp=to_string(gtotal);
       isDivisible999(temp);
   }
   else{
       if(gtotal==999) return true;
       else return false;
   }

}
int main()
{
    string num = "1998";
    int n = num.length();
    if (isDivisible999(num))
        cout << "Divisible";
    else
        cout << "Not divisible";
    return 0;
}