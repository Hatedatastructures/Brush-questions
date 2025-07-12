#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
//题目：字符串第一个唯一字符
// https://leetcode.cn/problems/first-unique-character-in-a-string/description/
namespace CPP
{
    class Solution 
    {
    public:
        int firstUniqChar(string s) 
        {
            unordered_map<int,int> hash_table;
            for(auto& str : s)
            {
                if(hash_table.find(str) != hash_table.end())
                {
                    hash_table[str]++; 
                    continue;
                }
                hash_table[str] = 1;
            }
            for(int i = 0; i < static_cast<int>(s.size());i++)
            {
                if(hash_table[s[i]] == 1)
                {
                    return i;
                }
            }
            return -1;
        }
    };
}
int main()
{
    string s = "leetcode";
    string s1 = "loveleetcode";
    string s2 = "aabb";
    CPP::Solution solution;
    cout << solution.firstUniqChar(s) << endl;
    cout << solution.firstUniqChar(s1) << endl;
    cout << solution.firstUniqChar(s2) << endl;
    return 0;
}