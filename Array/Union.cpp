#include <bits/stdc++.h>
using namespace std;

// 1 2 4 8 8 8 9
//  3 6 8 10 13 13 14

//Method 1: SET,MAP 

//Method 2: time O(n) if array is sorted 

void union_(int a[], int b[], int n1, int n2)
{
    // array must be sorted
    sort(a, a + n1);
    sort(b, b + n2);

    int i = 0;
    int j = 0;
    vector<int> ans;

    //two pointer apporach


    while (i < n1 and j < n2)
    {
        if (a[i] == a[i - 1])
        {
            i++;
            continue;
        }
        if (b[j] == b[j - 1])
        {
            j++;
            continue;
        }

        if (a[i] > b[j])
        {
            ans.push_back(b[j]);
            j++;
        }
        else if (a[i] < b[j])
        {
            ans.push_back(a[i]);
            i++;
        }
        else
        {
            ans.push_back(a[i]);
            i++;
            j++;
        }
    }

    //remaining element in b[]

    while (j < n2)
    {
        if (b[j] == b[j - 1])
        {
            j++;
            continue;
        }
        else
        {
            ans.push_back(b[j]);
            j++;
        }
    }
   
   //remaining element in a[]

    while (i < n1)
    {
        if (a[i] == a[i - 1])
        {
            i++;
            continue;
        }
        else
        {
            ans.push_back(a[i]);
            i++;
        }
    }

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}

int main()
{
    int a[] = {1, 2, 4, 8, 8, 8, 9,9 ,14, 15,3211,54};
    int b[] = {3, 6, 8, 10, 13, 13, 14};
    int n1 = sizeof(a) / sizeof(a[0]);
    int n2 = sizeof(b) / sizeof(b[0]);

    union_(a, b, n1, n2);

    return 0;
}