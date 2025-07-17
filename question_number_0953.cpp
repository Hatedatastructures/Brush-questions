#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
//题目：验证外星语词典
// https://leetcode.cn/problems/verifying-an-alien-dictionary/?envType=problem-list-v2&envId=hash-table
namespace CPP
{
    class Solution
    {
    public:
        bool isAlienSorted(vector<string> &words, string order)
        {
            unordered_map<char, int> hash_table;
            int cout_size = 0;
            for (auto &ch : order)
            {
                if (hash_table.find(ch) != hash_table.end())
                {
                    continue;
                }
                hash_table[ch] = cout_size++;
            }
            for (auto &str : words)
            {
                for (auto &ch : str)
                {
                    ch = hash_table[ch] + 'a';
                }
            }
            for (int i = 0; i < static_cast<int>(words.size() - 1); i++)
            {
                if (words[i] > words[i + 1])
                {
                    return false;
                }
            }
            return true;
        }
    };
}
int main()
{
    CPP::Solution solution;
    vector<string> words = {"hello", "leetcode"};
    string order = "hlabcdefgijkmnopqrstuvwxyz";
    cout << solution.isAlienSorted(words, order) << endl;
    return 0;
}