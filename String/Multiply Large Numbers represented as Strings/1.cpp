#include <bits/stdc++.h>
using namespace std;

/*

Given two positive numbers as strings. The numbers may be very large (may not fit in long long int), the task is to find product of these two numbers.
Examples:

Input : num1 = 4154
        num2 = 51454
Output : 213739916

Input :  num1 = 654154154151454545415415454
         num2 = 63516561563156316545145146514654
Output : 41549622603955309777243716069997997007620439937711509062916

*/

void multiply(string s1, string s2)
{
    int n1 = s1.size();
    int n2 = s2.size();

    int *result = new int[n1 + n2];

    for (int i = 0; i < n1 + n2; i++)
        result[i] = 0;

    int power = 0;
    int k, carry, product, ival, jval;

    for (int i = n1 - 1; i >= 0; i--)
    {
        k = n1 + n2 - power - 1;
        carry = 0;
        ival = (s1[i] - '0');

        for (int j = n2 - 1; j >= 0; j--)
        {
            jval = (s2[j] - '0');
            product = ival * jval + carry + result[k];
            result[k] = product % 10;
            carry = product / 10;

            //
            if (j == 0)
            {
                if (carry != 0)
                {
                    result[--k] = carry;
                }
            }
            k--;
        }

        power++;
    }

    int flag = 0;
    for (int i = 0; i < n1 + n2; i++)
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

int main()
{
    string num1 = "4154";
    string num2 = "51454";

    multiply(num1, num2);

    return 0;
}