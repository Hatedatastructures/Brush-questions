#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 题目：排序链表
// https://leetcode.cn/problems/sort-list/description/
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
        struct comparer
        {
            bool operator()(const ListNode *first, const ListNode *second)
            {
                return first->val > second->val;
            }
        };

    public:
        ListNode *sortList(ListNode *head)
        {
            ListNode *ret = new ListNode();
            ListNode *current_head = ret;
            if (head == nullptr)
            {
                return nullptr;
            }
            priority_queue<ListNode *, vector<ListNode *>, comparer> queue;
            while (head != nullptr)
            {
                queue.push(head);
                head = head->next;
            }
            while (!queue.empty())
            {
                ret->next = queue.top();
                ret = ret->next;
                ret->next = nullptr;
                queue.pop();
            }
            return current_head->next;
        }
    };
}
int main()
{
    // [4,2,1,3]
    CPP::ListNode *node1 = new CPP::ListNode(4);
    CPP::ListNode *node2 = new CPP::ListNode(2);
    CPP::ListNode *node3 = new CPP::ListNode(1);
    CPP::ListNode *node4 = new CPP::ListNode(3);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    CPP::Solution solution;
    auto ret = solution.sortList(node1);
    while (ret != nullptr)
    {
        std::cout << ret->val << std::endl;
        ret = ret->next;
    }
    return 0;
}