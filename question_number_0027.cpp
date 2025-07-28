#include <iostream>
#include <vector>
using namespace std;
// 题目：移除元素
// https://leetcode.cn/problems/remove-element/?envType=problem-list-v2&envId=array
namespace CPP
{
    class Solution
    {
    public:
        int removeElement(vector<int> &nums, int val)
        {
            for (int value = 0; value < nums.size(); value++)
            {
                if (nums[value] == val)
                { // erase函数删除迭代器后面的数据会覆盖删除迭代器的位置
                    nums.erase(nums.begin() + value);
                    value--;
                }
            }
            return nums.size();
        }
    };
}
int main()
{
    CPP::Solution solution;
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;
    cout << solution.removeElement(nums, val) << endl;
    return 0;
}