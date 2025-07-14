#include <iostream>
#include <unordered_set>
using namespace std;
//题目：环形链表 II
// https://leetcode.cn/problems/linked-list-cycle-ii/?envType=problem-list-v2&envId=hash-table
namespace CPP
{
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    class Solution
    {
    public:
        ListNode *detectCycle(ListNode *head)
        {
            unordered_set<ListNode *> hash_table;
            while (head)
            {
                if (hash_table.find(head) != hash_table.end())
                {
                    return head;
                }
                hash_table.insert(head);
                head = head->next;
            }
            return nullptr;
        }
    };
}
int main()
{
    CPP::Solution solution; //[3,2,0,-4]
    CPP::ListNode *head = new CPP::ListNode(3);
    head->next = new CPP::ListNode(2);
    head->next->next = new CPP::ListNode(0);
    head->next->next->next = new CPP::ListNode(-4);
    head->next->next->next->next = head->next;
    cout << solution.detectCycle(head)->val << endl;
    return 0;
}