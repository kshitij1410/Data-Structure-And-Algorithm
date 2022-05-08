vector<int> majorityElementII(vector<int> &arr)
{
    int n = arr.size();
    int c1 = 0, c2 = 0;
    int num1 = 0, num2 = 0;

    for (int i = 0; i < n; i++)
    {
        /* 7,4,4,9,7*/
        // last case c1=0 first we have to check or compare last element whith prev element
        if (arr[i] == num1)
            c1++;
        else if (arr[i] == num2)
            c2++;
        else if (c1 == 0)
        {
            num1 = arr[i];
            c1 = 1;
        }
        else if (c2 == 0)
        {
            num2 = arr[i];
            c2++;
        }
        else
        {
            c1--;
            c2--;
        }
    }

    // check if it is majority element or not

    c1 = 0;
    c2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (num1 == arr[i])
            c1++;
        if (num2 == arr[i])
            c2++;
    }

    vector<int> ans;
    if (c1 > (n / 3))
        ans.push_back(num1);
    if (c2 > (n / 3))
        ans.push_back(num2);

    return ans;
}