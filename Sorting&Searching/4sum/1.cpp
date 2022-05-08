//TIME-O(N^3)
//Method1: two pointer(N^2) * pair sum(n) 
//if we got duplicate then jump the i,j index 
// we find a unique pair
  

vector<vector<int>> fourSum(vector<int> &arr, int k)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;

    int last_i = -101;
    int last_j = -101;

    for (int i = 0; i < n; i++)
    {
        if (last_i == arr[i])
            continue;
        else
        {

            last_j = -101;
            for (int j = i + 1; j < n; j++)
            {
                if (last_j == arr[j])
                    continue;
                else
                {
                    int target = k - arr[j] - arr[i];

                    int low = j + 1;
                    int high = n - 1;
                    int left = -101;
                    int right = -101;
                    while (low < high)
                    {
                        if (left == arr[low])
                        {
                            low++;
                            continue;
                        }

                        if (right == arr[high])
                        {
                            high--;
                            continue;
                        }

                        int twoSum = arr[low] + arr[high];
                        if (twoSum < target)
                        {

                            left = arr[low];
                            low++;
                        }
                        else if (twoSum > target)
                        {

                            right = arr[high];
                            high--;
                        }
                        else
                        {
                            ans.push_back({arr[i], arr[j], arr[low], arr[high]});
                            left = arr[low];
                            right = arr[high];
                            low++;
                            high--;
                        }

                    } // while loop end
                    last_j = arr[j];
                } // else part end
            }     // j loop end

            last_i = arr[i];
        } // else

    } // i loop end;

    return ans;
}