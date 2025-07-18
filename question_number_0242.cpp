#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
// 题目：有效的字母异位词
//  https://leetcode.cn/problems/valid-anagram/description/?envType=problem-list-v2&envId=hash-table
namespace CPP
{
    class Solution
    {
    public:
        bool isAnagram(string s, string t)
        {
            unordered_map<char, int> hash_table_s;
            unordered_map<char, int> hash_table_t;
            if (s.size() != t.size())
            {
                return false;
            }
            for (const auto &ch : s)
            {
                if (hash_table_s.find(ch) != hash_table_s.end())
                {
                    hash_table_s[ch]++;
                    continue;
                }
                hash_table_s[ch] = 1;
            }
            for (const auto &ch : t)
            {
                if (hash_table_t.find(ch) != hash_table_t.end())
                {
                    hash_table_t[ch]++;
                    continue;
                }
                hash_table_t[ch] = 1;
            }
            for (const auto &ch : s)
            {
                if (hash_table_s.find(ch) != hash_table_s.end() && hash_table_t.find(ch) != hash_table_t.end())
                {
                    if (hash_table_s[ch] != hash_table_t[ch])
                    {
                        return false;
                    }
                    continue;
                }
                return false;
            }
            return true;
        }
    };
    class Solution_second
    {
    public:
        bool isAnagram(string s, string t)
        {
            sort(s.begin(), s.end());
            sort(t.begin(), t.end());
            return s == t;
        }
    };
}
int main()
{
    CPP::Solution solution;
    pair<string, string> test_data_first = {"anagram", "nagaram"};
    pair<string, string> test_data_second = {"rat", "car"};
    pair<string, string> test_data_third = {"aacc", "ccac"};
    cout << solution.isAnagram(test_data_first.first, test_data_first.second) << endl;
    cout << solution.isAnagram(test_data_second.first, test_data_second.second) << endl;
    cout << solution.isAnagram(test_data_third.first, test_data_third.second) << endl;
    return 0;
}