// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

// Return the max sliding window.

 

// Example 1:

// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]
// Explanation: 
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7


//Method 1: Naive approach O(k*nums.size())
//method 2: Avl tree or priority queue O(N log k)  and space O(k)
// Method 3: deque Tc- O(n) and sc-O(k) 

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    deque<int> dq;
    vector<int> ans;

    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() and nums[i] >= nums[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    ans.push_back(nums[dq.front()]);

    for (int i = k; i < nums.size(); i++)
    {

        if (!dq.empty() and i - k >= dq.front())
            dq.pop_front();

        while (!dq.empty() and nums[i] >= nums[dq.back()])
            dq.pop_back();

        // push always
        dq.push_back(i);

        ans.push_back(nums[dq.front()]);
    }

    return ans;
}