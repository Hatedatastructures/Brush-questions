#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
//题目：删除有序数组中的重复项
// https://leetcode.cn/problems/remove-duplicates-from-sorted-array/description/?envType=problem-list-v2&envId=array
class Solution 
{
public:
    int removeDuplicates(vector<int>& nums) 
    {
        unordered_set<int> hash_table;
        for(int i = 0; i < nums.size();i++)
        {
            if(hash_table.find(nums[i]) !=  hash_table.end())
            {
                nums.erase(nums.begin() + i);
                i--;
                continue;
            }
            hash_table.insert(nums[i]);
        }
        return nums.size();
    }
};
int main()
{
    Solution solution;
    vector<int> nums = {1,1,2};
    cout << solution.removeDuplicates(nums) << endl;
    return 0;
}