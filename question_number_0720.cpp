#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
//题目：词典中最长的单词
// https://leetcode.cn/problems/longest-word-in-dictionary/?envType=problem-list-v2&envId=hash-table
namespace CPP
{
    class Solution
    {
        struct comparators
        {
            bool operator()(const string &first, const string &second)
            {
                return first < second;
            }
        };

    public:
        string longestWord(vector<string> &words)
        {
            unordered_set<string> hash_table;
            sort(words.begin(), words.end(), comparators()); // 排序成升序方便后面哈希映射
            string restr = "";
            for (const auto &str : words)
            {
                if (str.size() == 1)
                {
                    // 到这里vector是有序的，因为题目要求逐步添加字符，首先映射的必定是单个字符
                    hash_table.insert(str);
                    if (restr.empty() || str < restr)
                    {
                        restr = str;
                    }
                    continue;
                } // 或者str.substr(0,str.size() - 1)来构建临时的前缀
                if (hash_table.find(string(str.begin(), str.end() - 1)) != hash_table.end())
                {
                    if (restr.size() < str.size() || (restr > str && restr.size() == str.size()))
                    {
                        restr = str;
                    }
                    hash_table.insert(str);
                }
                // 对于其他前缀没有的单词不映射
            }
            return restr;
        }
    };
}
int main()
{
    vector<string> worlds_first  = {"yo","ew","fc","zrc","yodn","fcm","qm","qmo","fcmz","z","ewq","yod","ewqz","y"};
    vector<string> worlds_second = {"a","banana","app","appl","ap","apply","apple"};
    vector<string> world_third   = {"m","mo","moc","moch","mocha","l","la","lat","latt","latte","c","ca","cat"};
    vector<string> worlds_fourth = {"w","wo","wor","worl","world"};
    CPP::Solution s;
    cout << s.longestWord(worlds_first) << endl;
    cout << s.longestWord(worlds_second) << endl;
    cout << s.longestWord(world_third) << endl;
    cout << s.longestWord(worlds_fourth) << endl;
    return 0;
}