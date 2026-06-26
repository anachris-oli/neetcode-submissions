/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        head = recursion(head,head->next);
    }

    ListNode* recursion(ListNode* root, ListNode* current)
    {
        if(current==nullptr) return root;
        root = recursion(root, current->next);
        if(root==nullptr) return nullptr;

        ListNode* tmp = nullptr;
        if(root==current or root->next==current)
        {
            current->next = nullptr;
        }
        else
        {
            tmp = root->next;
            root->next = current;
            current->next = tmp;
        }
        return tmp;
    }
};
