#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
//题目：删除有序数组中的重复项 2
// https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii/
namespace CPP
{
    class Solution
    {
    public:
        int removeDuplicates(vector<int> &nums)
        {
            unordered_map<int, int> hash_table;
            for (int i = 0; i < nums.size(); i++)
            {
                if (hash_table.find(nums[i]) != hash_table.end())
                {
                    if (hash_table[nums[i]] >= 2)
                    {
                        nums.erase(nums.begin() + i);
                        i--;
                        continue;
                    }
                    else
                    {
                        hash_table[nums[i]]++;
                    }
                }
                hash_table.insert({nums[i], 1});
            }
            return nums.size();
        }
    };
}
int main()
{
    CPP::Solution solution;
    vector<int> nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    cout << solution.removeDuplicates(nums) << endl;
    return 0;
}