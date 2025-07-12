#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
//题目：第一个出现两次的字母
// https://leetcode.cn/problems/first-letter-to-appear-twice/
namespace CPP 
{
    class Solution 
    {
    public:
        char repeatedCharacter(string s) 
        {
            unordered_set<char> hash_set;
            for(auto & str : s)
            {
                if(hash_set.find(str) != hash_set.end())
                {
                    return str;
                }
                hash_set.insert(str);
            }
            return s[0];
        }
    };
}
int main()
{
    CPP::Solution solution;
    string s = "abccbaacz";
    cout << solution.repeatedCharacter(s) << endl;
    return 0;
}