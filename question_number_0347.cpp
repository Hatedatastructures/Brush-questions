#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
//题目：前 K 个高频元素
//https://leetcode.cn/problems/top-k-frequent-elements/description/?envType=problem-list-v2&envId=sorting
namespace CPP
{
    class Solution
    {
        class comparator
        {
        public:
            bool operator()(const pair<int, int> fir, const pair<int, int> sec) const
            {
                return fir.second < sec.second;
            }
        };

    public:
        vector<int> topKFrequent(vector<int> &nums, int k)
        {
            unordered_map<int, int> hash_table;
            for (auto t : nums)
            {
                if (hash_table.find(t) != hash_table.end())
                {
                    hash_table[t]++;
                    continue;
                }
                hash_table.insert({t, 1});
            }
            priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> queue;
            for (auto t : hash_table)
            {
                queue.push(t);
            }
            vector<int> rt;
            for (int i = 0; i < k; i++)
            {
                rt.push_back(queue.top().first);
                queue.pop();
            }
            return rt;
        }
    };
}
int main()
{
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    for (auto t : CPP::Solution().topKFrequent(nums, k))
    {
        cout << t << " ";
    }
    cout << endl;
    return 0;
}