#include <iostream>
#include <stack>

using namespace std;
// 题目：回文链表
// https://leetcode.cn/problems/palindrome-linked-list/
namespace CPP
{
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    class Solution
    {
    public:
        bool isPalindrome(ListNode *head)
        {
            ListNode *node = head;
            stack<int> stack;
            while (node)
            {
                stack.push(node->val);
                node = node->next;
            }
            node = head;
            while (head && head->val == stack.top())
            {
                head = head->next;
                stack.pop();
            }
            if (stack.size() > 0)
                return false;
            return true;
        }
    };
}
int main()
{
    // [1,2,2,1]
    CPP::ListNode *node1 = new CPP::ListNode(1);
    CPP::ListNode *node2 = new CPP::ListNode(2);
    CPP::ListNode *node3 = new CPP::ListNode(2);
    CPP::ListNode *node4 = new CPP::ListNode(1);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    CPP::Solution solution;
    cout << solution.isPalindrome(node1) << endl;
    return 0;
}