#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// 题目：存在重复元素2
// https://leetcode.cn/problems/contains-duplicate-ii/?envType=problem-list-v2&envId=hash-table
namespace CPP
{
    class Solution 
    {
    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k) 
        {
            unordered_map<int,int> hash_table;
            for(int i = 0; i < static_cast<int>(nums.size()); i++)
            {
                if(hash_table.find(nums[i]) != hash_table.end() && i - hash_table[nums[i]] <= k )
                {
                    return true;
                }
                hash_table[nums[i]] = i;
            }
            return false;
        }
    };
}
int main()
{
    vector<int> nums = {1,2,3,1,2,3};
    CPP::Solution s;
    cout << s.containsNearbyDuplicate(nums, 2)  << std::endl;
    return 0;
}