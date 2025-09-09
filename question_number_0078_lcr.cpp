#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//题目：合并K个升序链表
//https://leetcode.cn/problems/vvXgSW/description/

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
        ListNode *mergeKLists(vector<ListNode *> &lists)
        {
            ListNode *ret = new ListNode();
            ListNode *node = ret;
            ret->next = node;
            priority_queue<ListNode *, vector<ListNode *>, comparer> queue;
            for (auto list : lists)
            {
                while (list)
                {
                    queue.push(list);
                    list = list->next;
                }
            }
            while (!queue.empty())
            {
                node->next = queue.top();
                node = node->next;
                node->next = nullptr;
                queue.pop();
            }
            node->next = nullptr; // 防止越界
            return ret->next;
        }
    };
}
int main()
{
    // [[1,4,5],[1,3,4],[2,6]]
    CPP::ListNode *node1 = new CPP::ListNode(1);
    CPP::ListNode *node2 = new CPP::ListNode(4);
    CPP::ListNode *node3 = new CPP::ListNode(5);
    node1->next = node2;
    node2->next = node3;

    CPP::ListNode *node4 = new CPP::ListNode(1);
    CPP::ListNode *node5 = new CPP::ListNode(3);
    CPP::ListNode *node6 = new CPP::ListNode(4);
    node4->next = node5;
    node5->next = node6;

    CPP::ListNode *node7 = new CPP::ListNode(2);
    CPP::ListNode *node8 = new CPP::ListNode(6);
    node7->next = node8;

    vector<CPP::ListNode *> lists;
    lists.push_back(node1);
    lists.push_back(node4);
    lists.push_back(node7);

    CPP::Solution solution;
    auto result = solution.mergeKLists(lists);
    while (result)
    {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
    return 0;
}