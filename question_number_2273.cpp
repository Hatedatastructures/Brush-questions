#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;
// 题目：移除字母异位词后的结果数组
// https://leetcode.cn/problems/find-resultant-array-after-removing-anagrams/
namespace CPP
{
    class Solution
    {
    public:
        vector<string> removeAnagrams(vector<string> &words)
        {
            vector<string> res;
            unordered_set<string> hash_table;
            for (auto &str : words)
            {
                string value = str;
                sort(value.begin(), value.end());
                if (hash_table.find(value) == hash_table.end())
                {
                    hash_table.clear();
                    hash_table.insert(value);
                    res.push_back(str);
                }
            }
            return res;
        }
    };
}
int main()
{
    CPP::Solution solution;
    vector<string> words = {"abba", "baba", "bbaa", "cd", "cd"};
    vector<string> res = solution.removeAnagrams(words);
    for (auto &str : res)
    {
        cout << str << endl;
    }
    return 0;
}