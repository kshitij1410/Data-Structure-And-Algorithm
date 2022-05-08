vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
{

    if (n == 1)
        return {1};

    long long int left[n], right[n];
    left[0] = nums[0];
    right[n - 1] = nums[n - 1];

    for (int i = 1; i < n; i++)
    {
        left[i] = nums[i] * left[i - 1];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = right[i + 1] * nums[i];
    }

    nums[0] = right[1];
    nums[n - 1] = left[n - 2];

    for (int i = 1; i < n - 1; i++)
    {
        nums[i] = left[i - 1] * right[i + 1];
    }

    return nums;
}
}
;